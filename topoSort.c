#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct _node {
	struct _node *next;
	int vertex;
};

typedef struct _node node;

node* createNode(int vertex) {
	node* newNode = (node*) malloc(sizeof(node));
	newNode->next = NULL;
	newNode->vertex = vertex;
	return newNode;
}

void _dfs(Graph_t *g, int src, int *visited, node** head) {
	if(visited[src] == 1) return;

	visited[src] = 1;
	AdjListNode_t *iter = g->adjListArr[src].head;

	while(iter != NULL) {
		_dfs(g, iter->vertex, visited, head);
		iter = iter->next;
	}
	
	node* newNode = createNode(src);
	newNode->next = *head;
	*head = newNode;
}


void topo(Graph_t *g) {
	node *ot = createNode(-1); 
	node **head = &ot;
	int *visited = (int*)malloc(g->totalVertices*sizeof(int));

	for(unsigned int i = 0; i < g->totalVertices; visited[i++] = 0);
	
	for(unsigned int i = 0; i < g->totalVertices; i++) 
		_dfs(g, i, visited, head);
	
	ot = *head;
	while(ot->vertex != -1) {
		printf("%d\n", ot->vertex);
		ot = ot->next;
	}
	free(visited);
}


int main() {
	Graph_t *g = createGraph(6, DIRECTED);

	addEdge(g, 0, 1, 1);
	addEdge(g, 0, 2, 1);
	addEdge(g, 0, 3, 1);
	addEdge(g, 1, 2, 1);
	addEdge(g, 1, 5, 1);
	addEdge(g, 5, 4, 1);
	addEdge(g, 2, 4, 1);
	
	displayGraph(g);
	
	topo(g);
}
