#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

int main()
    {
    //vars
    char input[15];
    float grad = 0;
    float fahrenheit;

    //input
    printf("bitte geben Sie eine Temperatur in Grad ein, welche Sie in Fahrenheit umrechnen wollen:\n");
    scanf("%s", &input);

    if (sscanf(input, "%f", &grad) ==1)
            {
            //calculation
            fahrenheit = (grad * 1.8) + 32;

            //console output
            printf("%.1fC entspricht %.1f fahrenheit\n", grad, fahrenheit);
    } else {
            printf("keine gueltige Zahl eingegeben !");
            }
    }
