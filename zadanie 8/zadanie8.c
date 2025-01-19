#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int choice, number;
    
    lista _l = 0;
    DodanieWartownika(&_l);
    lista _q = 0;
    DodanieWartownika(&_q);

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");

        printf("1 - wyswietl zawartosc list\n");

        printf("2 - dodaj element do L\n");
        printf("3 - dodaj element do Q\n");
        printf("4 - wczytaj listy z pliku\n");
        printf("5 - porownaj listy (zadanie 8)\n");
        
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
                //dodanie elementu do listy L
                printf("\n");
                printf("podaj liczbe: ");
                scanf("%d", &number);
                DodajDoPosortowanejWartownik(&_l, number);
                break;
            case 3:
                //dodanie elementu do listy Q
                printf("\n");
                printf("podaj liczbe: ");
                scanf("%d", &number);
                DodajDoPosortowanejWartownik(&_q, number);
                break;
            case 4:
                //wczytanie list z pliku
                _l = PobierzListe("listaL.txt");
                _q = PobierzListe("listaQ.txt");
                printf("listy wczytane\n");
                break;
            case 5:
                //porownanie list
                lista _wynikL = 0;
                lista _wynikQ = 0;
                DodanieWartownika(&_wynikL);
                DodanieWartownika(&_wynikQ);
                //
                printf("\nLISTY PRZED\n");
                printf("lista L: ");
                WyswietlListeOdPoczatku(_l);
                printf("\nlista Q: ");
                WyswietlListeOdPoczatku(_q);
                printf("\n");
                //
                PorownajListy(_l, _q, &_wynikL, &_wynikQ);
                //
                printf("\nLISTY PRZED\n");
                printf("lista L: ");
                WyswietlListeOdPoczatku(_wynikL);
                printf("\nlista Q: ");
                WyswietlListeOdPoczatku(_wynikQ);
                //
                printf("\n");
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
