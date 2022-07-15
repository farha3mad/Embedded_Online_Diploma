/*
 *        File: student_system.c
 *      Author: Eng.Farha Emad Mohamed
 *  Created on: 14/7/2022
 *
 */

#include "student_system.h"
//for I/O buffer problem
setvbuf(stdout,NULL,_IONBF,0);
setvbuf(stderr,NULL,_IONBF,0);

FIFO_STATE fifo_init(FIFO_t* fifo, student_data* buffer,unsigned int length){
    //checking the existence
    if(!buffer || !fifo){
        printf("\t[ERROR]Initialization Failed!!!!\n");
        return FIFO_NULL;
    }
    //Initialization
    fifo->Base = buffer;
    fifo->Tail = buffer;
    fifo->Head = buffer;
    fifo->Count = 0;
    fifo->Length = length;

    return FIFO_NO_ERROR;
}

FIFO_STATE fifo_enqueue(FIFO_t* fifo,student_data item){
    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is FULL
    if(fifo->Count == fifo->Length){
        printf("\t[ERROR]Database is FULL\n");
        return FIFO_FULL;
    }
    //inserting
    *(fifo->Head) = item;
    fifo->Count++;

    if(fifo->Head == (fifo->Base + (fifo->Length*sizeof(student_data)))){
       fifo->Head = fifo->Base;
    }else{
       fifo->Head++;
    }
    return FIFO_NO_ERROR;

}

FIFO_STATE check_id(FIFO_t* fifo,unsigned int id){

    //check if the id is already exists
    student_data* ptr = fifo->Base;
    int i;
    //traverse the queue to find the required id
    for(i=0 ; i<fifo->Count ; i++){
        if(ptr++->ID == id){
            return ID_NOT_UNIQE;
        }
    }
    return FIFO_NO_ERROR;
}

FIFO_STATE add_student_manually(FIFO_t* fifo){

    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is FULL
    if(fifo->Count == fifo->Length){
        printf("\t[ERROR]Database is FULL\n");
        return FIFO_FULL;
    }

    student_data student;
    int i;

    //getting student info
    printf("Enter student ID: \n");
    scanf("%d",&student.ID);
    //check if id is not unique
    if(check_id(fifo,student.ID) == ID_NOT_UNIQE){
        printf("\t[ERROR] ID is already taken\n");
        return ID_NOT_UNIQE;
    }
    printf("Enter student first name: \n");
    scanf("%s",&student.First_Name);
    printf("Enter student last name: \n");
    scanf("%s",&student.Last_Name);
    printf("Enter student GPA: \n");
    scanf("%f",&student.GPA);
    for(i=0 ; i<Course_Number ; i++){
       printf("Enter Course%d id: ",i+1);
       scanf("%d",&student.Courses[i]);
    }
    //adding the student info into the queue
    if(fifo_enqueue(fifo,student) == FIFO_NO_ERROR){
        printf("\tStudent(%d) is added successfully\n",student.ID);
        printf("Total number of students = %d\n",fifo->Count);
    }
    return FIFO_NO_ERROR;
}

FIFO_STATE print_all_students(FIFO_t* fifo){

    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is EMPTY
    if(fifo->Count == 0){
        printf("\t[ERROR]Database is Empty\n");
        return FIFO_EMPTY;
    }

    student_data* ptr = fifo->Base;
    int i,j;
    printf("\tStudents Info\n");
    for(i=0 ; i<fifo->Count ; i++){
        printf("=========================================\n");
        printf("Stduent%d ID : %d\n",i+1,ptr->ID);
        printf("Stduent%d first name : %s\n",i+1,ptr->First_Name);
        printf("Stduent%d last name : %s\n",i+1,ptr->Last_Name);
        printf("Stduent%d GPA : %.2f\n",i+1,ptr->GPA);
        printf("Stduent%d Courses:\n",i+1);
        for(j=0 ; j<Course_Number ; j++){
            printf("Course%d ID : %d\n",j+1,ptr->Courses[j]);
        }
        ptr++;

    }
    return FIFO_NO_ERROR;
}

