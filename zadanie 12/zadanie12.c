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
        printf("1 - wyswietl zawartosc listy\n");
        printf("2 - dodaj element na koncu listy L\n");
        printf("3 - dodaj element na koncu listy Q\n");
        printf("4 - usun powtorzenia z listy L elementow z listy Q\n");
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
                //wyswietlanie listy
                printf("\n");
                printf("lista L: ");
                WyswietlListeOdPoczatku(_l);
                printf("\n");       
                printf("lista Q: ");
                WyswietlListeOdPoczatku(_q);
                printf("\n");         
                break;
            case 2:
                //dodawanie elementu na koniec listy
                printf("\n");
                printf("podaj liczbe: ");
                scanf("%d", &number);
                DodajNaKoniec(&_l, number);
                printf("\n");
                break;
            case 3:
                //dodawanie elementu na koniec listy
                printf("\n");
                printf("podaj liczbe: ");
                scanf("%d", &number);
                DodajNaKoniec(&_q, number);
                printf("\n");
                break;
            case 4:
                //usuwanie powtorzen
                UsunPowtorzenia(&_l, _q);
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
