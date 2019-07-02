#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int compare_char(const void *first, const void *second);
int compare_int(const void *first, const void *second);
int compare_long(const void *first, const void *second);

int main(void) {
	// int graph
	graph *g = creat_graph();
	insert_vertex(g, (void*)1, compare_int);
	insert_vertex(g, (void*)4, compare_int);
	insert_vertex(g, (void*)3, compare_int);
	insert_vertex(g, (void*)2, compare_int);
	insert_vertex(g, (void*)3, compare_int);
	insert_vertex(g, (void*)1, compare_int);
	print_graph(g, type_int);

	insert_edge(g, (void*)1, (void*)2, 1.0, compare_int);
	insert_edge(g, (void*)1, (void*)3, 1.5, compare_int);
	insert_edge(g, (void*)2, (void*)1, 0.5, compare_int);
	insert_edge(g, (void*)2, (void*)4, 2.0, compare_int);
	print_graph(g, type_int);
	depthFirstSearch(g, compare_int, type_int);
	breadthFirstSearch(g, compare_int, type_int);

	remove_vertex(g, (void*)4, compare_int);
	print_graph(g, type_int);

	remove_one_edge(g, (void*)1, (void*)2, 1.0, compare_int);
	print_graph(g, type_int);

	delete_graph(g);
	
	// char graph
	g = creat_graph();
	insert_vertex(g, (void*)'A', compare_char);
	insert_vertex(g, (void*)'B', compare_char);
	insert_vertex(g, (void*)'C', compare_char);
	insert_vertex(g, (void*)'D', compare_char);
	insert_vertex(g, (void*)'E', compare_char);
	insert_vertex(g, (void*)'F', compare_char);
	insert_vertex(g, (void*)'G', compare_char);
	insert_vertex(g, (void*)'H', compare_char);
	insert_vertex(g, (void*)'I', compare_char);
	insert_vertex(g, (void*)'J', compare_char);
	insert_vertex(g, (void*)'K', compare_char);
	insert_vertex(g, (void*)'L', compare_char);
	insert_vertex(g, (void*)'M', compare_char);
	insert_vertex(g, (void*)'N', compare_char);
	insert_vertex(g, (void*)'O', compare_char);

	insert_edge(g, (void*)'A', (void*)'B', 0.0, compare_char);
	insert_edge(g, (void*)'B', (void*)'C', 0.0, compare_char);
	insert_edge(g, (void*)'C', (void*)'D', 0.0, compare_char);
	insert_edge(g, (void*)'B', (void*)'E', 0.0, compare_char);
	insert_edge(g, (void*)'E', (void*)'F', 0.0, compare_char);
	insert_edge(g, (void*)'E', (void*)'G', 0.0, compare_char);
	insert_edge(g, (void*)'F', (void*)'G', 0.0, compare_char);
	insert_edge(g, (void*)'F', (void*)'H', 0.0, compare_char);
	insert_edge(g, (void*)'H', (void*)'I', 0.0, compare_char);
	insert_edge(g, (void*)'H', (void*)'J', 0.0, compare_char);
	insert_edge(g, (void*)'J', (void*)'K', 0.0, compare_char);
	insert_edge(g, (void*)'J', (void*)'L', 0.0, compare_char);
	insert_edge(g, (void*)'L', (void*)'M', 0.0, compare_char);
	insert_edge(g, (void*)'L', (void*)'N', 0.0, compare_char);
	insert_edge(g, (void*)'L', (void*)'O', 0.0, compare_char);
	print_graph(g, type_char);
	depthFirstSearch(g, compare_char, type_char);
	breadthFirstSearch(g, compare_char, type_char);

	remove_vertex(g, (void*)'L', compare_int);
	print_graph(g, type_char);
	depthFirstSearch(g, compare_char, type_char);
	breadthFirstSearch(g, compare_char, type_char);

	delete_graph(g);

	return 0;
}

int compare_char(const void *first, const void *second) {
	if ((char)first > (char)second)
		return 1;
	else if ((char)first < (char)second)
		return -1;
	else
		return 0;
}

int compare_int(const void *first, const void *second) {
	if ((int)first > (int)second)
		return 1;
	else if ((int)first < (int)second)
		return -1;
	else
		return 0;
}

int compare_long(const void *first, const void *second) {
	if ((long)first > (long)second)
		return 1;
	else if ((long)first < (long)second)
		return -1;
	else
		return 0;
}