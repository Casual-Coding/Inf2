#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


int main(){
    // this Sample Code is supposed to calculate the current flowing through Resistor R2, in a Resistor Network
    // Schematic of Resistor Network
    printf("--------====----------\nI       R1      I    I\nI               I    I\nO Uq         R2 H    H  R3\nI               H    H\nI               H    H\nI               I    I\n----------------------\n");

    // vars
    float uq, r1, r2, r3;
    float rges, iges, u1, i2;
    // Input Values

    getResistorValue(&r1, "r1");
    getResistorValue(&r2, "r2");
    getResistorValue(&r3, "r3");
    printf("bitte Wert für Uq eingeben, nur in ganzen Volt:");
    scanf("%f", &uq);
    // Calculate Current i=U/R
    rges = r1 + ((r2*r3) / (r2+r3));
    iges = uq / rges;
    u1 = iges * r1;
    i2 = (uq - u1) / r2;

    // Output
    printf("I2 beträgt %f A", i2);
}

void getResistorValue(uint16_t *res, char resistorName[]){
    printf("bitte Wert für %s eingeben, nur in ganzen Ohm:", resistorName);
    scanf("%f", res);
}
