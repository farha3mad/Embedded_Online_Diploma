#include "DC.h"
//variables
unsigned int DC_speed=0;

void DC_init(){
    //initialization
    printf("\tDC motor init\n");

}
State_define(DC_idle){
    //state name
    DC_state_id = DC_idle;
    //stay in the same state
    DC_state_ptr = State(DC_idle);
    printf("DC motor in idle state speed = %d\n",DC_speed);

}

State_define(DC_busy){
    //state name
    DC_state_id = DC_busy;
    //automatic transition to the idle state
    DC_state_ptr = State(DC_idle);
    printf("DC motor in busy state speed = %d\n",DC_speed);

}

void DC_set_speed(int s){
    //receiving the speed value from CA module
    DC_speed = s;
    //moving to busy state
    DC_state_ptr = State(DC_busy);
    printf("CA--------speed = %d---------DC\n",DC_speed);
}

