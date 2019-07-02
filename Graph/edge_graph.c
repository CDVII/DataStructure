#include "edge_graph.h"

gedge *create_graph_edge(void *to_vertex_value, double weight) {
	gedge *e = (gedge*)malloc(sizeof(gedge));
	memset(e, 0, sizeof(gedge));
	e->to_vertex_value = to_vertex_value;
	e->weight = weight;
	return e;
}

void delete_graph_edge(gedge *e) {
	free(e);
}