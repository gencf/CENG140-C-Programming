#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

/* Takes matrix and size of the matrix and returns whether given matrix is symmetric or not */
void is_symmetric(int** matrix, int size){
    int i, j;
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            if (matrix[i][j] != matrix[j][i]){
                printf("Not symmetric\n");
                return;
            }

    printf("Symmetric\n");

}

/* Takes matrix and sizes of the matrix and returns mean of the matrix in the given axis direction */
float* mean(int** matrix, int size_x, int size_y, int axis){
    int i, j;
    float sum, *average;

    if(axis == 0)
        average = malloc(size_y * sizeof(int));       
    if(axis == 1)
        average = malloc(size_x * sizeof(int));    

    if(axis == 0){
        for (i = 0; i < size_y; i++){
            sum = 0;
            for (j = 0; j < size_x; j++)
                sum += matrix[j][i];
            average[i] = sum / size_x;
        }
    }

    if(axis == 1){
        for (i = 0; i < size_x; i++){
            sum = 0;
            for (j = 0; j < size_y; j++)
                sum += matrix[i][j];
            average[i] = sum / size_y;
        }
    }
    
    return average;
}

/* Takes matrix and sizes of the matrix prints the content of the matrix */
void print_matrix(int** matrix, int size_x, int size_y){
    int i, j;
    for(i = 0; i < size_x; i++){
        for(j = 0; j < size_y; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

}

/* Takes a float vector and prints the content of the vector */
void print_vector(float* vector, int size){
    int i;
    printf("[");
    for(i = 0; i < size; i++)
        printf("%.2f ", vector[i]);  
    printf("]\n");
}