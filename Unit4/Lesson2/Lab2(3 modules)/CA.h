#ifndef _CA_H
#define _CA_H

#include "state.h"
//state names
enum{
    CA_waiting,
    CA_driving
}State_id;

//prototypes
State_define(CA_waiting);
State_define(CA_driving);

//global pointer to function
void(*CA_state_ptr)();

#endif // _CA_H
