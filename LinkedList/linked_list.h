#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_node.h"

typedef struct linked_list {
	lnode *head, *tail;
	int size;
}linkedlist;

linkedlist *creat_list();
void delete_list(linkedlist *ll);
int is_list_empty(linkedlist *ll);
int get_list_size(linkedlist *ll);
void add_list_first(linkedlist *ll, void *data);
void add_list_last(linkedlist *ll, void *data);
void *remove_list_first(linkedlist *ll);
void *remove_list_last(linkedlist *ll);