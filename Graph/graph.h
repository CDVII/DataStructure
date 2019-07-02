#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex_graph.h"

enum type {
	type_char,
	type_int,
	type_long
};

typedef struct _graph {
	gvertex *head;
	int vertex_size;
}graph;

graph *creat_graph();
void delete_graph(graph *g);

int get_graph_vertex_size(graph *g);

int insert_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *));
void insert_edge(graph *g, void *from_vertex_value, void *to_vertex_value, double weight, int(*compare)(const void *, const void *));

int remove_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *));
int remove_all_edge(graph *g, void *from_vertex_value, void *to_vertex_value, int(*compare)(const void *, const void *));
int remove_one_edge(graph *g, void *from_vertex_value, void *to_vertex_value, double weight, int(*compare)(const void *, const void *));

gvertex *find_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *));

void print_graph(graph *g, enum type t);
void print_type(void *data, enum type t);

int index_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *));

void depthFirstSearch(graph *g, int(*compare)(const void *, const void *), enum type t);
//zvoid dfs_node(graph *g, gvertex *curr, int(*compare)(const void *, const void *), enum type t);
void breadthFirstSearch(graph *g, int(*compare)(const void *, const void *), enum type t);