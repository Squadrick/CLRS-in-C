#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data, struct node* leftChild, struct node* rightChild)
{
	struct node* currNode = (struct node*) malloc(sizeof(struct node));
	currNode->data = data;
	currNode->left = leftChild;
	currNode->right = rightChild;
	return currNode;
}

void addRightChild(struct node* root, int data)
{
	if(root->right == NULL)
	{
		struct node* rightChild = newNode(data, NULL, NULL);
		root->right = rightChild;
	}
	else
	{
		printf("Cannot add right child. Occupied!\n");
		addRightChild(root->right, data);
	}
}

void addLeftChild(struct node* root, int data)
{
	if(root->left == NULL)
	{
		struct node* leftChild = newNode(data, NULL, NULL);
		root->left = leftChild;
	}
	else
	{
		printf("Cannot add left child. Occupied!\n");
		addLeftChild(root->left, data);
	}
}

void traverse(struct node* root)
{
	if(root == NULL) return;
	traverse(root->left);
	printf("%d\n", root->data);
	traverse(root->right);
}

void recursiveFree(struct node* root)
{
	if(root == NULL) return;
	recursiveFree(root->left);
	recursiveFree(root->right);
	free(root);
}

int main()
{
	struct node* root = newNode(1, NULL, NULL);

	addLeftChild(root, 2);
	addRightChild(root, 3);

	addLeftChild(root->left, 4);
	addRightChild(root->left, 5);

	addLeftChild(root->right, 6);
	addRightChild(root->right, 7);
	
	addRightChild(root, 8);
	traverse(root);
	recursiveFree(root);
}
