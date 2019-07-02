#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct graph_edge {
	struct graph_edge *next_edge;
	double weight;
	void *to_vertex_value;
}gedge;

gedge *create_graph_edge(void *to_vertex_value, double weight);
void delete_graph_edge(gedge *e);