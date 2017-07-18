#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *ptr, int start, int mid, int end)
{
	int size, i, j, k, *ptr_new;
	size = end - start + 1;
	i = 0;
	j = start;
	k = mid;
	ptr_new = (int*) malloc(size * sizeof(int));

	while(j < mid && k <= end)
	{
		if(*(ptr + j) < *(ptr + k))
			*(ptr_new + i++) = *(ptr + j++);
		else
			*(ptr_new + i++) = *(ptr + k++);
	}
	
	while(k <= end) 
		*(ptr_new + i++) = *(ptr + k++);

	while(j < mid) 
		*(ptr_new + i++) = *(ptr + j++);

	for(int i = 0; i < size; i++) 
		*(ptr+start+i) = *(ptr_new+i);
	
	free(ptr_new);
}

void sort(int *ptr, int start, int end)
{
	if(start >= end) return;
	int mid = (start + end) / 2;
	sort(ptr, start, mid);
	sort(ptr, mid + 1, end);
	merge(ptr, start, mid + 1, end);
}

int main()
{
	srand(time(NULL));
	int num, *ptr, i;
	printf("Enter the number of elements: ");
	scanf("%d", &num);
	ptr = (int*) malloc(num * sizeof(int));

	for(i = 0; i < num; i++) 
		*(ptr + i) = rand() % 16;

	sort(ptr, 0, num - 1);
	
	for(int i = 0; i < num - 1; i++)
		if(*(ptr+i) > *(ptr+i+1))
			printf("fail\n");

	free(ptr);
}
