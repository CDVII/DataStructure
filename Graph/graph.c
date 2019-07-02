#include "graph.h"

// 헤더파일을 include 하면 머리 부분만 가져오므로 몸통이 설정된 부분을 직접 include한다.
#include "..\stack\stack.c"
#include "..\stack\stack_node.c"
#include "..\queue\queue.c"
#include "..\queue\queue_node.c"

int *visited;	// using dfs, bfs (static 키워드는 해당 파일에서만 전역변수에 접근 가능)

graph *creat_graph() {
    graph *g = (graph*)malloc(sizeof(graph));
    memset(g, 0, sizeof(graph));
    g->head = 0;
    g->vertex_size = 0;
    return g;
}

void delete_graph(graph *g) {
    gvertex *v = g->head;
    while (g->head != NULL) {
        g->head = g->head->next_vertex;
        delete_graph_vertex(v);
        v = g->head;
    }
    free(g);
}

int get_graph_vertex_size(graph *g) { return g->vertex_size; }

int insert_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *)) {
    gvertex *object_vertex = create_graph_vertex(vertex_value), *prev = NULL, *curr = g->head;
    while (curr != NULL && compare(vertex_value, curr->vertex_value) > 0) {
        prev = curr;
        curr = curr->next_vertex;
    }
    if (curr != NULL && compare(vertex_value, curr->vertex_value) == 0)
        return 0;
    if (prev == NULL)
        g->head = object_vertex;
    else
        prev->next_vertex = object_vertex;
    object_vertex->next_vertex = curr;
    ++g->vertex_size;
    return 1;
}

void insert_edge(graph *g, void *from_vertex_value, void *to_vertex_value, double weight, int(*compare)(const void *, const void *)) {
    gvertex *object_vertex = find_vertex(g, from_vertex_value, compare);
    gedge *object_edge = create_graph_edge(to_vertex_value, weight), *prev = NULL, *curr = object_vertex->next_edge;
    while (curr != NULL && compare(to_vertex_value, curr->to_vertex_value) > 0) {
        prev = curr;
        curr = curr->next_edge;
    }
    if (prev == NULL)
        object_vertex->next_edge = object_edge;
    else
        prev->next_edge = object_edge;
    object_edge->next_edge = curr;
}

int remove_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *)) {
    gvertex *prev = NULL, *curr = g->head;
    while (curr != NULL && compare(vertex_value, curr->vertex_value) > 0) {
        prev = curr;
        curr = curr->next_vertex;
    }
    if (curr != NULL && compare(vertex_value, curr->vertex_value) == 0) {
        if (prev == NULL)
            g->head = curr->next_vertex;
        else
            prev->next_vertex = curr->next_vertex;
        delete_graph_vertex(curr);
        --g->vertex_size;

        // remove connected all edges.
        curr = g->head;
        while (curr != NULL) {
            remove_all_edge(g, curr->vertex_value, vertex_value, compare);
            curr = curr->next_vertex;
        }
        return 1;
    }
    return 0;
}

int remove_all_edge(graph *g, void *from_vertex_value, void *to_vertex_value, int(*compare)(const void *, const void *)) {
    int count = 0;
    gvertex *object_vertex = find_vertex(g, from_vertex_value, compare);
    if (object_vertex != NULL) {
        gedge *prev = NULL, *curr = object_vertex->next_edge, *remove;
        while (curr != NULL && compare(to_vertex_value, curr->to_vertex_value) > 0) {
            prev = curr;
            curr = curr->next_edge;
        }
        if (curr == NULL || compare(to_vertex_value, curr->to_vertex_value) < 0)
            return 0;
        while (curr != NULL && compare(to_vertex_value, curr->to_vertex_value) == 0) {
            if (prev == NULL)
                object_vertex->next_edge = curr->next_edge;
            else
                prev->next_edge = curr->next_edge;
            remove = curr;
            curr = curr->next_edge;
            delete_graph_edge(remove);
            ++count;
        }
        return count;
    }
    return 0;
}

int remove_one_edge(graph *g, void *from_vertex_value, void *to_vertex_value, double weight, int(*compare)(const void *, const void *)) {
    gvertex *object_vertex = find_vertex(g, from_vertex_value, compare);
    if (object_vertex != NULL) {
        gedge *prev = NULL, *curr = object_vertex->next_edge;
        while (curr != NULL && compare(to_vertex_value, curr->to_vertex_value) > 0) {
            prev = curr;
            curr = curr->next_edge;
        }
        if (curr == NULL || compare(to_vertex_value, curr->to_vertex_value) < 0)
            return 0;
        while (curr != NULL && compare(to_vertex_value, curr->to_vertex_value) == 0) {
            if (curr->weight == weight) {
                if (prev == NULL)
                    object_vertex->next_edge = curr->next_edge;
                else
                    prev->next_edge = curr->next_edge;
                delete_graph_edge(curr);
                return 1;
            }
            prev = curr;
            curr = curr->next_edge;
        }
        return 0;
    }
    return 0;
}

gvertex *find_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *)) {
    gvertex *curr = g->head;
    while (curr != NULL && compare(vertex_value, curr->vertex_value) > 0)
        curr = curr->next_vertex;
    if (curr != NULL && compare(vertex_value, curr->vertex_value) < 0)
        return NULL;
    return curr;
}

