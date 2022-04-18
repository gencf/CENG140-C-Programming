#include "pointerUpdate.h"

void update(int * arr[], int length){
    int i;
    int *temp[100];

    for(i = 0; i < length; i++)
        temp[i] = arr[i];

    for(i = 0; i < length; i++)
        arr[i] = temp[*temp[i] % length];   
}