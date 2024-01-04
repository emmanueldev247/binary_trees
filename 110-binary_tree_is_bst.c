#include "binary_trees.h"

/**
 * bst_helper - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value allowed in the subtree
 * @max: The maximum value allowed in the subtree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_helper(tree->left, min, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_helper(tree, INT_MIN, INT_MAX));
}
