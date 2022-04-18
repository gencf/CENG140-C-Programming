#ifndef __LAB3_H__
#define __LAB3_H__
#define MAX_FOLLOW_COUNT 10
#define MAX_PROFILE_COUNT 20

struct Profile
{
    int userId;
    struct Profile *followed[MAX_FOLLOW_COUNT];
};

struct Node
{
    int data;
    struct Node *next;
};

void createProfile(int userId);
void follow(int followerId, int followedId);

void printList(struct Node *head);
void insertEnd(struct Node **headRef, int data);
int occurences(struct Node **headRef, int element);

#endif