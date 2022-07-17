#ifndef _ALARM_H
#define _ALARM_H

#include "state.h"

//state names
enum{
    AlarmInit,
    AlarmWaitnig,
    Alarm_ON,
    Alarm_OFF
}Alarm_state_id;

//prototypes
State_define(AlarmInit);
State_define(AlarmWaitnig);
State_define(Alarm_OFF);
State_define(Alarm_ON);

//global pointer
 void(*alarm_ptr)();

#endif // _ALARM_H
