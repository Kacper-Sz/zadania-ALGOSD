#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"


int main()
{
    int choice;
    
    while(1)
    {
        printf("Wybierz dzialanie: ");
        printf("1 - dodaj element na poczatku listy\n");
        printf("2 - dodaj element na koncu listy\n");
        printf("3 - usun pierwszy element listy\n");
        printf("4 - usun ostatni element listy\n");
        printf("5 - odszukaj zadany element\n");
        scanf("%d", &choice);
        
        if(choice == 5)
        {
            break;
        }
        
        switch(choice)
        {
            case 1:
                //funkcja dodawania na poczatku listy
                break;
            case 2:
                //funkcja dodawania na koncu listy
                break;
            case 3:
                //funkcja usuwania pierwszego elementu listy
                break;
            case 4:
                //funkcja usuwania ostatniego elementu listy
                break;
            default:
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

}
