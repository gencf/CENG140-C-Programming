#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int xcoors[10];
    int ycoors[10];
    int x, y, index;
    float dist, min;
    /* declare your variables */

    for (i = 0; i < 10; i++)
    {
        scanf("%d ", &xcoors[i]);
    }

    for (i = 0; i < 10; i++)
    {
        scanf("%d ", &ycoors[i]);
    }

    scanf("%d %d", &x, &y);

    min = sqrt(pow(x - xcoors[0], 2) + pow(y - ycoors[0], 2));

    for (i = 1; i < 10; i++)
    {
        dist = sqrt(pow(x - xcoors[i], 2) + pow(y - ycoors[i], 2));
        if (dist < min)
        {
            min = dist;
            index = i;
        }
    }

    printf("P = (%d,%d), nearest point index = %d, distance = %.1f", x, y, index, min);

    return 0;
}