FIFO_STATE add_student_from_file(FIFO_t* fifo){

    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is FULL
    if(fifo->Count == fifo->Length){
        printf("\t[ERROR]Database is FULL\n");
        return FIFO_FULL;
    }
    student_data NewStudent;
    int i,j=1;
    //pointer to the text file
    FILE* student_file = fopen("students.txt","r");
    //check the availability to the file
    if(student_file == NULL){
        printf("\t[ERROR]file can not be opened\n");
        return FIFO_ERROR;
    }
    //loop until the end of the text file or the database to be full
    while(!feof(student_file) && (fifo->Count != fifo->Length))
    {
        //adding the first integer
        fscanf(student_file,"%d",&NewStudent.ID);
        //check if the id is already exists
        if(check_id(fifo,NewStudent.ID) == ID_NOT_UNIQE){
            printf("\t[ERROR] ID is already taken\n");
            //skipping the current line
            fscanf(student_file,"%*[^\n]");
            continue;
        }
        fscanf(student_file,"%s",&NewStudent.First_Name);
        fscanf(student_file,"%s",&NewStudent.Last_Name);
        fscanf(student_file,"%f",&NewStudent.GPA);
        for(i=0 ; i<Course_Number ; i++){
            fscanf(student_file,"%d",&NewStudent.Courses[i]);
        }
        if(fifo_enqueue(fifo,NewStudent) == FIFO_NO_ERROR){
        printf("\tStudent(%d) is added successfully\n",NewStudent.ID);
        }
    }
    //closing the file
    fclose(student_file);
    printf("\nTotal number of students = %d\n",fifo->Count);
    return FIFO_NO_ERROR;
    }

FIFO_STATE find_student_by_id(FIFO_t* fifo){

    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is EMPTY
    if(fifo->Count == 0){
        printf("\t[ERROR]Database is Empty\n");
        return FIFO_EMPTY;
    }
    //pointer to the first element in queue
    student_data* ptr = fifo->Base;

    unsigned int id,i,flag=0;
    //getting the id from user
    printf("Enter the id of the student\n");
    scanf("%d",&id);
    //searching the entire queue for the required id
    for(i=0 ; i<fifo->Count ; i++){
        if(ptr->ID == id){
            flag = 1;
            break;
        }
        ptr++;
    }
    //check if the id exists
    if(flag==1)
    {
        printf("=========================================\n");
        printf("\tStudent with ID = %d Info\n",id);
        printf("First name: %s\n",ptr->First_Name);
        printf("Last name: %s\n",ptr->Last_Name);
        printf("GPA: %.2f\n",ptr->GPA);
        for(i=0 ; i<Course_Number ; i++){
            printf("Course%d id: %d\n",i+1,ptr->Courses[i]);
        }
    }
    else{
        printf("\t[ERROR] Student not found !!!\n");
        return FIFO_ERROR;
    }
    return FIFO_NO_ERROR;
}

FIFO_STATE find_student_by_first_name(FIFO_t* fifo){

    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is FULL
    if(fifo->Count == fifo->Length){
        printf("\t[ERROR]Database is FULL\n");
        return FIFO_FULL;
    }
    //pointer to the first element in queue
    student_data* ptr = fifo->Base;
    char name[20];
    int i, j,flag =0;

    printf("Enter the first name of the student\n");
    scanf("%s",name);

    for(i=0 ; i<fifo->Count ; i++){
        if(*ptr->First_Name == *name){
            flag = 1;
            printf("\tStudent with name: %s Info\n",name);
            printf("=========================================\n");
            printf("ID: %d\n",ptr->ID);
            printf("First name: %s\n",ptr->First_Name);
            printf("Last name: %s\n",ptr->Last_Name);
            printf("GPA: %.2f\n",ptr->GPA);
            for(j=0 ; j<Course_Number ; j++){
                printf("Course%d id: %d\n",j+1,ptr->Courses[j]);
            }

        }
        ptr++;
    }

    if(flag=0){
        printf("\t[ERROR] Student not found !!!\n");
        return FIFO_ERROR;
    }
   return FIFO_NO_ERROR;
}

FIFO_STATE find_students_registered_in_course(FIFO_t* fifo){

    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is EMPTY
    if(fifo->Count == 0){
        printf("\t[ERROR]Database is Empty\n");
        return FIFO_EMPTY;
    }

    unsigned int courseID,i,j,k,count =0;
    printf("Enter course ID:");
    scanf("%d",&courseID);

    student_data* ptr = fifo->Base;
    for(i=0 ; i<fifo->Count ; i++){
        for(j=0 ; j<Course_Number ; j++){
            if(ptr->Courses[j] = courseID){
                count++;
                printf("\tStudent registered in course ID: %d Info\n",courseID);
                printf("ID: %d\n",ptr->ID);
                printf("First name: %s\n",ptr->First_Name);
                printf("Last name: %s\n",ptr->Last_Name);
                printf("GPA: %.2f\n",ptr->GPA);
                for(k=0 ; k<Course_Number ; k++){
                    printf("Course%d id: %d\n",k+1,ptr->Courses[k]);
                }
                printf("\n=========================================\n");
                break;
            }
        }

    ptr++;
    }
    if(count==0){
        printf("[ERROR] No student registered in course ID = %d \n",courseID);
        return FIFO_ERROR;
    }
    else{
        printf("Number of students registered in course%d = %d\n",courseID,count);
    }
    return FIFO_NO_ERROR;
}

