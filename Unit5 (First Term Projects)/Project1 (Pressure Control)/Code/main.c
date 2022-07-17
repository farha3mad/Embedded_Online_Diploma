#include "alarm.h"
#include "alarm_monitor.h"
#include "algo.h"
#include"sensor.h"
#include "driver.h"

void setup(){

    //Initializing drivers
    GPIO_INITIALIZATION();

    //Initial state for each module
    sensor_ptr = State(SensorInit);
    alarm_ptr = State(AlarmInit);
    alarm_monitor_ptr = State(AlarmMonitorIdle);
    algo_ptr = State(High_pressure_detection);
}

int main()
{
    setup();
    while(1){

        //calling functions
        sensor_ptr();
        algo_ptr();
        alarm_monitor_ptr();
        alarm_ptr();

       //delay
       Delay(50000);
    }
    return 0;
}

