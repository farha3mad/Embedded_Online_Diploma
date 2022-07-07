#include "CA.h"

//variables
unsigned int CA_speed=0,CA_distance=0,CA_threshold=50;

State_define(CA_waiting){
    //state name
    State_id = CA_waiting;
    //sending the speed to DC motor module
    CA_speed=0;
    DC_set_speed(CA_speed);

    printf("Waiting state : Distance= %d \t Speed= %d \n",CA_distance,CA_speed);

}

State_define(CA_driving){
    //state name
    State_id = CA_driving;
    //sending the speed to DC motor module
    CA_speed=30;
    DC_set_speed(CA_speed);

    printf("Driving state : Distance= %d \t Speed= %d \n",CA_distance,CA_speed);

}

void US_set_distance(int d){
    //receiving the distance value from US sensor
    CA_distance=d;
    //state checking
    (CA_distance<=CA_threshold)? (CA_state_ptr = State(CA_waiting)) : (CA_state_ptr = State(CA_driving));
    printf("US--------distance = %d---------CA\n",CA_distance);
}
