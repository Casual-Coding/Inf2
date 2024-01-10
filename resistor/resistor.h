#ifndef RESISTOR_H_INCLUDED
#define RESISTOR_H_INCLUDED

class resistor {
    //vars
    double res;
public:
        //constructor
        resistor(double r) : res(r) {}
        //set resistance, not done
        void set_res(double r) {res = r;}
        //functions
        double get_res() const {return res;}
        double get_curr(double voltage) const {return voltage / res;}
        double get_voltage(double current) const {return current * res;}
};



#endif // RESISTOR_H_INCLUDED
