#include "CA.h"
#include "DC.h"
#include "US.h"


void setup(){
    US_init();
    DC_init();
    US_state_ptr = State(US_waiting);
    CA_state_ptr = State(CA_waiting);
    DC_state_ptr = State(DC_idle);
}

int main()
{
    setup();
    while(1){

        DC_state_ptr();
        US_state_ptr();
        CA_state_ptr();

        //delay
       int i;
       for(i=0;i<1000000;i++);
    }
}
