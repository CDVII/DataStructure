#include "vertex_graph.h"

gvertex *create_graph_vertex(void *vertex_value) {
	gvertex *v = (gvertex*)malloc(sizeof(gvertex));
	memset(v, 0, sizeof(gvertex));
	v->vertex_value = vertex_value;
	return v;
}

void delete_graph_vertex(gvertex *v) {
	gedge *e = v->next_edge;
	while (v->next_edge != NULL) {
		v->next_edge = v->next_edge->next_edge;
		delete_graph_edge(e);
		e = v->next_edge;
	}
	free(v);
}