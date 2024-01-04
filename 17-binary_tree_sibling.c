#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the siblings of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: NULL if parent || node is NULL, otherwise a pointer to the sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
