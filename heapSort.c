#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct MaxHeap
{
	int size;
	int* array;
};

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(struct MaxHeap* maxHeap, int idx)
{
	int largest = idx;
	int left = (idx * 2) + 1;
	int right = (idx + 1) * 2;

	if(left < maxHeap->size && 
			maxHeap->array[left] > maxHeap->array[largest])	
		largest = left;

	if(right < maxHeap->size && 
			maxHeap->array[right] > maxHeap->array[largest])
		largest = right;

	if(largest != idx)
	{
		swap(maxHeap->array + idx, maxHeap->array + largest);
		heapify(maxHeap, largest);
	}
}

struct MaxHeap* createHeap(int *array, int size)
{
	struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
	maxHeap->array = array;
	maxHeap->size = size;

	for(int i = (maxHeap->size - 2) / 2; i >= 0; i--)
		heapify(maxHeap, i);

	return maxHeap;
}

void heapSort(int* array, int size)
{
	struct MaxHeap* maxHeap = createHeap(array, size);
	while(maxHeap->size > 1)
	{
		swap(maxHeap->array, maxHeap->array + maxHeap->size - 1);
		--maxHeap->size;
		heapify(maxHeap, 0);
	}
	free(maxHeap);
}

int main()
{
	srand(time(NULL));
	int size, *arr, i;
	scanf("%d", &size);
	arr = (int*) malloc(size * sizeof(int));

	for(i = 0; i < size; i++)
		*(arr + i) = rand() % size;
	
	heapSort(arr, size);
	
	for(i = 0; i < size; i++)
		printf("%d\n", *(arr + i));
	
	free(arr);
	return 0;
}
