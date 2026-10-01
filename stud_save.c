#include "student.h"

void stud_save(SLL *ptr)
{
    if (ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    FILE *fp;
    fp = fopen("student.dat", "w");

    while (ptr)
    {
        fprintf(fp, "%d %s %f\n", ptr->rollno, ptr->name, ptr->percentage);
        ptr = ptr->next;
    }

    printf("Data saved in file\n");
    fclose(fp);
}

void stud_load(SLL **ptr)
{
    FILE *fp;
    fp = fopen("student.dat", "r");
    if (fp == 0)
        return;

    SLL *new, *last;
    while (1)
    {
        new = malloc(sizeof(SLL));
        if (fscanf(fp, "%d %s %f", &new->rollno, new->name, &new->percentage) == -1)
        {
            free(new);
            break;
        }

        new->next = 0;
        if (*ptr == 0)
            *ptr = new;
        else
        {
            last = *ptr;
            while (last->next)
                last = last->next;
            last->next = new;
        }
    }
    fclose(fp);
}
