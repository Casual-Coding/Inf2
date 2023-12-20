#include <stdio.h>
#include <stdint.h>

int main(){
    // this tool is supposed to identify a given Symbol
    uint16_t toCheck;
    // input
    printf("please input a Single Number, letter or Symbol, this Programm is gonna identify it:\n");
    scanf("%c", &toCheck);
    //switch case
    if (toCheck >= 65 && toCheck <= 90){
        printf("its a Capital letter");
    } else if (toCheck >= 97 && toCheck <= 122) {
        printf("its a small Letter");
    }  else if (toCheck >= 48 && toCheck <= 57) {
        printf("its a Number");
    }  else if (toCheck >= 0 && toCheck <= 31 || toCheck == 127) {
        printf("Control Symbol");
    }   else {
        printf("its a Symbol");
    }
}
