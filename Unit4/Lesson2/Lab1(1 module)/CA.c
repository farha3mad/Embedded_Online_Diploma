#include "CA.h"
#include "math.h"
//variables
unsigned int speed,distance,threshold=50;

State_define(CA_waiting){
    //state action
    State_id = CA_waiting;
    speed=0;
    distance = Random_value(45,55,1);

    //event check
    (distance<=threshold)? (state_ptr = State(CA_waiting)) : (state_ptr = State(CA_driving));
    printf("Distance= %d \t Speed= %d \n",distance,speed);

}

State_define(CA_driving){
    //state action
    State_id = CA_driving;
    speed=30;
    distance = Random_value(45,55,1);

    //event check
    (distance<=threshold)? (state_ptr = State(CA_waiting)) : (state_ptr = State(CA_driving));
    printf("Distance= %d \t Speed= %d \n",distance,speed);

}

int Random_value(int low, int high, int count){
    int i;
    for(i=0 ; i<count ; i++)
    {
        int random_num = (rand()%(high - low +1))+low;
        return random_num;
    }
}
