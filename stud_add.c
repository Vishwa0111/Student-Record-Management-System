#include "student.h"

void stud_add(SLL **ptr)
{
    SLL *new, *last, *t;
    int r = 1;

    new = malloc(sizeof(SLL));

    while (1)
    {
        t = *ptr;
        while (t)
        {
            if (t->rollno == r)
                break;
            t = t->next;
        }
        if (t == 0)
            break;
        r++;
    }
    new->rollno = r;

    printf("Allocated Roll No: %d\n", new->rollno);
    printf("Enter name: ");
    scanf("%s", new->name);

    while (1)
    {
        printf("Enter percentage: ");
        scanf("%f", &new->percentage);
        if (new->percentage >= 0.0f && new->percentage <= 100.0f)
            break;
        printf("Invalid percentage\n");
    }

    new->next = 0;

    if (*ptr == 0)
    {
        *ptr = new;
    }
    else
    {
        last = *ptr;
        while (last->next)
            last = last->next;
        last->next = new;
    }
}
