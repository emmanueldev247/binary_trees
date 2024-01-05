#include "binary_trees.h"

/**
 * minValueNode - gets the node with the smallest value in a binary search tree
 * @node: a pointer to the root of the tree
 *
 * Return: a pointer to the node with the smallest value in the tree
 */
bst_t *minValueNode(bst_t *node)
{
	bst_t *current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;

			free(root);
			return (temp);
		}

		temp = minValueNode(root->right);

		root->n = temp->n;

		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
