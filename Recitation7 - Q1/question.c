#include <stdlib.h>
#include <stdio.h>
#include "question.h"

void set_age(struct Person* p, int new_age){
    p -> age = new_age;
}
void print_info(struct Person* p){
    printf("%c\n%d\n", p->initial, p->age);
}
