#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(){
    //this program can calculate the Area of a given triangle using the Gauﬂsche Trapezformel
    // vars
    uint16_t x1, y1, x2, y2, x3, y3;
    // Rectangle Coordinates
    printf("erster Punkt des Dreiecks:\n");
    getXYCoordinates(&x1, &y1);
    printf("zweiter Punkt des Dreiecks:\n");
    getXYCoordinates(&x2, &y2);
    printf("dritter Punkt des Dreiecks:\n");
    getXYCoordinates(&x3, &y3);
    // Calculations

    // output
}

void getXYCoordinates(uint16_t *x, uint16_t *y){
    printf("bitte geben Sie die X Koordinate ein:\n");
    scanf("%i", x);
    printf("bitte geben Sie die Y Koordinate ein:\n");
    scanf("%i", y);
}
