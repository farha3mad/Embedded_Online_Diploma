#ifndef _SENSOR_H
#define _SENSOR_H
#include "state.h"

//state names
enum{
    SensorInit,
    SensorReading,
    SensorWaiting
}Sensor_state_id;

//prototypes
State_define(SensorInit);
State_define(SensorReading);
State_define(SensorWaiting);

//global pointer
 void(*sensor_ptr)();

#endif // _SENSOR_H
