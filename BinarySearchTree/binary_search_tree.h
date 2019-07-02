#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_search_tree_node.h"

enum type {
	type_char,
	type_int,
	type_long,
	type_data
};

typedef struct binary_search_tree {
	tnode *root;
	int size;
}bst;

bst *creat_bstree();
void delete_bstree(bst *tree);
void delete_bst_branch(tnode *curr);

int get_tree_size(bst *tree);

int insert_bstree(bst *tree, void *data, int(*compare)(const void *, const void *));
tnode *insert_bst_branch(tnode *curr, void *data, int(*compare)(const void *, const void *));

int search_bstree(bst *tree, void *data, int(*compare)(const void *, const void *));
int search_bst_branch(tnode *curr, void *data, int(*compare)(const void *, const void *));

int remove_bstree(bst *tree, void *data, int(*compare)(const void *, const void *));
tnode *remove_bst_branch(tnode *curr, void *data, int(*compare)(const void *, const void *));

void print_bstree(bst *tree, enum type t);
void print_bst_branch(tnode *curr, int blank_count, enum type t);
void print_type(void *data, enum type t);

void print_prefix(bst *tree, enum type t);
void print_prefix_branch(tnode *curr, enum type t);

void print_infix(bst *tree, enum type t);
void print_infix_branch(tnode *curr, enum type t);

void print_postfix(bst *tree, enum type t);
void print_postfix_branch(tnode *curr, enum type t);