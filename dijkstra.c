#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int minKey(int key[], int mstSet[], int l) {
	int min = 99999;
	int idx;
	for(int i = 0; i < l; i++)
		if(mstSet[i] == 0 && key[i] <= min) {
			min = key[i];
			idx = i;
		}
	return idx;
}

void dijkstra(Graph_t* g, int src) {
	int key[g->totalVertices];

	int mstSet[g->totalVertices];

	for(int i = 0; i < g->totalVertices; i++) {
		key[i] = 9999;
		mstSet[i] = 0;
	}

	key[src] = 0;

	for(int count = 0; count < g->totalVertices; count++) {
		int u = minKey(key, mstSet, g->totalVertices);
		mstSet[u] = 1;

		AdjListNode_t *iter = g->adjListArr[u].head;

		while(iter != NULL) {
			if(mstSet[iter->vertex] == 0 && iter->edgeWeight + key[u]< key[iter->vertex]){
				key[iter->vertex] = iter->edgeWeight + key[u];
			}
			iter = iter->next;
		}
	}

	for(int i = 1; i < g->totalVertices; i++)
		printf("%d - %d\n", i, key[i]);
}

int main() {
	Graph_t *g = createGraph(9, UNDIRECTED);

	addEdge(g, 0, 1, 4);
	addEdge(g, 0, 7, 8);
	addEdge(g, 1, 2, 8);
	addEdge(g, 1, 7, 11);
	addEdge(g, 2, 3, 7);
	addEdge(g, 2, 5, 4);
	addEdge(g, 2, 8, 2);
	addEdge(g, 3, 4, 9);
	addEdge(g, 3, 5, 14);
	addEdge(g, 4, 5, 10);
	addEdge(g, 5, 6, 2);
	addEdge(g, 6, 7, 1);
	addEdge(g, 6, 8, 6);
	addEdge(g, 7, 8, 7);

	displayGraph(g);
	dijkstra(g, 0);
}
