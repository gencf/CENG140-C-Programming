/* put your code here */
#include <stdio.h>

int main(){

    float Mon, Tue, Wed, Thu, Fri, avg;
    scanf("%f %f %f %f %f", &Mon, &Tue, &Wed, &Thu, &Fri);
    avg = (Mon + Tue + Wed + Thu + Fri) / 5;

    printf("Celsius on Mon: %.2f\n", (Mon - 32) / 1.8);
    printf("Celsius on Tue: %.2f\n", (Tue - 32) / 1.8);
    printf("Celsius on Wed: %.2f\n", (Wed - 32) / 1.8);
    printf("Celsius on Thu: %.2f\n", (Thu - 32) / 1.8);
    printf("Celsius on Fri: %.2f\n", (Fri - 32) / 1.8);
    printf("Average: %.2f\n", (avg - 32) / 1.8);

    return 0;
}
