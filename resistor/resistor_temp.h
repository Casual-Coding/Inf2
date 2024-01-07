#ifndef RESISTOR_TEMP_H_INCLUDED
#define RESISTOR_TEMP_H_INCLUDED

#include "resistor.h"

class resistor_temp : public resistor
{
    double alpha;
    double t_ref;
    double r_ref;
    double temp;

public:
    resistor_temp(double p_alpha, double p_r_ref, double p_t_ref) :
    alpha {p_alpha},
    t_ref {p_t_ref},
    r_ref {p_r_ref},
    temp {p_t_ref},
    resistor {p_r_ref} {}
    void set_temp(double tem){
    temp = tem;
    set_res(r_ref *(1.0+alpha*(temp-t_ref)));
    }
    void set_res(double r){
    resistor::set_res(r);
    temp = (((r/r_ref)-1.0) / alpha) + t_ref;
    }


};


#endif // RESISTOR_TEMP_H_INCLUDED
