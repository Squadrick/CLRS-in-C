#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int** warshall(int **mat, int vertices) {
	for(int k = 0; k < vertices; k++) {
		for(int i = 0; i < vertices; i++) {
			for(int j = 0; j < vertices; j++) {
				mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
			}
		}
	}

	for(unsigned int i = 0; i < vertices; i++) {
		for(unsigned int j = 0; j < vertices; j++) {
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	Graph_t *g = createGraph(4, DIRECTED);

	addEdge(g, 0, 1, 1);
	addEdge(g, 1, 3, 1);
	addEdge(g, 3, 0, 1);
	addEdge(g, 3, 2, 1);
	displayGraph(g);

	int **mat = getBooleanMatrix(g);

	warshall(mat, g->totalVertices);
}
