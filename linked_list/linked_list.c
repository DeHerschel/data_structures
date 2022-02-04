#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Linked_List.h"
List CreateList(){
	List list;
	list.head = NULL;
	list.length = 0;
	return list;
}
Node *CreateNode(Book *book) {
	Node *node = (Node *)malloc(sizeof(Node));
	strncpy(node->book.title, book->title, 50);
	strncpy(node->book.author, book->author, 50);
	strncpy(node->book.isbn, book->isbn, 13);
	node->next = NULL;
	return node;
}
void DestroyNode(Node *node) {
	free(node);
}
void InsertFirst(List *list, Book *book) {
	Node *node = CreateNode(book);
	node->next = list->head;
	list->head = node;
	list->length++;
}
void InsertLast(List *list, Book *book) {
	Node *node = CreateNode(book);
	//empty list
	if (list->head == NULL) {
		list->head = node;
		list->length++;
		return;
	}	
	Node *p = list->head;
	while (p->next) {
		p = p->next;
	}
	p->next = node;
	list->length++;
}

void InsertAfter(int n, List *list, Book *book){
	Node *node = CreateNode(book);
	if (list->head == NULL) {
		list->head = node;
		list->length++;
		return;
	}
	Node *p = list->head;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	node->next = p->next;
	p->next = node;
	list->length++;
}

Book* Get(int n, List * list) {
	if (list->head == NULL) {
		return NULL;
	}
	Node *p = list->head;
	int i = 0;
	while (p->next && i < n) {
		p = p->next;
		i++;
	}
	return &p->book;
}

int isEmpty(List *list) {
	return (list->head == NULL);
}
void DeleteFirst(List *list){
	if (!isEmpty(list)) {
		Node *to_delete = list->head;
		list->head = list->head->next;
		DestroyNode(to_delete);
		list->length--;
	}
}

void DeleteLast(List *list) {
	if (!isEmpty(list)){
		//list have more than one element
		if (!list->head->next){	
			Node *to_delete = list->head;
			list->head == NULL;
			DestroyNode(to_delete);
			list->length--;
		}
		Node *p = list->head;
		while (p->next->next) {
			p = p->next;
		}
		Node *to_delete = p->next;
		p->next = NULL;
		DestroyNode(to_delete);
		list->length--;
		return;
	}
}

void Delete(int n, List *list) {
	if (!isEmpty(list)){
		if (n == 0) {
			DeleteFirst(list);
			return;
		}
		Node *p = list->head;
		int i = 0;
		while (i < (n-1)) {
			p = p->next;
			i++;
		}
		Node *to_delete = p->next;
		p->next = to_delete->next;
		DestroyNode(to_delete);
		list->length--;
	}
}