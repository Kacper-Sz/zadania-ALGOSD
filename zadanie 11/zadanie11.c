#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int choice, number;
    
    listaB _lB = 0;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");
        printf("1 - wyswietl zawartosc listy\n");
        printf("2 - dodaj element na koncu listy\n");
        printf("3 - usun K-te\n");
        
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
            {
                // wyswietl liste od poczatku
                printf("\n");
                WyswietlListeOdPoczatkuB(_lB);
                printf("\n");
                break;
            }
            case 2:
            {
                // dodaj element na poczatek listy
                printf("podaj liczbe: ");
                scanf("%d", &number);
                DodajNaKoniecB(&_lB, number);
                printf("\n");
                break;
            }
            case 3:
            {
                // usun K-te
                printf("podaj liczbe: ");
                scanf("%d", &number);
                UsuwanKaty(&_lB, number);
                printf("\n");
                printf("usunieto, na liscie pozostal element: ");
                WyswietlListeOdPoczatkuB(_lB);
                printf("\n");
                break;
            }
            
        }
    }

    return 0;

}
