#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
	int front, rear;
	Data queArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq);
int QisEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);
#endif

#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *pq) {
	pq->front = 0; pq->rear = 0;
}

int QisEmpty(Queue *pq) {
	if (pq->front == pq->rear) return TRUE;
	else return FALSE;
}

int NextPosIdx(int pos) { // 큐의 다음 위치에 해당하는 인덱스 값 반환
	if (pos == QUE_LEN - 1) return 0;	// 큐의 끝이므로 회전을 돕는다.
	else return pos + 1;	// 아닐경우 다음 큐를 가리키도록
}

void Enqueue(Queue *pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {
		printf("Queue Memory Error!\n"); exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq) {
	if (QisEmpty(pq)) {
		printf("Queue Memory Error!\n"); exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue *pq) {
	if (QisEmpty(pq)) {
		printf("Queue Memory Error!\n"); exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];
}

int main(void) {
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QisEmpty(&q)) printf("%d ", Dequeue(&q));
	printf("\n");
	return 0;
}