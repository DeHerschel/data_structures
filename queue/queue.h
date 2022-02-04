#ifndef queue_h
#define queue_h
#include <stdio.h>
#include "order.h"

typedef struct Node {
	Order *order;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *head;
	Node *end;
	int length;
} Queue;

Node *CreateNode(Order *order);

void DestroyNode(Node *node);

Queue *CreateQueue();

void DeleteQueue();

void queueUp(Queue *queue, Order *book);

Order *get(Queue *queue);

int isEmpty(Queue *queue);

Order *packOff(Queue *queue);

#endif