#ifndef _US_H
#define _US_H
#include <math.h>
#include "state.h"

//state names
enum{
    US_waiting
}US_state_id;

//prototypes
void US_init();
State_define(US_waiting);

//global pointer
void(*US_state_ptr)();

#endif
