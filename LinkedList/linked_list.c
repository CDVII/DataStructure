#include "linked_list.h"

linkedlist *creat_list() {
	linkedlist *ll = (linkedlist*)malloc(sizeof(linkedlist));
	memset(ll, 0, sizeof(linkedlist));
	ll->head = ll->tail = NULL;
	ll->size = 0;
	return ll;
}

void delete_list(linkedlist *ll) {
	while (!is_list_empty(ll))
		remove_list_first(ll);
	free(ll);
}

int is_list_empty(linkedlist *ll) {
	return ll->size == 0;
}

int get_list_size(linkedlist *ll) {
	return ll->size;
}

void add_list_first(linkedlist *ll, void *data) {
	lnode *n = create_list_node(data);
	if (is_list_empty(ll))
		ll->head = ll->tail = n;
	else {
		n->next = ll->head;
		n->prev = ll->tail;
		ll->head->prev = n;
		ll->tail->next = n;
		ll->head = n;
	}
	++ll->size;
}

void add_list_last(linkedlist *ll, void *data) {
	lnode *n = create_list_node(data);
	if (is_list_empty(ll))
		ll->head = ll->tail = n;
	else {
		n->next = ll->head;
		n->prev = ll->tail;
		ll->head->prev = n;
		ll->tail->next = n;
		ll->tail = n;
	}
	++ll->size;
}

void *remove_list_first(linkedlist *ll) {
	lnode *object;
	void *item;
	if (is_list_empty(ll)) {
		puts("\nException : list is empty!\n");
		exit(1);
	}
	object = ll->head;
	item = object->data;
	if (get_list_size(ll) == 1)
		ll->head = ll->tail = NULL;
	else {
		ll->tail->next = object->next;
		object->next->prev = ll->tail;
		ll->head = ll->head->next;
	}
	--ll->size;
	delete_list_node(object);
	return item;
}

void *remove_list_last(linkedlist *ll) {
	lnode *object;
	void *item;
	if (is_list_empty(ll)) {
		puts("\nException : list is empty!\n");
		exit(1);
	}
	object = ll->tail;
	item = object->data;
	if (get_list_size(ll) == 1)
		ll->head = ll->tail = NULL;
	else {
		object->prev->next = ll->head;
		ll->head->prev = object->prev;
		ll->tail = ll->tail->prev;
	}
	--ll->size;
	delete_list_node(object);
	return item;
}
