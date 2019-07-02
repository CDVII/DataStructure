#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct list_node {
	struct list_node *prev, *next;
	void *data;
}lnode;

lnode *create_list_node(void *data);
void delete_list_node(lnode *n);