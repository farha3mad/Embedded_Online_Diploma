#ifndef _STATE_H
#define _STATE_H
/*** Generic state function declaration ***/
#define State_define(_state_) void ST##_state_()
#define State(_state_)  ST##_state_

#endif // _STATE_H
