#ifndef order_h
#define order_h
#include <stdio.h>

typedef struct OrderLine {
	int product_id;
	int amount;
	float price;
} OrderLine;

typedef struct NodeOrderLine {
	OrderLine line;
	struct NodeOrderLine* next;
} NodeOrderLine;

typedef struct Order {
	int client_id;
	NodeOrderLine products_list;
} Order;


#endif