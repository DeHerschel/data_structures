#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

Node *CreateNode(Order *order) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->order = order;
	node->next = NULL;
	return node;
}

void DestroyNode(Node *node) {
	node->order = NULL;
	node->next = NULL;
	free(node);
}

Queue *CreateQueue() {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->head = NULL;
	queue->end = NULL;
	queue->length = 0;
	return queue;
}

int isEmpty(Queue *queue){
	return (queue->head == NULL);
}

void queueUp(Queue *queue, Order *order) {
	Node *node = CreateNode(order);
	//empty queue
	if (!isEmpty(queue)) {
		queue->head = node;
		queue->end = node;
		queue->length++;
		return;
	}	
	queue->end->next = node;
	queue->end = node;
	queue->length++;
}

Order* Get(int n, Queue * queue) {
	if (queue->head == NULL) {
		return NULL;
	}
	Node *p = queue->head;
	int i = 0;
	while (p->next && i < n) {
		p = p->next;
		i++;
	}
	return &p->order;
}
void delete(Queue *queue) {
	if (!isEmpty(queue)) {
		Node *to_delete = queue->head;
		queue->head = queue->head->next;
		DestroyNode(to_delete);
		queue->length--;
		if (!isEmpty(queue)) {
			queue->end = NULL;
		}
	}
}

Order *get(Queue *queue) {
	if (!isEmpty(queue)) {
		Order *order = queue->head->order;
		return order;
	}
}

Order *packOff(Queue *queue){
	Order *order = get(queue);
	delete(queue);
	return order;
}

void DestroyQueue(Queue *queue) {
	while (!isEmpty(queue)) {
		delete(queue);
	}
	free(queue);
}