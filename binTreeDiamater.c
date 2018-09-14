#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *l;
	struct Node *r;
	int data;
};

typedef struct Node Node_t;

Node_t *newNode(int data) {
	Node_t *node = malloc(sizeof(Node_t));
	node->data = data;
	node->l = NULL;
	node->r = NULL;
	return node;
}

int max(int a, int b) { return (a > b ? a : b); }

int height(Node_t *root, int *ans) {
	if(root == NULL)
		return 0;
	int l_height = height(root->l, ans);
	int r_height = height(root->r, ans);

	*ans = max(*ans, 1 + l_height + r_height);
	return 1 + max(l_height, r_height);
}

int diamater(Node_t *root) {
	if(root == NULL) return 0;
	int ans = 0;
	height(root, &ans);
	return ans;
}

int main() {
	Node_t *root = newNode(1);
	root->l = newNode(2);
	root->r = newNode(3);
	root->l->l = newNode(4);
	root->l->r = newNode(5);

	printf("Diameter is %d\n", diamater(root));
	return 0;
}
