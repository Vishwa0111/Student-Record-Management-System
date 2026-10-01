#include "student.h"

void stud_mod(SLL *ptr)
{
    if (ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    char op;
    printf("Enter which record to search for modification:\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
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
        SLL *t = ptr;

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
            printf("Record not found\n");
            return;
        }
        else if (count > 1)
        {
            printf("Multiple records found. Enter roll number to modify: ");
            scanf("%d", &r);
        }
    }
    else if (op == 'p' || op == 'P')
    {
        float sper;
        printf("Enter percentage: ");
        scanf("%f", &sper);

        int count = 0;
        SLL *t = ptr;

        printf("\nMatching Records:\n");
        while (t)
        {
            if (t->percentage == sper)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n", t->rollno, t->name, t->percentage);
                count++;
                r = t->rollno;
            }
            t = t->next;
        }

        if (count == 0)
        {
            printf("Record not found\n");
            return;
        }
        else if (count > 1)
        {
            printf("Multiple records found. Enter roll number to modify: ");
            scanf("%d", &r);
        }
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    while (ptr)
    {
        if (ptr->rollno == r)
        {
            printf("Current details: Roll No: %d, Name: %s, Percentage: %.2f\n", ptr->rollno, ptr->name, ptr->percentage);
            printf("Enter updated name: ");
            scanf("%s", ptr->name);

            while (1)
            {
                printf("Enter updated percentage: ");
                scanf("%f", &ptr->percentage);
                if (ptr->percentage >= 0.0f && ptr->percentage <= 100.0f)
                    break;
                printf("Invalid percentage\n");
            }
            printf("Record updated successfully\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Record not found\n");
}
