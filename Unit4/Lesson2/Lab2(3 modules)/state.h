#ifndef _STATE_H
#define _STATE_H

#include <stdio.h>
#include <stdlib.h>

/*** Generic state function declaration ***/
#define State_define(_state_) void ST##_state_()
#define State(_state_)  ST##_state_

//Connections
void US_set_distance(int d);
void DC_set_speed(int s);

#endif // _STATE_H
