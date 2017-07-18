#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	srand(time(NULL));
	int num, *ptr, i, j, min, index;
	
	printf("Enter number of elements: ");
	scanf("%d", &num);

	ptr = (int* ) malloc(num * sizeof(int));
	for(i = 0; i < num; i++)
		*(ptr + i) = rand();
	
	for(i = 0; i < num - 1; i++)
	{
		index = i;
		min = *(ptr + index);
		for(j = i+1; j < num; j++)
		{
			if(*(ptr + j) < min)
			{
				min = *(ptr + j);
				index = j;
			}
		}
		if(index == i) continue;
		swap(ptr+index, ptr+i);
	}
	for(i = 0; i < num; i++)
		printf("%d\n", *(ptr+i));

	free(ptr);
}
