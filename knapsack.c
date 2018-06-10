#include <stdio.h>
#include <stdlib.h>

void _knapsack(int mat[][], int *w, int *v, int i, int j) {
	if(mat[])
}

void knapsack(int *w, int *v, int cap, int items) {
	int mat[items][cap];
	
	for(int i = 0; i < items; i++)
		for(int j = 0; j < cap; j++)
			mat[i][j] = -1;

	int value = _knapsack(mat, w, v, cap, items);
}

int main() {
	int cap = 5;
	int items = 4;

	int values[items] = {12, 10, 20, 15};
	int weight[items] = {2, 1, 3, 2};

}
