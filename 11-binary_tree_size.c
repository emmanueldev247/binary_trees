#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: returns size of tree/subtree; if tree is NULL, return 0
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	size = 0;
	if (!tree)
		return (0);

	size +=	binary_tree_size(tree->left);
	size +=	binary_tree_size(tree->right);
	size++;

	return (size);
}
