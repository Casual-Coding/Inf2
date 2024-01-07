#ifndef RESISTOR_H_INCLUDED
#define RESISTOR_H_INCLUDED

class resistor {
    double res;
public:
        resistor(double r) : res{r} {}
        void set_res(double r) {res = r;}
        double get_res() const {return res;}
        double get_curr(double voltage) const {return voltage / res;}
        double get_voltage(double current) const {return current * res;}
};



#endif // RESISTOR_H_INCLUDED
