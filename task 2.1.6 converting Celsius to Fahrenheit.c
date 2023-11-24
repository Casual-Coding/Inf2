#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main()
    {
    //vars
    float grad = 0;
    float fahrenheit;

    //input
    printf("bitte geben Sie eine Temperatur in Grad ein, welche Sie in Fahrenheit umrechnen wollen:\n");
    scanf("%f", &grad);

    //calculation
    fahrenheit = (grad * 1.8) + 32;

    //console output
    printf("%.1fC entspricht %.1f fahrenheit\n", grad, fahrenheit);
    }
