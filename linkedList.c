#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node* next;
	int data;
};

struct node* addNode(struct node* curr, int nextData)
{
	struct node* next = (struct node*) malloc(sizeof(struct node));
	next->data = nextData;
	curr->next = next;
	next->next = NULL;
	return next;
}

void deleteNode(struct node* curr)
{

}

int main()
{
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head->data = 10;
	end = addNode(head, 10);
}
