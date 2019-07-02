#include "stack_node.h"

snode *create_stack_node(void *data) {
	snode *n = (snode*)malloc(sizeof(snode));
	memset(n, 0, sizeof(snode));
	n->data = data;
	return n;
}

void delete_stack_node(snode *n) {
	free(n);
}