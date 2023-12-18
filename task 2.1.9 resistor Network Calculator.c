#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(){
    //tool for Calculating of the Resistance of a Resistor Network
    //print Network Shematic
    printf("-----====---o---====---====---o---\n      R1    I     R2    R3    I   \n            L------====-------I   \n                    R4\n");

    //enter Values for each Resistor
    uint16_t r1, r2, r3, r4, r23;
    float r234, rges;

    getResistorValue(&r1, "r1");
    getResistorValue(&r2, "r2");
    getResistorValue(&r3, "r3");
    getResistorValue(&r4, "r4");

    printf("-----====---o---====---====---o---\n     %iOhm  I    %iOhm  %iOhm   I   \n            L------====-------I   \n                   %iOhm\n", r1, r2, r3, r4);

    //Calulate
    r23 = r2 + r3;
    r234 = (r23*r4)/(r23+r4);
    rges = r234 + r1;

    //Printout
    printf("R2 + R3 = %i OHM, R2&R3 parallel zu R4 haben einen gesamtwiderstand von %f OHM, die Schaltung hat einen gesamtwiedrstand von %f OHM", r23, r234, rges);

}

void getResistorValue(uint16_t *res, char name[]){
    printf("bitte wert fuer %s eingeben, nur in ganzen Ohm:", name);
    scanf("%hu", res);
}
