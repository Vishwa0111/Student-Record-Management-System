#include "student.h"

void stud_del_all(SLL **ptr)
{
    if (*ptr == 0)
        return;

    SLL *del = *ptr;
    while (del)
    {
        *ptr = del->next;
        free(del);
        del = *ptr;
    }
}

void stud_del(SLL **ptr)
{
    if (*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    char op;
    printf("R/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    printf("Enter choice: ");
    scanf(" %c", &op);

    int r = 0;

    if (op == 'r' || op == 'R')
    {
        printf("Enter roll number: ");
        scanf("%d", &r);
    }
    else if (op == 'n' || op == 'N')
    {
        char sname[50];
        printf("Enter name: ");
        scanf("%s", sname);

        int count = 0;
        SLL *t = *ptr;

        printf("\nMatching Records:\n");
        while (t)
        {
            if (strcmp(t->name, sname) == 0)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n", t->rollno, t->name, t->percentage);
                count++;
                r = t->rollno;
            }
            t = t->next;
        }

        if (count == 0)
        {
            printf("Name not found\n");
            return;
        }
        else if (count > 1)
        {
            printf("Enter roll number to delete: ");
            scanf("%d", &r);
        }
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    SLL *del = *ptr, *prev = 0;
    while (del)
    {
        if (del->rollno == r)
        {
            if (del == *ptr)
                *ptr = del->next;
            else
                prev->next = del->next;

            free(del);
            printf("Record deleted successfully\n");
            return;
        }
        prev = del;
        del = del->next;
    }
    printf("Roll number not found\n");
}
