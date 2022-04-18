#include <stdio.h>

int main(){
    char direction;
    int x, y, n;

    scanf("%c %d %d %d", &direction, &x, &y, &n);

    if (direction == 'E'){
        if (x+1 < n) 
            x++;
    }

    if (direction == 'W'){
        if (x-1 > 0) 
            x--;
    }
 
    if (direction == 'N'){
        if (y-1 > 0) 
            y--;
    }    

    if (direction == 'S'){
        if (y+1 < n) 
            y++;
    }
    printf("%d %d", x, y);

    return 0;
}