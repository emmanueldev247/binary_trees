#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given node
 * 			or NULL (no ancestor)
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t f_depth, s_depth, diff, i;
	binary_tree_t *f_temp, *s_temp;

	if (!first || !second)
		return (NULL);

	f_temp = (binary_tree_t *)first;
	s_temp = (binary_tree_t *)second;

	f_depth = binary_tree_depth(first);
	s_depth = binary_tree_depth(second);

	if (f_depth >= s_depth)
	{
		diff = f_depth - s_depth;
		for (i = 0; i < diff; i++)
			f_temp = f_temp->parent;
	}
	else
	{
		diff = s_depth - f_depth;
		for (i = 0; i < diff; i++)
			s_temp = s_temp->parent;
	}

	if (f_temp == s_temp)
		return (f_temp);

	while (s_temp->parent)
	{
		if (f_temp->parent == s_temp->parent)
			return (f_temp->parent);
		f_temp = f_temp->parent;
		s_temp = s_temp->parent;
	}
	return (NULL);
}

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

