#include "header.h"

int main()
{
    setvbuf(stdout,NULL,_IONBF,0);
    unsigned int choice;
    while(1)
    {
        printf("Choose one of the following options\n\n");
        printf("(1)Add new student\n");
        printf("(2)Delete student\n");
        printf("(3)Delete all students\n");
        printf("(4)View students\n");
        printf("(5)Get the Nth student\n");
        printf("(6)Get the Nth student backward\n");
        printf("(7)Get the number students\n");
        printf("(8)Get the middle student in the list\n");
        printf("(9)Reverse List\n");
        printf("Enter option number:");

        scanf("%d",&choice);
        printf("\n=============================\n");

        switch(choice)
        {
            case 1:
                if(Add_new_student()== No_error);
                break;
            case 2:
                if(Delete_student() == No_error);
                break;
            case 3:
                Delete_All();
                break;
            case 4:
                Print_students();
                break;
            case 5:
                if(Get_Nth_student() == No_error);
                break;
            case 6:
                if(Get_Nth_student_backward() == No_error);
                break;
            case 7:
                Get_Length();
                break;
            case 8:
                Find_middle();
                break;
            case 9:
                reverse_list();
                break;
            default:
                break;
        }

    }
}
