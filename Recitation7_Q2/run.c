#include <stdio.h>
#include <stdlib.h>
#include "linkedListUnion.h"

int main(){
    
    /* Do not change */
 
    struct Node *list1;
    struct Node *list2;
    struct Node *result;


    list1=list2=result=NULL;
    
    addNode(&list1,10);   
    addNode(&list1,20);
    addNode(&list1,30);	
    addNode(&list2,20);
    addNode(&list2,40);
    
    printList(list1);
    printList(list2);

    result=getUnion(&list1,&list2);
    
    printList(list1);
    printList(list2);
    printList(result);
    
    return 0;
}