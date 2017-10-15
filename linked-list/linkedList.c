#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
	node *h = randomInit(10, 0);
	reverse(&h);
	display(h);
}
