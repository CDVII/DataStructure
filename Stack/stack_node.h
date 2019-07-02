#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct stack_node {
	struct stack_node *next;
	void *data;
}snode;

snode *create_stack_node(void *data);
void delete_stack_node(snode *n);