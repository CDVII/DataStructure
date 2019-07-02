#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

int compare_char(const void *first, const void *second);
int compare_int(const void *first, const void *second);
int compare_long(const void *first, const void *second);

int main(void) {
	int a = 45, b = 46;
	char c = 'U', d = 'N';
	
	// int tree
	bst *tree = creat_bstree();

	insert_bstree(tree, (void*)23, compare_int);
	insert_bstree(tree, (void*)46, compare_int);
	insert_bstree(tree, (void*)35, compare_int);
	insert_bstree(tree, (void*)2, compare_int);
	insert_bstree(tree, (void*)3, compare_int);
	insert_bstree(tree, (void*)1, compare_int);

	printf("tree size : %d\n", tree->size);
	printf("tree %s %d\n", search_bstree(tree, (void*)a, compare_int) ? "have" : "don't have", a);
	printf("tree %s %d\n\n", search_bstree(tree, (void*)b, compare_int) ? "have" : "don't have", b);

	print_bstree(tree, type_int);
	printf("\n\n\n");

	remove_bstree(tree, (void*)45, compare_int);
	print_bstree(tree, type_int);
	printf("\n\n\n");

	remove_bstree(tree, (void*)46, compare_int);
	print_bstree(tree, type_int);
	printf("\n\n\n");

	remove_bstree(tree, (void*)2, compare_int);
	print_bstree(tree, type_int);
	printf("\n\n\n");

	remove_bstree(tree, (void*)23, compare_int);
	print_bstree(tree, type_int);
	printf("\n\n\n");
	printf("\n\n\n");

	delete_bstree(tree);

	// char tree
	tree = creat_bstree();

	print_bstree(tree, type_char);

	insert_bstree(tree, (void*)'K', compare_char);
	insert_bstree(tree, (void*)'E', compare_char);
	insert_bstree(tree, (void*)'A', compare_char);
	insert_bstree(tree, (void*)'T', compare_char);
	insert_bstree(tree, (void*)'T', compare_char);
	insert_bstree(tree, (void*)'L', compare_char);
	insert_bstree(tree, (void*)'N', compare_char);
	insert_bstree(tree, (void*)'M', compare_char);

	printf("tree size : %d\n", tree->size);
	printf("tree %s %c\n", search_bstree(tree, (void*)c, compare_char) ? "have" : "don't have", c);
	printf("tree %s %c\n\n\n", search_bstree(tree, (void*)d, compare_char) ? "have" : "don't have", d);

	print_bstree(tree, type_char);
	printf("\n\n\n");

	print_prefix(tree, type_char);
	print_infix(tree, type_char);
	print_postfix(tree, type_char);
	printf("\n");

	remove_bstree(tree, (void*)'L', compare_char);
	print_bstree(tree, type_char);
	printf("\n\n\n");

	remove_bstree(tree, (void*)'E', compare_char);
	print_bstree(tree, type_char);
	printf("\n\n\n");

	delete_bstree(tree);
	
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