#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue_node.h"

typedef struct _queue {
	qnode *front, *rear;
	int size;
}queue;

queue *creat_queue();
void delete_queue(queue *q);
int is_queue_empty(queue *q);
int get_queue_size(queue *q);
void enqueue_queue(queue *q, void *data);
void *dequeue_queue(queue *q);
void *peek_queue(queue *q);