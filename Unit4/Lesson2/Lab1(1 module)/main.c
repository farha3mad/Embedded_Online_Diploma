#include <stdio.h>
#include <stdlib.h>
#include "CA.h"

void setup(){
    //initial state
    state_ptr = State(CA_waiting);
}

int main()
{
    setup();
    while(1){
       state_ptr();
       //delay
       int i;
       for(i=0;i<1000000;i++);
    }
}
