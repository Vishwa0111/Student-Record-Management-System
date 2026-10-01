#include "student.h"

int main()
{
    SLL *headptr = 0;
    char op, ch;

    stud_load(&headptr);

    while (1)
    {
        printf("\n*** STUDENT RECORD MENU ***\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");
        printf("Enter your choice: ");

        scanf(" %c", &op);

        switch (op)
        {
            case 'a':
            case 'A':
                stud_add(&headptr);
                break;

            case 'd':
            case 'D':
                stud_del(&headptr);
                break;

            case 's':
            case 'S':
                stud_show(headptr);
                break;

            case 'm':
            case 'M':
                stud_mod(headptr);
                break;

            case 'v':
            case 'V':
                stud_save(headptr);
                break;

            case 'e':
            case 'E':
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter choice: ");
                scanf(" %c", &ch);

                if (ch == 's' || ch == 'S')
                {
                    stud_save(headptr);
                    stud_del_all(&headptr);
                    exit(0);
                }
                else if (ch == 'e' || ch == 'E')
                {
                    stud_del_all(&headptr);
                    exit(0);
                }
                else
                {
                    printf("Invalid choice\n");
                }
                break;

            case 't':
            case 'T':
                stud_sort(&headptr);
                break;

            case 'l':
            case 'L':
                stud_del_all(&headptr);
                printf("All records deleted\n");
                break;

            case 'r':
            case 'R':
                stud_reverse(&headptr);
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
