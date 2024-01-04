#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
 * binary_tree_levelorder - level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	size_t size, i, j;

	if (tree == NULL || func == NULL)
		return;

	/* Allocate memory for the queue */
	size = binary_tree_size(tree);
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (queue == NULL)
		return;

	/* Enqueue the root and initialize the indices */
	queue[0] = (binary_tree_t *)tree;
	i = 0;
	j = 1;

	while (i < j)
	{
		func(queue[i]->n);
		if (queue[i]->left != NULL)
			queue[j++] = queue[i]->left;
		if (queue[i]->right != NULL)
			queue[j++] = queue[i]->right;
		i++;
	}

	free(queue);
}
