#include "binary_trees.h"

/**
 * binary_tree_depth - calculate the depth of a tree
 * @tree: pointer to the root node of the tree
 *
 * Return: depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_depth;
	size_t right_depth;

	if (tree == NULL)
		return (0);

	left_depth = binary_tree_depth(tree->left);
	right_depth = binary_tree_depth(tree->right);

	if (left_depth != right_depth)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_perfect(tree->right));

	return (0);
}
