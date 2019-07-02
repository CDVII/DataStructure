#include "binary_search_tree.h"

int insert_success, remove_success;

bst *creat_bstree() {
	bst *tree = (bst*)malloc(sizeof(bst));
	memset(tree, 0, sizeof(bst));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}

void delete_bstree(bst *tree) {
	delete_bst_branch(tree->root);
	free(tree);
}
void delete_bst_branch(tnode *curr) {
	if (curr != NULL) {
		delete_bst_branch(curr->left);
		delete_bst_branch(curr->right);
		delete_bst_node(curr);
	}
}

int get_tree_size(bst *tree) { return tree->size; }

int insert_bstree(bst *tree, void *data, int(*compare)(const void *, const void *)) {
	tree->root = insert_bst_branch(tree->root, data, compare);
	tree->size = insert_success == 1 ? tree->size + 1 : 0;
	return insert_success;
}
tnode *insert_bst_branch(tnode *curr, void *data, int(*compare)(const void *, const void *)) {
	if (curr == NULL) {
		insert_success = 1;
		curr = create_bst_node(data);
	}
	else if (compare(curr->data, data) > 0)
		curr->left = insert_bst_branch(curr->left, data, compare);
	else if (compare(curr->data, data) < 0)
		curr->right = insert_bst_branch(curr->right, data, compare);
	else
		insert_success = 0;
	return curr;
}

int search_bstree(bst *tree, void *data, int(*compare)(const void *, const void *)) {
	return search_bst_branch(tree->root, data, compare);
}
int search_bst_branch(tnode *curr, void *data, int(*compare)(const void *, const void *)) {
	if (curr == NULL)
		return 0;
	else if (compare(curr->data, data) > 0)
		return search_bst_branch(curr->left, data, compare);
	else if (compare(curr->data, data) < 0)
		return search_bst_branch(curr->right, data, compare);
	else
		return 1;
}

int remove_bstree(bst *tree, void *data, int(*compare)(const void *, const void *)) {
	tree->root = remove_bst_branch(tree->root, data, compare);
	tree->size = insert_success == 1 ? tree->size - 1 : 0;
	return remove_success;
}
tnode *remove_bst_branch(tnode *curr, void *data, int(*compare)(const void *, const void *)) {
	tnode *max_node;
	if (curr == NULL)
		remove_success = 0;
	else if (compare(curr->data, data) > 0)
		curr->left = remove_bst_branch(curr->left, data, compare);
	else if (compare(curr->data, data) < 0)
		curr->right = remove_bst_branch(curr->right, data, compare);
	else {
		remove_success = 1;
		if (curr->left == NULL) {
			curr = curr->right;
		}
		else if (curr->right == NULL)
			curr = curr->left;
		else {
			max_node = curr->left;
			while (max_node->right != NULL)
				max_node = max_node->right;
			curr->data = max_node->data;
			curr->left = remove_bst_branch(curr->left, max_node->data, compare);
		}
	}
	return curr;
}

void print_bstree(bst *tree, enum type t) {
	if(tree->root != NULL)
		print_bst_branch(tree->root, 0, t);
}

void print_bst_branch(tnode *curr, int blank_count, enum type t) {
	if (curr != NULL) {
		int i;
		print_bst_branch(curr->right, blank_count + 10, t);
		for (i = 0; i < blank_count; i++)
			printf(" ");
		print_type(curr->data, t);
		if (curr->left != NULL)
			printf(",L");
		if (curr->right != NULL)
			printf(",R");
		printf("\n");
		print_bst_branch(curr->left, blank_count + 10, t);
	}
}

void print_type(void *data, enum type t) {
	switch (t) {
	case type_char :
		printf("%c", (char)data); break;
	case type_int:
		printf("%d", (int)data); break;
	case type_long:
		printf("%ld", (long)data); break;
	}
}

void print_prefix(bst *tree, enum type t) {
	printf("Prefix of Tree :");
	print_prefix_branch(tree->root, t);
	printf("\n");
}
void print_prefix_branch(tnode *curr, enum type t) {
	if (curr != NULL) {
		printf(" ");
		print_type(curr->data, t);
		print_prefix_branch(curr->left, t);
		print_prefix_branch(curr->right, t);
	}
}

void print_infix(bst *tree, enum type t) {
	printf("Infix of Tree :");
	print_infix_branch(tree->root, t);
	printf("\n");
}
void print_infix_branch(tnode *curr, enum type t) {
	if (curr != NULL) {
		print_infix_branch(curr->left, t);
		printf(" ");
		print_type(curr->data, t);
		print_infix_branch(curr->right, t);
	}
}

void print_postfix(bst *tree, enum type t) {
	printf("Postfix of Tree :");
	print_postfix_branch(tree->root, t);
	printf("\n");
}
void print_postfix_branch(tnode *curr, enum type t) {
	if (curr != NULL) {
		print_postfix_branch(curr->left, t);
		print_postfix_branch(curr->right, t);
		printf(" ");
		print_type(curr->data, t);
	}
}