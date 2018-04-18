#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "queue.h"


void bfs(Graph_t *g, unsigned int src) {
	int *visited = (int*) malloc(g->totalVertices*sizeof(int));
	for(unsigned int i = 0; i < g->totalVertices; visited[i++] = 0);
	queue* q = createQueue(g->totalVertices);
	
	visited[src] = 1;
	enqueue(q, src);

	while(!isEmpty(q)) {
		int curr = dequeue(q);
		printf("%d\n", curr);
		
		AdjListNode_t *iter = g->adjListArr[curr].head;
		while(iter != NULL) {
			if(visited[iter->vertex] == 0) {
				visited[iter->vertex] = 1;
				enqueue(q, iter->vertex);
			}
			iter = iter->next;
		}
	}
	free(q);
}

int main() {
	Graph_t *g = createGraph(10, UNDIRECTED);

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
	bfs(g, 5);
}
