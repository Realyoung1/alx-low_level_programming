#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

/* LIBRARIES */
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
#include <math.h>

/* STRUCTURES */

/**
 * struct listint_s - singlyed link listsss
 *
 * @n: Integered
 * @index: Indexes of the nodes in the listed
 * @next: Pointerss to the next nodess
 *
 * Description: singlyed link listsss nodes structures
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;
/**
 * struct skiplist_s - Singlyed link listss with an expressed laned
 *
 * @n: Integerss
 * @index: Indexes of the node in the listsss
 * @next: Poineterd to the next nodesss
 * @express: Pointered to the nexts nodes in the express lane
 *
 * Description: singlyed linkss list node structure with an express lane
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* PROTOTYPES */

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
listint_t *create_list(int *array, size_t size);
void free_list(listint_t *list);
void print_list(const listint_t *list);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
