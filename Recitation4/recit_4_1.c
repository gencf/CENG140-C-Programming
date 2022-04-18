#include <stdio.h>

int gcd(int a, int b){
    printf("gcd %d %d\n", a, b);
    if(a % b == 0){
        return b;
    }
    else if (a > b)
        return (gcd(b, a%b));
    else
        return (gcd(a, b%a));
}

double power_handler(int base, int exponent, int step){
    double result = 1;
    if (exponent == 0)
        return 1;
    printf("calculate: %d^%d call: %d\n", base, exponent, step);
    if (exponent % 2 == 0){
        result = power_handler(base, exponent/2, ++step);
        result *= result;    
    }    
    else
        result = base * power_handler(base, exponent-1, ++step);
    return result;  
}

double power(int base, int exponent){
    int step = 1;
    if (exponent == 0){
        printf("calculate: %d^%d call: %d\n", base, exponent, step);
        return 1;
    }
    return power_handler(base, exponent, step);
}


int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    // printf("%d", gcd(a,b));
    printf("%f", power(a,b));
    return 0;
}

