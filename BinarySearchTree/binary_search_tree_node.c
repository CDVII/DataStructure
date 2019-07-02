#include "binary_search_tree_node.h"

tnode *create_bst_node(void *data) {
	tnode *n = (tnode*)malloc(sizeof(tnode));
	memset(n, 0, sizeof(tnode));
	n->data = data;
	return n;
}

void delete_bst_node(tnode *n) {
	free(n);
}