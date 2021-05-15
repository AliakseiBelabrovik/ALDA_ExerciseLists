//
//  list.h
//  ALDA_ExerciseLists
//
//  Created by Michael Strommer on 26.04.21.
//

#ifndef list_h
#define list_h

#include <stdio.h>


struct list
{
    char color;  //Farbe des jewiligen Elements der Kette
    struct list* next; /* Zeiger auf das nächste Element */
    struct list* previous; //Zeige auf den Vorgänger
};

typedef struct list element;

void lichterKetteCtrl(char sel, struct list** list);
void printListe(struct list* list);
void addStart(char sel, struct list** list);
void addEnd(char sel, struct list** list);
void insertAtIndex(char sel, struct list** list, int position);
void deleteFromList(struct list** list, int position);
void revert(struct list** list);

#endif /* list_h */