FIFO_STATE total_number_of_students(FIFO_t* fifo){

    //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is EMPTY
    if(fifo->Count == 0){
        printf("\t[ERROR]Database is Empty\n");
        return FIFO_EMPTY;
    }

    printf("Total number of students = %d\n",fifo->Count);
    printf("You can still add up to %d student\n",(fifo->Length - fifo->Count));

    return FIFO_NO_ERROR;
}
FIFO_STATE delete_student_by_id(FIFO_t* fifo){
     //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is EMPTY
    if(fifo->Count == 0){
        printf("\t[ERROR]Database is Empty\n");
        return FIFO_EMPTY;
    }
    unsigned int i,j,id,choice=0,flag=0,index=0;
    printf("Enter the student ID: ");
    scanf("%d",&id);
    student_data* ptr = fifo->Base;
    for(i=0 ; i<fifo->Count ; i++){
        if(ptr->ID == id){
            flag = 1;
            printf("\tStudent with ID = %d Info\n",id);
            printf("=========================================\n");
            printf("First name: %s\n",ptr->First_Name);
            printf("Last name: %s\n",ptr->Last_Name);
            printf("GPA: %.2f\n",ptr->GPA);
            for(i=0 ; i<Course_Number ; i++){
                printf("Course%d id: %d\n",i+1,ptr->Courses[i]);
            }
            printf("=========================================\n");
            printf("Are you sure you want to delete student? 1.Yes 2.No\n");
            scanf("%d",&choice);
            if(choice == 1){
                for(j=index ; j<fifo->Count-1 ; j++){
                    buffer[j] = buffer[j+1];
                }
                fifo->Count--;
                fifo->Head--;
                printf("\tDeletion is done successfully\n");
            }
            else if (choice == 2){
                printf("\tDeletion is Canceled\n");
            }
            else{
                printf("[ERROR] Invalid choice!!\n");
            }
            break;
        }
        index++;
        ptr++;
    }
    if(flag == 0){
            printf("[ERROR] Student not found !!!\n");
    }
    return FIFO_NO_ERROR;
}

FIFO_STATE update_student_by_id(FIFO_t* fifo){

     //checking the existence of FIFO
    if(!fifo->Base || !fifo->Head || !fifo->Tail){
        printf("\t[ERROR]Database does not exist\n");
        return FIFO_NULL;
    }
    //check if FIFO is EMPTY
    if(fifo->Count == 0){
        printf("\t[ERROR]Database is Empty\n");
        return FIFO_EMPTY;
    }

    unsigned int id,i,j,choice,info,flag=0;
    char data[50];
    student_data* ptr = fifo->Base;

    printf("Enter the student ID: ");
    scanf("%d",&id);

    for(i=0 ; i<fifo->Count ; i++){
        if(ptr->ID == id){
            flag = 1;
            printf("\tStudent with ID = %d Info\n",id);
            printf("=========================================\n");
            printf("First name: %s\n",ptr->First_Name);
            printf("Last name: %s\n",ptr->Last_Name);
            printf("GPA: %.2f\n",ptr->GPA);
            for(i=0 ; i<Course_Number ; i++){
                printf("Course%d id: %d\n",i+1,ptr->Courses[i]);
            }
            printf("=========================================\n");
            printf("Are you sure you want to update student? 1.Yes 2.No\n");
            scanf("%d",&choice);
            if(choice == 1){
               printf("\n=========================================\n");
                printf("Choose the data you want to update:\n");
                printf("(1)First name\n");
                printf("(2)Last name\n");
                printf("(3)GPA\n");
                printf("(4)Registered Courses\n");
                scanf("%d",&info);
                switch(info){
                    case 1:
                        printf("Enter the new first name: ");
                        scanf("%s",(ptr->First_Name));
                        break;
                    case 2:
                        printf("Enter the new last name: ");
                        scanf("%s",(ptr->Last_Name));
                        break;
                    case 3:
                        printf("Enter the new GPA: ");
                        scanf("%s",data);
                        ptr->GPA = atof(data);
                        break;
                    case 4:
                        printf("Enter the new course id of each courses: \n");
                        for(j=0 ; j<Course_Number ; j++){
                            printf("Enter Course%d id: ",j+1);
                            scanf("%s",data);
                            ptr->Courses[j] = atoi(data);

                        }
                        break;
                    default:
                        break;
                }

                printf("\tUpdated Student with ID = %d Info\n",id);
                printf("First name: %s\n",ptr->First_Name);
                printf("Last name: %s\n",ptr->Last_Name);
                printf("GPA: %.2f\n",ptr->GPA);
                for(j=0 ; j<Course_Number ; j++){
                    printf("Course%d id: %d\n",j+1,ptr->Courses[j]);
                }
            }
            else if (choice == 2){
                printf("\tUpdate is Canceled\n");

            }
            else{
                printf("[ERROR] Invalid choice!!\n");
            }
            break;
    }

    if(flag == 0){
            printf("[ERROR] Student not found !!!\n");
    }

    return FIFO_NO_ERROR;
}
}
