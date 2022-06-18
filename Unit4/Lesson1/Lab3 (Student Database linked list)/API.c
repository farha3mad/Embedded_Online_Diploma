#include "header.h"
//pointer to the first node
struct Student* first_student = NULL;
/***Add students***/
List_status Add_new_student()
{
    setvbuf(stdout,NULL,_IONBF,0);
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student)); //creating new student node

    if(new_student == NULL) //check if the node created in the memory
    {
       printf("========Failed to add new student========");
       return list_full;
    }

    if(first_student == NULL) //Check if list is empty
    {
        first_student = new_student;
    }
    else
    {
        struct Student* last_student = first_student; //pointer to navegate the list
        while(last_student->next_student != NULL)
            last_student = last_student->next_student;

        last_student->next_student = new_student;

    }

    new_student->next_student =NULL; //make last node points to null
    //Adding new student data
    printf("Enter Student ID: \n");
    scanf("%d",&new_student->data.id);

    printf("Enter Student full name: \n");
    scanf("%s",new_student->data.name);

    printf("Enter Student height: \n");
    scanf("%f",&new_student->data.height);

    printf("\n===============================\n");
    return No_error;
}
/***Delete Student***/
List_status Delete_student()
{
    setvbuf(stdout,NULL,_IONBF,0);
     if(first_student == NULL) //Check if list is empty
    {
        printf("\n========List is Empty========\n");
        return List_empty;
    }
    unsigned int ID;
    printf("Enter The id of the student: \n");
    scanf("%d",&ID);

    struct Student* deleted_student = first_student;
    struct Student* previous_student = first_student;
    while(deleted_student) //traverse the list
    {
        if(deleted_student->data.id == ID)
        {
             if(deleted_student == first_student) //first node
            {
                first_student = NULL;
                free(deleted_student);
                break;
            }
            else
            {
                previous_student->next_student = deleted_student->next_student;
                free(deleted_student);
            }
            return No_error;
        }
        previous_student = deleted_student;
        deleted_student = deleted_student->next_student;
    }
        printf("\n========Student can not found========\n");
        return Not_found;
}
/***Print the list***/
void Print_students()
{
    if(first_student == NULL) //Check if list is empty
        printf("\n========List is Empty========\n");
    else
    {
        printf("========Students info========\n");
        unsigned int i=1;
        struct Student* temp = first_student;
        while(temp != NULL)
        {
            printf("Record %d:\n",i);
            printf("\tID = %d\n",temp->data.id);
            printf("\tNAME = %s\n",temp->data.name);
            printf("\tHEIGHT = %.2f\n",temp->data.height);
            temp = temp->next_student;
            i++;
        }
        printf("===========================\n");
    }
}
/***delete the list***/
void Delete_All()
{
    if(first_student == NULL) //Check if list is empty
        printf("\n========List is Empty========\n");
    else
    {
        struct Student* current = first_student;
        struct Student* temp;
        while(current != NULL)
        {
            temp = current;
            current = current->next_student;
            free(temp);
        }
       first_student = NULL;
    }
}
/***Get element by index***/
List_status Get_Nth_student()
{
    setvbuf(stdout,NULL,_IONBF,0);
    if(first_student == NULL) //Check if list is empty
        printf("\n========List is Empty========\n");
    else
    {
        unsigned count =0;
        unsigned int index;
        struct Student* current = first_student;
        printf("Enter the index: \n");
        scanf("%d",&index);

        while(current)
        {
            if(count == index)
            {
                printf("========Student index %d info========\n",count);
                printf("\tID = %d\n",current->data.id);
                printf("\tNAME = %s\n",current->data.name);
                printf("\tHEIGHT = %.2f\n",current->data.height);
                printf("===========================\n");
                return No_error;
            }
            else
            {
               count++;
               current = current->next_student;
            }
        }
    }

    return Not_found;
}
/***get length of list***/
void Get_Length()
{
    if(first_student == NULL) //Check if list is empty
        printf("\n========List is Empty========\n");
    else
    {
        unsigned int count=0;
        struct Student* temp = first_student;
        while(temp)
        {
            count++;
            temp = temp->next_student;
        }
        printf("Number of students = %d\n",count);
    }
}
/***Get element by index backwards***/
List_status Get_Nth_student_backward()
{
    setvbuf(stdout,NULL,_IONBF,0);
     if(first_student == NULL) //Check if list is empty
        printf("\n========List is Empty========\n");
    else
    {
        unsigned count=0;
        struct Student* fast = first_student;
        struct Student* slow = first_student;
        unsigned int index;
        printf("Enter the index number: \n");
        scanf("%d",&index);
        while(index)
        {
            if(fast = fast->next_student);
            else
            {
               printf("\n========Index Not Found========\n");
               return Not_found;
            }

            index--;
            count++;
        }
        while(fast)
        {
            slow = slow->next_student;
            fast = fast->next_student;
        }
        printf("\n========Student backward number %d info========\n",count);
                printf("\tID = %d\n",slow->data.id);
                printf("\tNAME = %s\n",slow->data.name);
                printf("\tHEIGHT = %.2f\n",slow->data.height);
                printf("===========================\n");
    }

   return No_error;
}
/***find the middle of the list***/
void Find_middle()
{
    if(first_student == NULL) //Check if list is empty
        printf("\n========List is Empty========\n");
    else if(first_student->next_student == NULL)
    {
        printf("\n========List has only one student========\n");
    }
    else
    {
        struct Student* fast = first_student;
        struct Student* slow = first_student;
        while(fast->next_student)
        {
            fast = fast->next_student;
            slow = slow->next_student;
            if(fast = fast->next_student);
            else
                break;
        }
        printf("\n========Middle Student info========\n");
                printf("\tID = %d\n",slow->data.id);
                printf("\tNAME = %s\n",slow->data.name);
                printf("\tHEIGHT = %.2f\n",slow->data.height);
                printf("\n===========================\n");
    }
}
/***reversing list elements***/
void reverse_list()
{
    if(first_student == NULL) //Check if list is empty
        printf("\n========List is Empty========\n");
    else if(first_student->next_student == NULL)
    {
        printf("\n========List has only one student========\n");
    }
    else
    {
        struct Student* fast = first_student;
        struct Student* slow = NULL;
        struct Student* current = first_student;
        while(fast)
        {
            fast = current->next_student;
            current->next_student=slow;
            slow=current;
            current= fast;
        }
        first_student=slow;

    }
}
