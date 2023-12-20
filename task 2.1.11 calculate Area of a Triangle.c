#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(){
    //this program can calculate the Area of a given triangle using the Gauﬂsche Trapezformel
    // vars
    uint16_t x1, y1, x2, y2, x3, y3;
    float area, subarea1, subarea2, subarea3;
    // Rectangle Coordinates
    printf("erster Punkt des Dreiecks:\n");
    getXYCoordinates(&x1, &y1);
    printf("zweiter Punkt des Dreiecks:\n");
    getXYCoordinates(&x2, &y2);
    printf("dritter Punkt des Dreiecks:\n");
    getXYCoordinates(&x3, &y3);
    // Calculations using  2A=Summe xi * (yi+1-yi-1)
    subarea1 = x1 * (y2 - y3);
    subarea2 = x2 * (y3 - y1);
    subarea3 = x3 * (y1 - y2);
    area = (subarea1 + subarea2 + subarea3) / 2;
    if (area < 0) {
        area = area * -1;
    }
    // output
    printf("Der Fl‰cheninhalt des Dreiecks betr‰gt %.1f FE", area);
}

void getXYCoordinates(uint16_t *x, uint16_t *y){
    printf("bitte geben Sie die X Koordinate ein:\n");
    scanf("%hu", x);
    printf("bitte geben Sie die Y Koordinate ein:\n");
    scanf("%hu", y);
}
