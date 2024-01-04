#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: returns height of tree/subtree; if tree is NULL, return 0
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = right_height = 0;
	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	else
		left_height = 0;

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	else
		right_height = 0;

	if (left_height >= right_height)
		return (left_height);
	else
		return (right_height);
}

