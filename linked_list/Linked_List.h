#ifndef linked_list_h
#define linked_list_h
#include <stdio.h>
#include "book.h"

typedef struct Node {
	Book book;
	struct Node* next;
} Node;

typedef struct List {
	Node* head;
	int length;
} List;

List CreateList();

Node *CreateNode(Book *book);

void DestroyNode(Node *node);

void InsertFirst(List *list, Book *book);

void InsertLast(List *list, Book *book);

void InsertAfter(int n, List *list, Book *book);

Book *Get(int n, List *list);

int isEmpty(List *list);

void DeleteFirst(List *list);

void DeleteLast(List *list);

void Delete(int n, List *list);

#endif