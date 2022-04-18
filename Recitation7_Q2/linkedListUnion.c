#include "linkedListUnion.h"
#include <stdlib.h>
#include <stdio.h>


struct Node *createNode(int n)
{
    struct Node *np = NULL;

    np = (struct Node *)malloc(sizeof(struct Node));

    if (np)
    {
        np->value = n;
        np->next = NULL;
    }
    return np;


}

void addNode(struct Node **head, int val)
{
    struct Node *curr = *head;
    struct Node *np = createNode(val);

    if (np)
    {
        if (curr == NULL)
        {
            *head = np;
        }

        else 
        {
            while (curr->next)
            {
                curr = curr->next;
            }

            curr->next = np;
        }
    }
}

void printList(struct Node *head)
{
    if (head)
    {
        printf("%d ", head->value);

        if(head->next)
            printList(head->next);

        else
            printf("\n");
    }
}

int checkValue(struct Node *list, int val)
{
    struct Node *curr = list;
    
    while (curr)
    {
        if (curr->value == val)
            return 1;
        curr = curr->next;
    }

    return 0;
}


struct Node *getUnion(struct Node **list1, struct Node **list2)
{
    struct Node *curr = *list1;
    struct Node *new = NULL;  
    
    while (curr)
    {
        if (!checkValue(new, curr->value))
            addNode(&new, curr->value);
        curr = curr->next;
    }

    curr = *list2;

    while (curr)
    {
        if (!checkValue(new, curr->value))
            addNode(&new, curr->value);
        curr = curr->next;
    }

    return new;
}
