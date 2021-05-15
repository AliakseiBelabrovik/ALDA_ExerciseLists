//
//  list.c
//  ALDA_ExerciseLists
//
//  Created by Michael Strommer on 26.04.21.
//

#include "list.h"

void lichterKetteCtrl(char sel, struct list** list) {
    char input = NULL;
    int position = NULL;
    switch (sel)
    {
        
        case 'e':
            while (1)
            {
                input = NULL;
                printf("l: ");
                scanf(" %c", &input);
                if (input == '0')
                {
                    break;
                }
                addEnd(input, &(*list));
            }
            break;
        case 'a':
            while (1)
            {
                input = NULL;
                printf("l: ");
                scanf(" %c", &input);
                if (input == '0')
                {
                    break;
                }
                addStart(input, &(*list));
            }
            break;
        
        case 'i':
                //read position
                printf("l: ");
                scanf(" %d", &position);

                //read the color to add
                printf("l: ");
                scanf(" %c", &input);
                if (input == '0')
                {
                    break;
                }
                insertAtIndex(input, &(*list), position);
                break;
        case 'l':
            //read position
            printf("l: ");
            if (input == '0')
            {
                break;
            }
            deleteFromList(&(*list), position);
            break;
        case 'u':
            revert(&(*list));
            break;

      
        case 'x':
            printf("Bye\n");
            break;
            
        default:
            printf("%c is not allowed now! Please choose between a, e,i, l, u and x", input);
            break;
    }
}

//gibt die Lichterkette auf der Konsole aus
void printListe(struct list* list) {
    printf("Lichterkette: ");
    struct list* help = list; 
    for (; help != NULL; help = help->next)
    {
        printf(" %c", help->color);
        if (help->next == list) {
            printf("\n");
            break;
        }
        printf(" - ");
    }
    printf("I leaving the printListe method\n");
}

//ein Objekt wird am Anfang hinzugefügt
void addStart(char sel, struct list** list) {
    element* neu;
    element* help;
    neu = (element*) malloc(sizeof(element));
    neu->color = sel;

    if (*list == NULL) {
        printf("The list is null\n");
        neu->next = neu;
        neu->previous = neu;
        *list = neu;
    } else {
        //if the list is not null -> help pointer should point to the beginning of that list
        help = *list;
        neu->next = help;
        neu->previous = help->previous;
        neu->previous->next = neu;
        neu->next->previous = neu;

        //da neu nun das 1. Element ist -> soll Liste auf ihn zeigen. 
        *list = neu;
    }
   
}

//ein Element wird am Ende hinzugefügt
void addEnd(char sel, struct list** list) {
    element* neu;
    element* help;
    neu = (element*) malloc(sizeof(element));
    neu->color = sel;

    if (*list == NULL) {
        printf("The list is null\n");
        neu->next = neu;
        neu->previous = neu;
        *list = neu;
    }
    else
    {
        help = *list; //pointer to the first element of the list
        help = help->previous; //the last element of the list
        neu->next = *list;
        neu->previous = help;
        neu->previous->next = neu;
        neu->next->previous = neu;
    }
}

//Ein Element wird nach der Position eingefügt
void insertAtIndex(char sel, struct list** list, int position) {
    element* neu; //pointer auf neues element
    element* help; //hilfspointer
    neu = (element*)malloc(sizeof(element)); //reserviere platz für neues element
    neu->color = sel; //initialisiere color des neuen elements
    if (*list == NULL) {
        neu->next = neu;
        neu->previous = neu;
        *list = neu; //pointer der liste soll nun auf das neue = 1. Element zeigen
    }
    else
    {
        help = *list; //wenn die liste nicht leer ist, soll hilfszeiger auf den anfang der liste zeigen
        for (int i = 0; i <= position-1; i++)
        {
            help = help->next;
        }
        neu->next = help;
        neu->previous = help->previous;
        neu->previous->next = neu;
        neu->next->previous = neu;

        if (position == 0) {
            *list = neu; 
        }

    }
}

//Ein Element wird an bestimmter Stelle entfernt
void deleteFromList(struct list** list, int position) {
    element* help;
    

    help = *list;
    if (help->next == *list && help->previous == help) {
        *list = NULL;
    }
    else
    {
        for (int i = 1; i <= position-1; i++)
        {
            help = help->next;
        }
        help->previous->next = help->next;
        help->next->previous = help->previous;

        if (position == 1) {
            *list = help->next;
        }
    }
}

//Die Liste wird umgekehrt 
void revert(struct list** list) {
    element *help = *list;
    element* help2; //hilfszeiger 
    element* end = help->previous; //wir merken uns das ende der liste -> diese wird später als anfang der liste initialisiert
    for (; help != NULL; help = help->next)
    {
        help2 = help->next;
        help->next = help->previous;
        help->previous = help2;

        //falls das nächste element das 1. war, wir stoppen und lassen die list auf das ende zeigen
        if (help->next == *list) {
            *list = end;
            break;
        }
    }
}



