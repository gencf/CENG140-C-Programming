#include <stdio.h>
#include <stdlib.h>
#include "the2.h"

/* prints content of the storage */
void print_storage(int **storage, int IA_size, int *DA_sizes)
{
	int i, j;

	for (i = 0; i < IA_size; i++)
	{
		printf("%d -> ", i);

		for (j = 0; j < DA_sizes[i]; j++)
		{
			if (j == DA_sizes[i] - 1)
				printf("%d\n", storage[i][j]);
			else
				printf("%d ", storage[i][j]);
		}
	}
}

/* initialize a 2D dynamic array with given sizes, allocates an array
   to keep data array sizes in the main function */
int **initialize_storage(int IA_size, int DA_size, int **DA_sizes)
{
	int **storage, *data_array_sizes, i;

	data_array_sizes = (int *)calloc(IA_size, sizeof(int));

	for (i = 0; i < IA_size; i++)
	{
		data_array_sizes[i] = DA_size;
	}
	*DA_sizes = data_array_sizes;

	storage = (int **)calloc(IA_size * DA_size, sizeof(int));

	for (i = 0; i < IA_size; i++)
	{
		storage[i] = (int *)calloc(DA_size, sizeof(int));
	}

	return storage;
}

/* transforms given person name to name code */
int transform_name(char *name)
{
	int x = 0, i = 0;
	char ch;

	while ((ch = name[i]) != '\0')
	{
		x += (i + 1) * (i + 1) * ch;
		i++;
	}

	return x;
}

/* inserts given person name into storage, extends corresponding data array if it is full.
   updates data sizes array in case. */
void insert(int **storage, int IA_size, char *text, int *DA_sizes)
{
	int i, j, c, last;
	c = transform_name(text);
	i = c % IA_size;
	last = DA_sizes[i] - 1;

	if (storage[i][last] != 0)
	{
		storage[i] = (int *)realloc(storage[i], DA_sizes[i] * 2 * sizeof(int));

		for (j = DA_sizes[i]; j < DA_sizes[i] * 2; j++)
		{
			storage[i][j] = 0;
		}

		DA_sizes[i] *= 2;
	}

	for (j = 0; j < DA_sizes[i]; j++)
	{
		if (storage[i][j] != 0)
			continue;
		else
		{
			storage[i][j] = c;
			break;
		}
	}
}

/* chechs if need extending the storage. initialize a new one with doubled size in case.
   allocates a new data array sizes, fills new storage, updates data array sizes and
   frees old storage and data array sizes. */
void resize_IA(int ***storage, int *IA_size, int DA_size, int **DA_sizes)
{
	/* write your code here */
	int i, sum = 0, index_array_size = *IA_size;
	int **new_storage, *new_DA_sizes;

	for (i = 0; i < index_array_size; i++)
	{
		sum += (*DA_sizes)[i];
	}

	if (sum >= 1.5 * index_array_size * DA_size)
	{
		new_storage = initialize_storage(index_array_size * 2, DA_size, &new_DA_sizes);

		fill_new_storage(*storage, index_array_size, *DA_sizes, new_storage, new_DA_sizes);

		for (i = 0; i < index_array_size; i++)
		{
			free((*storage)[i]);
		}

		free(*storage);
		free(*DA_sizes);

		*IA_size = index_array_size * 2;
		*storage = new_storage;
		*DA_sizes = new_DA_sizes;
	}
}

/* transfers all the content in the old storage to the new one using insert2 function. */
void fill_new_storage(int **old_storage, int old_IA_size, int *old_DA_sizes, int **new_storage, int *new_DA_sizes)
{
	int i, j;
	int new_IA_size = 2 * old_IA_size;

	for (i = 0; i < old_IA_size; i++)
	{

		for (j = 0; j < old_DA_sizes[i]; j++)
		{
			insert2(new_storage, new_IA_size, old_storage[i][j], new_DA_sizes);
		}
	}
}

/* inserts given code name into storage, extends corresponding data array if it is full.
   updates data sizes array in case. */
void insert2(int **storage, int IA_size, int name_code, int *DA_sizes)
{
	int i, j, last;
	i = name_code % IA_size;
	last = DA_sizes[i] - 1;

	if (storage[i][last] != 0)
	{
		storage[i] = (int *)realloc(storage[i], DA_sizes[i] * 2);

		for (j = DA_sizes[i]; j < DA_sizes[i] * 2; j++)
		{
			storage[i][j] = 0;
		}
		DA_sizes[i] *= 2;
	}

	for (j = 0; j < DA_sizes[i]; j++)
	{
		if (storage[i][j] != 0)
		{
			continue;
		}
		else
		{
			storage[i][j] = name_code;
			break;
		}
	}
}
