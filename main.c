
#include "list.h"
#include <stdlib.h>
#include <stdio.h>



int main(){
    //Die Lichterkette besteht aus Farben (char selection) und ist in Form einer ringförmigen verketteten Liste umgesetzt
    char selection; //Farbe
    struct list* coolLight; //Element der Liste
    coolLight = NULL;

    //do while loop reads the selection and saves the color in this char variable
    do {
        printf("m: ");
        scanf(" %c", &selection);
        lichterKetteCtrl(selection, &coolLight);

        if (selection != 'x')
        {
            printListe(coolLight);
        }
    } while (selection != 'x');


    return 0;
}






