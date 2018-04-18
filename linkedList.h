#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>
#include <stdio.h>

struct _node
{
	struct _node *next;
	int data;
};

typedef struct _node node;

void display(node *head)
{
	while(head!=NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

node* newNode(int n)
{
	node* temp = (node*) malloc(sizeof(node));
	temp->data = n;
	temp->next = NULL;
	return temp;
}

void insert(node **head, int data)
{
	node *temp = newNode(data);
	while(*head != NULL) 
		head = &(*head)->next;
	*head = temp;
}

void delete(node **head, int data)
{
	while(*head && (*head)->data != data)
		head = &(*head)->next;
	if(!*head) return;
	*head = (*head)->next;
}

void deleteNode(node **head, node *ele)
{
	while(*head != ele)
		head = &(*head)->next;
	*head = (*head)->next;
}

void deleteRepeated(node **head)
{
	while((*head)->next != NULL)
	{
		if((*head)->data == (*head)->next->data)	
			deleteNode(head, *head);
		else
			head = &(*head)->next;
	}
}

int midNode(node *head)
{
	node* fast = head;
	node* slow = head;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}

void reverse(node **head)
{
	node *prev = NULL;
	node *curr = *head;
	node *next;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

node* randomInit(int size, int start)
{
	node* head = NULL;
	for(int i = 0; i < size; i++)
		insert(&head, start+i);
	return head;
}
#endif
