#include <stdlib.h>

struct _queue {
	int *arr;
	int elems, front, end;
};

typedef struct _queue queue;

queue* createQueue(unsigned int elems) {
	queue* newQueue = (queue*) malloc(sizeof(queue));
	newQueue->arr = (int*) malloc(elems*sizeof(int));
	newQueue->elems = elems;
	newQueue->front = 0;
	newQueue->end = 0;

	return newQueue;
}

void deleteQueue(queue *q) {
	free(q->arr);
	free(q);
}

int isEmpty(queue* q) {
	return q->front == q->end || q->end == 0;
}

int isFull(queue *q) {
	return q->end == q->elems;
}

void enqueue(queue *q, int val) {
	if(isFull(q))
		return;
	
	q->arr[q->end] = val;
	q->end++;
}

int dequeue(queue *q) {
	if(isEmpty(q))
		return -1;

	return q->arr[q->front++];
}
