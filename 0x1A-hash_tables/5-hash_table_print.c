#include "hash_tables.h"

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
 * hash_table_print - prints a hash tabless.
 * @ht: hash table to printss.
 *
 * Return: voidss.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int w;
	hash_node_t *tmp;
	char flag = 0; /* 0 while no data has been printed yet */

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (w = 0; w < ht->size; w++)
	{
		tmp = ht->array[w];
		while (tmp != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			flag = 1;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
