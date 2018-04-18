#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int** warshall(int **mat, int vertices) {
	int ***space = (int***)malloc((vertices+1)*sizeof(int**));
	space[0] = mat;

	for(int k = 1; k <= vertices; k++) {
		space[k] = (int**) malloc(vertices*sizeof(int*));
		for(int i = 0; i < vertices; i++) {
			space[k][i] = (int*) malloc(vertices*sizeof(int));
			for(int j = 0; j < vertices; j++){
				space[k][i][j] = 0;
			}
		}
	}
	
	printf("Space alloc'd\n");
	for(int k = 1; k <= vertices; k++) {
		for(int i = 0; i < vertices; i++) {
			for(int j = 0; j < vertices; j++){
				space[k][i][j] = space[k-1][i][j] || (space[k-1][i][k-1] && space[k-1][k-1][j]);
			}
		}
	}
	
	int **m = space[vertices];
	for(unsigned int i = 0; i < vertices; i++) {
		for(unsigned int j = 0; j < vertices; j++) {
			printf("%d\t", m[i][j]);
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
