#ifndef book_h
#define book_h
typedef struct Book {
	char title[50];
	char author[50];
	char isbn[13];
} Book;
#endif