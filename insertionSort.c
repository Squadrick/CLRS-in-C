#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int num, i, j, key, *ptr;
	srand(time(NULL));
	printf("Enter number of elements: ");
	scanf("%d", &num);
	ptr = (int*) malloc(num * sizeof(int));

	for(i = 0; i < num; i++) 
		*(ptr+i) = rand();

	for(j = 1; j < num; j++)
	{
		key = *(ptr + j);
		i = j - 1;
		while(i >= 0 && *(ptr+i) < key)
		{
			*(ptr+i+1) = *(ptr+i);
			i--;
		}
		*(ptr+i+1) = key;
	}
	
	for(i = 0; i < num; i++)	
		printf("%d\n", *(ptr+i));
	
	free(ptr);
	return 0;
}
