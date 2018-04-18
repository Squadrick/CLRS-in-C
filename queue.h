#include <stdlib.h>

struct _queue {
	int *arr;
	int elems, front;
};

typedef struct _queue queue;

queue* createQueue(unsigned int elems) {
	queue* newQueue = (queue*) malloc(sizeof(queue));
	newQueue->arr = (int*) malloc(elems*sizeof(int));
	newQueue->elems = elems;
	newQueue->front = 0;

	return newQueue;
}

int isEmpty(queue* q) {
	return q->front == 0;
}

int isFull(queue *q) {
	return q->front == q->elems;
}

void enqueue(queue *q, int val) {
	if(isFull(q))
		return;

	q->arr[q->front] = val;
	q->front++;
}

int dequeue(queue *q) {
	if(isEmpty(q))
		return -1;

	return q->arr[--(q->front)];
}
