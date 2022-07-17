#include "alarm.h"

void Start_Alarm(){
    //state action
    alarm_ptr = State(Alarm_ON);
}

void Stop_Alarm(){
    //state action
    alarm_ptr = State(Alarm_OFF);
}

State_define(AlarmInit){
    //state action
    Alarm_state_id = AlarmInit;
    //going to the waiting state
    alarm_ptr = State(AlarmWaitnig);
}

State_define(AlarmWaitnig){
    //state action
    Alarm_state_id = AlarmWaitnig;
}

State_define(Alarm_OFF){
    //state action
    Alarm_state_id = Alarm_OFF;
    //turn off the alarm
    Set_Alarm_actuator(1);
    //going to the waiting state
    alarm_ptr = State(AlarmWaitnig);
}

State_define(Alarm_ON){
    //state action
    Alarm_state_id = Alarm_ON;
    //turn on the alarm
    Set_Alarm_actuator(0);
    //going to the waiting state
    alarm_ptr = State(AlarmWaitnig);
}
