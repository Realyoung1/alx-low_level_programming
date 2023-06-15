#include "lists.h"

#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

/**
 * dlistint_len - func counts the number of nodes in the linked list.
 * @h: pointer to the beginning of a linked lists.
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t k;

	for (k = 0; h != NULL; k++)
		h = h->next;
	return (k);
}
