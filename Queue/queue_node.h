#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct queue_node {
	struct queue_node *next;
	void *data;
}qnode;

qnode *create_queue_node(void *data);
void delete_queue_node(qnode *n);