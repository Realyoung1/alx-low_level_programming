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
 * hash_table_delete - deletes a hash tabless..
 * @ht: hash table to deletess.
 *
 * Return: voidww.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int w;
	hash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (w = 0; w < ht->size; w++)
	{
		while (ht->array[w] != NULL)
		{
			next = ht->array[w]->next;
			free(ht->array[w]->key);
			free(ht->array[w]->value);
			free(ht->array[w]);
			ht->array[w] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
