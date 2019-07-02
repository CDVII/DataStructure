#include "queue_node.h"

qnode *create_queue_node(void *data) {
	qnode *n = (qnode*)malloc(sizeof(qnode));
	memset(n, 0, sizeof(qnode));
	n->data = data;
	return n;
}

void delete_queue_node(qnode *n) {
	free(n);
}