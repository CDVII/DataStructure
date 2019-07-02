#pragma once

#include <stdlib.h>
#include <string.h>

#include "edge_graph.h"

typedef struct graph_vertex {
	struct graph_vertex *next_vertex;
	gedge *next_edge;
	void *vertex_value;
}gvertex;

gvertex *create_graph_vertex(void *vertex_value);
void delete_graph_vertex(gvertex *v);