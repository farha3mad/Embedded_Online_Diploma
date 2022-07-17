#include "algo.h"
 //variables
int algo_pval;
int algo_threshold ;

State_define(High_pressure_detection){
    //state action
    Algo_state_id = High_pressure_detection;
    //receiving the pressure value
    algo_pval = send_pval();
    //stay in the same state
    algo_ptr = State(High_pressure_detection);
}

//sending to alarm monitor if there is high pressure or not
int highP(void){
    algo_threshold =20;
    return(algo_pval>=algo_threshold);
}

