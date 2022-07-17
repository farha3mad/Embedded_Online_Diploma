#include "sensor.h"

//variables
 int sensor_pval=0;

State_define(SensorInit){
    //initializing pressure sensor driver
    Sensor_state_id = SensorInit;
    //going to the reading state
    sensor_ptr = State(SensorReading);
}

State_define(SensorReading){
    //state action
    Sensor_state_id = SensorReading;
    //getting the pressure value
    sensor_pval = getPressureVal();
    //going to the waiting state
    sensor_ptr = State(SensorWaiting);
}

State_define(SensorWaiting){
    //state name
    Sensor_state_id = SensorWaiting;
    //setting timer between readings
    Delay(10000);
    //going to the reading state again
    sensor_ptr = State(SensorReading);
}

//sending the pressure value to the main algorithm
int send_pval(){
    return sensor_pval;
}

