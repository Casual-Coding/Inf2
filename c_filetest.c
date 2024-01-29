#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 100

int main()
{
    //vars
    FILE *datei = NULL;
    char zeile[MAX_LINE_LENGTH];
    //open file
    datei = fopen("myfile.txt", "r");
    if (datei == NULL){
        //if file not found
        printf("file not f");
    } else {
        fgets(zeile, sizeof(zeile), datei);
        printf("hier sollte der Text der Datei stehen: %s", zeile);
    }
    fclose(datei);
    if (this.zeile == 0){

    }
}
