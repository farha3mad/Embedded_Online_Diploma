#include "US.h"
//variables
unsigned int US_distance=0;

void US_init(){
    //initialization
    printf("\tUltrasonic init\n");
}

State_define(US_waiting)
{
    //state name
    US_state_id = US_waiting;
    //get distance value
    US_distance = Random_value(45,55,1);
    //setting distance value
    US_set_distance(US_distance);
    printf("Distance= %d \n",US_distance);
    //stay in the same state
    US_state_ptr = State(US_waiting);
}

int Random_value(int low, int high, int count){
    int i;
    for(i=0 ; i<count ; i++)
    {
        int random_num = (rand()%(high - low +1))+low;
        return random_num;
    }
}
