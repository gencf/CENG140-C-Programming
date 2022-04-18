#include <stdio.h>
#define CARD_COUNT 100

int main()
{
    int a[3];
    int b[2];
    int i, j, win = 0, difference1, difference2, index, smallest, biggest, card = -1;

    for (i = 0; i < 3; i++){
        scanf(" %d", &a[i]);
    }

    for (j = 0; j < 2; j++){
        scanf(" %d", &b[j]);
    }

    for (i = 0; i < 2; i++){
        difference1 = 100;
        difference2 = 0;
        index = -1;
        smallest = -1;
        biggest = 0;

        for (j = 0; j < 3; j++){

            if (a[j] - b[i] > 0 && a[j] - b[i] < difference1){
                difference1 = a[j] - b[i];
                index = j;
            }

            if (a[j] - b[i] < 0 && a[j] - b[i] < difference2){
                difference2 = a[j] - b[i];
                smallest = j;
            } 

            if (a[j] > biggest){
                biggest = a[j];
            }
                
        }

        if (index >= 0){
            a[index] = 0;
        }

        if (index == -1){
            a[smallest] = 0;
            win = 1;
        }

    }

    if(win == 0)
        printf("WITHDRAW\n");

    if (win == 1){
        card = biggest + 1;
        for (i = 0; i < 3; i++){
            if (card == a[i])
                card++;
        }

        for (j = 0; j < 2; j++){
            if (card == b[j])
                card++;
        }

        if (card > CARD_COUNT)
            printf("WITHDRAW\n");

        else
            printf("%d\n", card);
    }

    return 0;
}