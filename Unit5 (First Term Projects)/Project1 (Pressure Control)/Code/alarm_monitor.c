#include "alarm_monitor.h"

State_define(AlarmMonitorIdle){
    //state action
    Alarm_monitor_state_id = AlarmMonitorIdle;
    //sending to the alarm actuator to stop alarming
    Stop_Alarm();
    //check if there is high pressure
    if(highP() == 1){
        alarm_monitor_ptr = State(AlarmMonitorAlarming);
    }
}

State_define(AlarmMonitorAlarming){
    //state action
    Alarm_monitor_state_id = AlarmMonitorAlarming;
    //sending to the alarm actuator to start alarming
    Start_Alarm();
    //going to the waiting state
    alarm_monitor_ptr = State(AlarmMonitorWaiting);
}

State_define(AlarmMonitorWaiting){
    //state action
    Alarm_monitor_state_id = AlarmMonitorWaiting;
     //Timer
    Delay(100000);
    //going to the idle state
    alarm_monitor_ptr = State(AlarmMonitorIdle);
}

