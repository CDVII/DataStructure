#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct bst_node {
	struct bst_node *left, *right;
	void *data;
}tnode;

tnode *create_bst_node(void *data);
void delete_bst_node(tnode *n);