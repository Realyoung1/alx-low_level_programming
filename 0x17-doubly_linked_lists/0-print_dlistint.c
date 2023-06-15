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
 * print_dlistint - to print all the elements of a dlistint_t list.
 * @h: pointers to the start of the linked lists.
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t k;

	for (k = 0; h != NULL; k++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (k);
}
