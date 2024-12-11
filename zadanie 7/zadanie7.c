#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int choice, number;
    
    lista _l = 0;
    lista _q = 0;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");

        printf("1 - wyswietl zawartosc list\n");

        printf("2 - dodaj element do L\n");
        printf("3 - dodaj element do Q\n");

        printf("4 - polacz listy\n");
        
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
            case 0:
                break;
            case 1:
                //wyswietlanie listy
                printf("\n");
                printf("lista L: ");
                WyswietlListeOdPoczatku(_l);
                printf("\nlista Q: ");
                WyswietlListeOdPoczatku(_q);
                printf("\n");
                break;
            case 2:
                // dodaj element lista uporzadkowana
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac: ");
                scanf("%d", &number);
                DodajDoPosortowanej(&_l, number);
                printf("\n");
                break;
            case 3:
                // dodaj element lista uporzadkowana
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac: ");
                scanf("%d", &number);
                DodajDoPosortowanej(&_q, number);
                printf("\n");
                break;      
            case 4:
                // laczenie list
                polaczListy(&_l, &_q);
                printf("\n");
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
