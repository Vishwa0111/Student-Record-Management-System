#include "student.h"

void stud_show(SLL *ptr)
{
    if (ptr == 0)
    {
        printf("No student records available\n");
        return;
    }

    printf("Roll No.\tName\tPercentage\n");
    while (ptr)
    {
        printf("%d\t\t%s\t%.2f\n", ptr->rollno, ptr->name, ptr->percentage);
        ptr = ptr->next;
    }
}
