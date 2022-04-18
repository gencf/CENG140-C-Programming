#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

int main()
{
    int i;
    float* mean_vector;
    int** matrix = (int**) malloc(sizeof(int*) * 4);

    for (i = 0; i < 4; i++)
    {
        matrix[i] = (int*) malloc(sizeof(int) * 4);
        matrix[i][0] = (i+1)*1;
        matrix[i][1] = (i+1)*2;
        matrix[i][2] = (i+1)*3;
        matrix[i][3] = (i+1)*4;
    }
    
    print_matrix(matrix, 4, 4);
    is_symmetric(matrix, 4);
    mean_vector = mean(matrix, 4, 4, 0);
    print_vector(mean_vector, 4);
    mean_vector = mean(matrix, 4, 4, 1);
    print_vector(mean_vector, 4);
    
    return 0;
}