#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(){
    //goal of this Programm ist to run some arithmetic Operations and store the Resulats in
    //different Variables, of types that wont hold that Data

    //vars
    uint8_t a = 4;
    uint8_t b = 6;
    uint8_t c;

    c = a - b;
    //wrong result will be printed, cause uint cant handle negative values
    printf("%i - %i = %i \n wrong result, cause uints cant handle negative Values \n", a, b, c);

    c = (a * b) + 300;
    printf("%i * %i = %i \n result should be 324, but since 8 bit Unsigned Number can only display 256, Result will be wrong \n", a, b, c);
}
