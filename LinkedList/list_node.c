#include "list_node.h"

lnode *create_list_node(void *data) {
	lnode *n = (lnode*)malloc(sizeof(lnode));
	memset(n, 0, sizeof(lnode));
	n->data = data;
	return n;
}

void delete_list_node(lnode *n) {
	free(n);
}