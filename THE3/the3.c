#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "the3.h"

/*
Create a student array
*/
Student *create_students(int ids[], int remaining_credits[], char *names[], int student_count)
{
    Student *students = (Student *)malloc(student_count * sizeof(Student));
    int i;

    for (i = 0; i < student_count; i++)
    {
        students[i].id = ids[i];
        students[i].name = names[i];
        students[i].remaining_credit = remaining_credits[i];
    }

    return students;
}

/*
Create a course array
*/
Course *create_courses(int ids[], int capacities[], int course_count)
{
    Course *courses = (Course *)malloc(course_count * sizeof(Course));
    int i;

    for (i = 0; i < course_count; i++)
    {
        courses[i].id = ids[i];
        courses[i].capacity = capacities[i];
        courses[i].requests = NULL;
    }

    return courses;
}

/*
Appends a bid to a linked list of bids ordered by bids descendingly.
*/
void append(Request **requests, Student *student, int bid)
{
    Request *curr = *requests;
    Request *prev = NULL;
    Request *new = (Request *)malloc(sizeof(Request));

    new->student = student;
    new->bid = bid;
    new->next = NULL;

    if (curr == NULL)
    {
        *requests = new;
        student->remaining_credit -= bid;
    }

    else
    {
        while (curr && bid <= curr->bid)
        {
            prev = curr;
            curr = curr->next;
        }

        if (prev)
        {
            prev->next = new;
        }

        else
        {
            *requests = new;
        }

        new->next = curr;
        student->remaining_credit -= bid;
    }
}

/*
Add news bid to the course. If student do not have enough bid, do not update course candidate student list.
*/
void new_request(char *student_name, int course_id, int bid, Student *students, Course *courses, int student_count, int course_count)
{
    int i, student, course;
    Request *curr = NULL;
    Request *prev = NULL;

    for (i = 0; i < student_count; i++)
    {
        if (strcmp(students[i].name, student_name) == 0)
        {
            student = i;
            break;
        }
    }

    for (i = 0; i < course_count; i++)
    {
        if (courses[i].id == course_id)
        {
            course = i;
            break;
        }
    }

    curr = courses[course].requests;

    while (curr)
    {
        if (curr->student->id == students[student].id)
        {
            if (prev)
            {
                prev->next = curr->next;
            }

            else
            {
                courses[course].requests = curr->next;
            }

            students[student].remaining_credit += curr->bid;
            free(curr);
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    if (bid <= students[student].remaining_credit)
    {
        append(&courses[course].requests, &students[student], bid);
        printf("%s is added to enrollment list of Course %d. Remaining credit: %d\n",
            students[student].name, courses[course].id, students[student].remaining_credit);
    }

    else
    {
        printf("%s does not have enough credit to enroll Course %d.\n",
            students[student].name, courses[course].id);
    }
}

/*
Prints accepted student list for the course.
*/
void print_course_requests(Course *courses, int course_count, int stop_at_capacity)
{
    Request *curr;
    int i, capacity, count;

    for (i = 0; i < course_count; i++)
    {
        printf("Course: %d\n", courses[i].id);
        capacity = courses[i].capacity;
        curr = courses[i].requests;
        count = 0;

        if (curr == NULL)
        {
            printf("Student List: No students\n");
        }

        else
        {
            printf("Student List: ");

            while (curr)
            {
                if (count == capacity - 1 && stop_at_capacity)
                {
                    printf("%s(%d)\n", curr->student->name, curr->bid);
                    break;
                }

                else if (curr->next)
                {    
                    printf("%s(%d) ", curr->student->name, curr->bid);
                }

                else
                {
                    printf("%s(%d)\n", curr->student->name, curr->bid);
                }

                curr = curr->next;
                count++;
            }
        }
    }
}