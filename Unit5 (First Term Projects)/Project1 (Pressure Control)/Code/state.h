#ifndef _STATE_H
#define _STATE_H

#include "driver.h"
#include <stdio.h>
#include <stdlib.h>

/*** Generic state function declaration ***/
#define State_define(_state_) void ST##_state_()
#define State(_state_)  ST##_state_

/*** Connections ***/
//Main Algorithm -----> Alarm monitor
int highP(void);

//Pressure sensor -----> Main Algorithm
int send_pval();

//Alarm monitor -----> Alarm
void Start_Alarm();
void Stop_Alarm();

#endif // _STATE_H
