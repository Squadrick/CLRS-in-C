#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int * i, int * j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int partition(int *arr, int start, int end)
{
	int pivot = *(arr + end);
	int i = start;
	for(int j = start; j < end; j++)
	{
		if(*(arr + j) <= pivot)
		{
			swap(arr+i, arr+j);
			i++;
		}
	}
	swap(arr+i, arr+end);
	return i;
}

void sort(int *arr, int start, int end)
{
	if(start >= end) return;
	int pivot = partition(arr, start, end);
	sort(arr, start, pivot - 1);
	sort(arr, pivot + 1, end);
}

int main()
{
	srand(time(NULL));
	int size, i, *arr;
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	arr = (int*) malloc(size * sizeof(int));
	
	for(int i = 0; i < size; i++)
		*(arr + i) = rand() % size;
	
	sort(arr, 0, size-1);

	free(arr);
}
