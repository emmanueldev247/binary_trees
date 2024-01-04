#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the depth of a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: returns depth of tree/subtree; if tree is NULL, return 0
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	depth = 0;
	if (!tree)
		return (0);

	if (tree->parent)
		depth = 1 + binary_tree_depth(tree->parent);
	else
		depth = 0;

	return (depth);
}