void print_graph(graph *g, enum type t) {
    gvertex *curr_vertex = g->head;
    gedge *curr_edge;
    while (curr_vertex != NULL)
    {
        print_type(curr_vertex->vertex_value, t);
        printf(" ->");
        curr_edge = curr_vertex->next_edge;
        while (curr_edge != NULL)
        {
            printf(" ");
            print_type(curr_edge->to_vertex_value, t);
            curr_edge = curr_edge->next_edge;
        }
        curr_vertex = curr_vertex->next_vertex;
        printf("\n");
    }
    printf("Number of vertices: %d\n", g->vertex_size);
}

void print_type(void *data, enum type t) {
    switch (t) {
        case type_char:
            printf("%c", (char)data); break;
        case type_int:
            printf("%d", (int)data); break;
        case type_long:
            printf("%ld", (long)data); break;
    }
}

int index_vertex(graph *g, void *vertex_value, int(*compare)(const void *, const void *)) {
    int order = 0;
    gvertex *curr = g->head;
    while (curr != NULL && compare(vertex_value, curr->vertex_value) > 0) {
        curr = curr->next_vertex;
        ++order;
    }
    if (curr != NULL && compare(vertex_value, curr->vertex_value) < 0)
        return -1;
    return curr != NULL ? order : -1;
}

void depthFirstSearch(graph *g, int(*compare)(const void *, const void *), enum type t) {
    int now_index, next_index;
    gvertex *now_vertex = g->head, *next_vertex;
    gedge *now_edge;
    stack *vertex_stack = creat_stack();
    visited = (int*)malloc(sizeof(int) * g->vertex_size);
    memset(visited, 0, sizeof(int) * g->vertex_size);

    printf("Depth First Search :");
    push_stack(vertex_stack, now_vertex->vertex_value);
    now_index = index_vertex(g, now_vertex->vertex_value, compare);
    printf(" ");
    print_type(now_vertex->vertex_value, t);
    visited[now_index] = 1;

    while (is_stack_empty(vertex_stack) == 0) {
        now_vertex = find_vertex(g, peek_stack(vertex_stack), compare);
        now_index = index_vertex(g, now_vertex->vertex_value, compare);
        now_edge = now_vertex->next_edge;
        while (now_edge != NULL) {
            next_vertex = find_vertex(g, now_edge->to_vertex_value, compare);
            next_index = index_vertex(g, next_vertex->vertex_value, compare);
            if (visited[next_index] == 0) {

                printf(" ");
                print_type(next_vertex->vertex_value, t);

                push_stack(vertex_stack, next_vertex->vertex_value);
                visited[next_index] = 1;
                break;
            }
            now_edge = now_edge->next_edge;
        }
        if (now_edge == NULL)
            pop_stack(vertex_stack);
    }

    printf("\n");
    delete_stack(vertex_stack);
    free(visited);
}

/*
// 재귀적인 방법으로 DFS 구현
void depthFirstSearch(graph *g, int(*compare)(const void *, const void *), enum type t) {
	visited = (int*)malloc(sizeof(int) * g->vertex_size);
	memset(visited, 0, sizeof(int) * g->vertex_size);
	printf("Depth First Search :");
	dfs_node(g, g->head, compare, t);
	printf("\n");
	free(visited);
}

void dfs_node(graph *g, gvertex *curr_vertex, int(*compare)(const void *, const void *), enum type t) {
	int order = index_vertex(g, curr_vertex->vertex_value, compare);
	printf(" ");
	print_type(curr_vertex->vertex_value, t);
	visited[order] = 1;
	if (curr_vertex->next_edge != NULL) {
		gedge *curr_edge = curr_vertex->next_edge;
		while (curr_edge != NULL) {
			gvertex *next_vertex = find_vertex(g, curr_edge->to_vertex_value, compare);
			if (visited[index_vertex(g, curr_edge->to_vertex_value, compare)] == 0)
				dfs_node(g, next_vertex, compare, t);
			curr_edge = curr_edge->next_edge;
		}
	}
}
*/

void breadthFirstSearch(graph *g, int(*compare)(const void *, const void *), enum type t) {
    int now_index, next_index;
    gvertex *now_vertex = g->head, *next_vertex;
    gedge *now_edge;
    queue *vertex_queue = creat_queue();
    visited = (int*)malloc(sizeof(int) * g->vertex_size);
    memset(visited, 0, sizeof(int) * g->vertex_size);
    printf("Breadth First Search :");

    enqueue_queue(vertex_queue, now_vertex->vertex_value);
    now_index = index_vertex(g, now_vertex->vertex_value, compare);
    visited[now_index] = 1;
    while (is_queue_empty(vertex_queue) == 0) {
        now_vertex = find_vertex(g, dequeue_queue(vertex_queue), compare);
        now_index = index_vertex(g, now_vertex->vertex_value, compare);

        printf(" ");
        print_type(now_vertex->vertex_value, t);

        now_edge = now_vertex->next_edge;
        while (now_edge != NULL) {
            next_vertex = find_vertex(g, now_edge->to_vertex_value, compare);
            next_index = index_vertex(g, next_vertex->vertex_value, compare);
            if (visited[next_index] == 0) {
                enqueue_queue(vertex_queue, next_vertex->vertex_value);
                visited[next_index] = 1;
            }
            now_edge = now_edge->next_edge;
        }
    }

    printf("\n");
    delete_queue(vertex_queue);
    free(visited);
}
