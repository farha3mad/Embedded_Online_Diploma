#ifndef _ALARM_MONITOR_H
#define _ALARM_MONITOR_H

#include "state.h"

//state names
enum{
    AlarmMonitorIdle,
    AlarmMonitorAlarming,
    AlarmMonitorWaiting
}Alarm_monitor_state_id;

//prototypes
State_define(AlarmMonitorIdle);
State_define(AlarmMonitorAlarming);
State_define(AlarmMonitorWaiting);

//global pointer
void(*alarm_monitor_ptr)();

#endif // _ALARM_MONITOR_H

