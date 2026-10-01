#include "student.h"

static int countNode(SLL *ptr)
{
    int c = 0;
    while (ptr)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}

void stud_sort(SLL **ptr)
{
    if (*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    char op;
    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &op);

    if (op != 'n' && op != 'N' && op != 'p' && op != 'P')
    {
        printf("Invalid choice\n");
        return;
    }

    int c = countNode(*ptr);
    int i, j;
    SLL *p1, *p2;
    SLL t;

    p1 = *ptr;
    for (i = 0; i < c - 1; i++)
    {
        p2 = p1->next;
        for (j = 0; j < c - 1 - i; j++)
        {
            int swap = 0;
            if ((op == 'n' || op == 'N') && strcmp(p1->name, p2->name) > 0)
                swap = 1;
            else if ((op == 'p' || op == 'P') && (p1->percentage < p2->percentage))
                swap = 1;

            if (swap)
            {
                t.rollno = p1->rollno;
                strcpy(t.name, p1->name);
                t.percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = t.rollno;
                strcpy(p2->name, t.name);
                p2->percentage = t.percentage;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    printf("List sorted successfully\n");
}

void stud_reverse(SLL **ptr)
{
    if (*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    SLL *prev = 0, *cur = *ptr, *nxt = 0;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *ptr = prev;
    printf("List reversed successfully\n");
}
