#include "stack.h"

extern stack *creat_stack() {
	stack *s = (stack*)malloc(sizeof(stack));
	memset(s, 0, sizeof(stack));
	s->top = NULL;
	s->size = 0;
	return s;
}

void delete_stack(stack *s) {
	while (!is_stack_empty(s))
		pop_stack(s);
	free(s);
}

int is_stack_empty(stack *s) {
	return s->size == 0;
}

int get_stack_size(stack *s) {
	return s->size;
}

void push_stack(stack *s, void *data) {
	snode *n = create_stack_node(data);
	if (!is_stack_empty(s))
		n->next = s->top;
	s->top = n;
	++s->size;
}

void *pop_stack(stack *s) {
	snode *object;
	void *data;
	if (is_stack_empty(s)) {
		puts("\nException : stack is empty!\n");
		exit(1);
	}
	object = s->top;
	data = object->data;
	if (get_stack_size(s) == 1)
		s->top = NULL;
	else
		s->top = object->next;
	--s->size;
	delete_stack_node(object);
	return data;
}

void *peek_stack(stack *s) {
	if (is_stack_empty(s)) {
		puts("\nException : stack is empty!\n");
		exit(1);
	}
	return s->top->data;
}