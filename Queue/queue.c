#include "queue.h"

queue *creat_queue() {
	queue *q = (queue*)malloc(sizeof(queue));
	memset(q, 0, sizeof(queue));
	q->front = q->rear = NULL;
	q->size = 0;
	return q;
}

void delete_queue(queue *q) {
	while (!is_queue_empty(q))
		dequeue_queue(q);
	free(q);
}

int is_queue_empty(queue *q) {
	return q->size == 0;
}

int get_queue_size(queue *q) {
	return q->size;
}

void enqueue_queue(queue *q, void *data) {
	qnode *n = create_queue_node(data);
	if (is_queue_empty(q))
		q->front = q->rear = n;
	else {
		q->rear->next = n;
		q->rear = n;
	}
	++q->size;
}

void *dequeue_queue(queue *q) {
	qnode *object;
	void *data;
	if (is_queue_empty(q)) {
		puts("\nException : queue is empty!\n");
		exit(1);
	}
	object = q->front;
	data = object->data;
	if (get_queue_size(q) == 1)
		q->front = q->rear = NULL;
	else
		q->front = object->next;
	--q->size;
	delete_queue_node(object);
	return data;
}

void *peek_queue(queue *q) {
	if (is_queue_empty(q)) {
		puts("\nException : queue is empty!\n");
		exit(1);
	}
	return q->front->data;
}