#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"

int main() {
	Book book1;
	Book *p_book1 = &book1;
	strncpy(p_book1->title, "Don Quijote",50);
	strncpy(p_book1->author, "Miguel de Cervantes",50);
	strncpy(p_book1->isbn, "1234567890123",13);

	Book book2;
	Book *p_book2 = &book2;
	strncpy(p_book2->title, "La Regenta", 50);
	strncpy(p_book2->author, "Miguel de Cervantes", 50);
	strncpy(p_book2->isbn, "1234567890123", 13);

	Book book3;
	Book *p_book3 = &book3;
	strncpy(p_book3->author, "Miguel de Cervantes", 50);
	strncpy(p_book3->isbn, "1234567890123", 13);
	strncpy(p_book3->title, "Rinconete y cortadillo", 50);
	List list = CreateList();
	List* p_list = &list;
	InsertFirst(p_list, p_book2);
	InsertFirst(p_list, p_book1);
	InsertLast(p_list, p_book3);
	InsertAfter(0, p_list, p_book1);

	printf("%s\n", p_list->head->next->book.title);
	
	DeleteFirst(p_list);

	printf("%s\n", p_list->head->next->book.title);
	
	DeleteLast(p_list);
	
	printf("%s\n", Get(0, p_list)->title);

	Delete(0, p_list);

	printf("%s\n", Get(0, p_list)->title);

	return 0;
}
