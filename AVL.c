#include <stdlib.h>
#include <stdio.h>

struct _node {
	struct _node *left, *right;
	int val, cost;
};

typedef struct _node node;

node* createNode(int val) {
	node* newNode = (node*) malloc(sizeof(node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = val;
	newNode->cost = 1;

	return newNode;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int height(node *p) {
	if(p == NULL) return 0;
	return p->cost;
}

int getUpdatedCost(node *p) {
	return max(height(p->left), height(p->right)) + 1;
}

int getBalance(node* n) {
	return height(n->left) - height(n->right);
}

node* rightRotate(node* subRoot) {
	node* l = subRoot->left;
	node* lr = l->right;
	
	l->right = subRoot;
	subRoot->left = lr;

	subRoot->cost = getUpdatedCost(subRoot);
	l->cost = getUpdatedCost(l);

	return l;
}

node* leftRotate(node* subRoot) {
	node* r = subRoot->right;
	node* rl = r->left;

	r->left = subRoot;
	subRoot->right = rl;

	subRoot->cost = getUpdatedCost(subRoot);
	r->cost = getUpdatedCost(r);

	return r;
}

node* insert(node* root, int key) {
	if(root == NULL) {
		return createNode(key);
	}
	if(key < root->val)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	
	root->cost = getUpdatedCost(root);
	int balance = getBalance(root);

	if(balance > 1 && key < root->left->val)
		return rightRotate(root);

	if(balance < -1 && key > root->right->val)
		return leftRotate(root);

	if(balance > 1 && key > root->left->val) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(balance < -1 && key < root->right->val) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void preorder(node* root) {
	if(root != NULL) {
		printf("%d\n", root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	node* root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 25);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 75);

	preorder(root);
}
