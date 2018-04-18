#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int min(int a, int b) {
	return a < b ? a : b;
}

int** floyd(int **mat, int vertices) {
	for(int k = 0; k < vertices; k++) {
		for(int i = 0; i < vertices; i++) {
			for(int j = 0; j < vertices; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
			}
		}
	}

	for(int i = 0; i < vertices; i++) {
		for(int j = 0; j < vertices; j++) {
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	Graph_t *g = createGraph(4, DIRECTED);

	addEdge(g, 0, 2, 3);
	addEdge(g, 2, 3, 1);
	addEdge(g, 3, 0, 6);
	addEdge(g, 2, 1, 7);
	addEdge(g, 1, 0, 2);
	displayGraph(g);
	
	int **mat = getAdjMatrix(g);
	floyd(mat, g->totalVertices);
}
