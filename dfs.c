#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

void _dfs(Graph_t *g, int src, int *visited) {
	if(visited[src] == 1)
		return;

	visited[src] = 1;

	AdjListNode_t *iter = g->adjListArr[src].head;
	printf("%d\n", src);

	while(iter != NULL) {
		_dfs(g, iter->vertex, visited);
		iter = iter->next;
	}
}


void dfs(Graph_t *g) {
	int *visited = (int*)malloc(g->totalVertices*sizeof(int));

	for(unsigned int i = 0; i < g->totalVertices; visited[i++] = 0);
	
	for(unsigned int i = 0; i < g->totalVertices; i++) {
		_dfs(g, i, visited);
	}
	free(visited);
}

int main() {
	Graph_t *g = createGraph(10, DIRECTED);

	addEdge(g, 0, 1, 1);
	addEdge(g, 0, 2, 1);
	addEdge(g, 0, 3, 1);

	addEdge(g, 1, 2, 1);
	addEdge(g, 1, 4, 1);
	addEdge(g, 1, 5, 1);

	addEdge(g, 2, 4, 1);
	addEdge(g, 3, 5, 1);
	addEdge(g, 4, 5, 1);
	
	displayGraph(g);
	dfs(g);
}
