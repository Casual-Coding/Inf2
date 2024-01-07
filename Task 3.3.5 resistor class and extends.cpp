#include <iostream>

class Resistor {
    float resistance;
};




/*#include <iostream>

class Resistor {

    double resistance;

public:
    Resistor(double initialResistance) : resistance(initialResistance) {}

    double getResistance() const {
        return resistance;
    }

    void setResistance(double newResistance) {
        resistance = newResistance;
    }

    double calculateCurrent(double voltage) const {
        return voltage / resistance;
    }

    double calculateVoltage(double current) const {
        return resistance * current;
    }
};
