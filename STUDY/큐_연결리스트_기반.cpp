#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
}Node;

typedef struct _1Queue {
	Node *front, *rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int QisEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif

#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *pq) {
	pq->front = NULL; pq->rear = NULL;
}

int QisEmpty(Queue *pq) {
	// 큐가 아무것도 가리키도 있지 않을 경우
	if (pq->front == NULL) return TRUE; 
	else return FALSE;
}

void Enqueue(Queue *pq, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL; newNode->data = data;
	if (QisEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue *pq) {
	Node *delNode;
	Data retData;

	if (QisEmpty(pq)) {
		printf("Queue Memory Error!\n"); exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}

Data QPeek(Queue *pq) {
	if (QisEmpty(pq)) {
		printf("Queue Memory Error!\n"); exit(-1);
	}
	return pq->front->data;
}

int main(void) {
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QisEmpty(&q))
		printf("%d ", Dequeue(&q));
	printf("\n");
	return 0;
}