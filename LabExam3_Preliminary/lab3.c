#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"
#define MAX_FOLLOW_COUNT 10
#define MAX_PROFILE_COUNT 20

/*
    DO NOT TOUCH THIS LINE.
    DO NOT ATTEMPT TO MODIFY YOUR OWN allProfiles.
    Just use the variable "allProfiles" as you wish.
*/
extern struct Profile *allProfiles[MAX_PROFILE_COUNT];

void createProfile(int userId)
{
    struct Profile *p = (struct Profile *)malloc(sizeof(struct Profile));
    int i, j;
    p->userId = userId;

    for (i = 0; i < MAX_FOLLOW_COUNT; i++)
    {
        (p->followed)[i] = NULL;
    }

    for (j = 0; j < MAX_PROFILE_COUNT; j++)
    {
        if (allProfiles[j] == NULL)
        {
            allProfiles[j] = p;
            break;
        }
    }
}

void follow(int followerId, int followedId)
{
    int i, flag = 1;
    struct Profile *followerPtr = NULL;
    struct Profile *followedPtr = NULL;


    if (followerId != followedId)
    {
        for (i = 0; i < MAX_PROFILE_COUNT && allProfiles[i]; i++)
        {
            if (allProfiles[i]->userId == followerId)
            {
                followerPtr = allProfiles[i];
            }

            else if (allProfiles[i]->userId == followedId)
            {
                followedPtr = allProfiles[i];
            }
        }

        if (followerPtr && followedPtr)
        {
            for (i = 0; i < MAX_FOLLOW_COUNT; i++)
            {
                if (followerPtr->followed[i] == followedPtr)
                {
                    flag = 0;
                    break;
                }
            }

            for (i = 0; i < MAX_FOLLOW_COUNT && flag == 1; i++)
            {
                if (followerPtr->followed[i] == NULL)
                {
                    followerPtr->followed[i] = followedPtr;
                    break;
                }
            }
        }        
    }

}

void printList(struct Node *head)
{
    struct Node *curr = head;

    if(curr == NULL)
        printf("\n");

    else
    {
        if (curr->next)
            printf("%d -> ", curr->data);
        else
            printf("%d", curr->data);

        printList(curr->next);
    }  
}

void insertEnd(struct Node **headRef, int data)
{
    struct Node *np = (struct Node*)malloc(sizeof(struct Node));
    struct Node *curr = *headRef;
    np->data = data;
    np->next = NULL;

    if(curr == NULL)
        *headRef = np;

    else
    {
        while(curr->next)
        {      
            curr = curr->next;               
        }

        curr->next = np;
    }
}

int occurences(struct Node **headRef, int element)
{
    int count = 0;
    struct Node *curr = *headRef;

    while (curr)
    {
        if(curr->data == element)
            count++;
            
        curr = curr->next;
    }

    return count;
}