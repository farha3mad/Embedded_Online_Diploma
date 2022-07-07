#ifndef _DC_H
#define _DC_H
#include "state.h"

//state names
enum{
    DC_idle,
    DC_busy
}DC_state_id;

//prototypes
void DC_init();
State_define(DC_idle);
State_define(DC_busy);

//global pointer
void(*DC_state_ptr)();

#endif // _DC_H
