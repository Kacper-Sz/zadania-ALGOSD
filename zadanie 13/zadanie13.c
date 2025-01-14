#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int choice, liczba, priorytet;
    
    lista _l = 0;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");
        printf("1 - wyswietl liste\n");
        printf("2 - dodaj element\n");
        
        printf("0 - wyjdz\n\n");

        printf("twoj wybor: ");
        scanf("%d", &choice);
        printf("------------------------------------\n");
        printf("\n");

        if(choice == 0)
        {
            break;
        }
        
        switch(choice)
        {
            case 1:
                printf("\n");
                WyswietlKolejke(_l);
                printf("\n");
                break;
            case 2:
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac: ");
                scanf("%d", &liczba);
                printf("podaj priorytet: ");
                scanf("%d", &priorytet);
                DodajDoKolejkiPriorytetowej(&_l, liczba, priorytet);
                printf("\n");
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
