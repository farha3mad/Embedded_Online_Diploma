#ifndef _ALGO_H
#define _ALGO_H

#include "state.h"

//state names
enum{
    High_pressure_detection
}Algo_state_id;

//prototypes
State_define(High_pressure_detection);

//global pointer
 void(*algo_ptr)();

#endif // _ALGO_H
