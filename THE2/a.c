#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **storage, **data_array_sizes;
	int i, IA_size = 6, DA_size = 3;

	printf("IA_size: %d DA_size: %d\n", IA_size, DA_size);

	storage = (int **)calloc(IA_size, sizeof(int));
	*data_array_sizes = (int *)malloc(IA_size * sizeof(int));	
    printf("in\n");

	for (i = 0; i < IA_size; i++)
		printf("%d %d\n", IA_size, (*data_array_sizes)[i]);
	

	for (i = 0; i < IA_size; i++)
	{
		storage[i] = (int *)calloc(DA_size, sizeof(int));
	}

    for (i = 0; i < IA_size; i++)
	{
		(*data_array_sizes)[i] = DA_size;
	}

	for (i = 0; i < IA_size; i++)
	{
	    printf("data_array_sizes: %d\n", (*data_array_sizes)[i]);
		printf("storage: %p\n", storage[i]);
	}
}