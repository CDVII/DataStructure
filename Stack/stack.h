#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_node.h"

typedef struct _stack {
	snode *top;
	int size;
}stack;

stack *creat_stack();
void delete_stack(stack *s);
int is_stack_empty(stack *s);
int get_stack_size(stack *s);
void push_stack(stack *s, void *data);
void *pop_stack(stack *s);
void *peek_stack(stack *s);