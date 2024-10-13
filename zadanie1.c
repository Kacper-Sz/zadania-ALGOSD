#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int choice, number;
    
    lista _l = 0;

    while(1)
    {
        printf("nastepna operacja: \n");
        printf("1 - dodaj element na poczatku listy\n");
        printf("2 - dodaj element na koncu listy\n");
        printf("3 - usun pierwszy element listy\n");
        printf("4 - usun ostatni element listy\n");
        printf("5 - odszukaj zadany element\n");
        printf("6 - dodaj element przed lub za wskazanym\n");
        printf("7 - usun wskazany element\n");

        printf("10 - wyswietl zawartosc listy\n");
        printf("0 - wyjdz\n\n");

        printf("twoj wybor: ");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 0)
        {
            break;
        }
        
        switch(choice)
        {
            case 1:
                //funkcja dodawania na poczatku listy
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                printf("\n");
                DodajNaPoczatek(&_l, number);
                break;
            case 2:
                //funkcja dodawania na koncu listy
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                printf("\n");
                DodajNaKoniec(&_l, number);
                break;
            case 3:
                //funkcja usuwania pierwszego elementu listy
                UsunPierwszy(&_l);
                printf("usunieto pierwszy element z listy");
                break;
            case 4:
                //funkcja usuwania ostatniego elementu listy
                UsunOstatni(&_l);
                printf("usunieto ostatni element z listy");
                break;
            case 5:
                //funkcja odszukujaca zadany element
                printf("podaj liczbe ktora chcesz odszukac: ");
                scanf("%d", &number);
                printf("\n");
                OdszukajElement(_l, number);
                break;
            case 6:
                printf("podaj liczbe ktora chcesz dodac jako nowy element: ");
                scanf("%d", &number);
                printf("\npodaj liczbe przed lub za ktora chcesz dodac nowy element: ");
                int gdzie, opcja;
                scanf("%d", &gdzie);
                printf("\n1 - dodaj przed\n");
                printf("2 - dodaj za\n");
                printf("Wybierz opcje: ");
                scanf("%d", &opcja);
                if (opcja == 1 || opcja == 2) {
                    DodajPrzedLubZa(&_l, number, gdzie, opcja);
                } else {
                    printf("Niepoprawna opcja\n");
                }
                printf("\n");
                break;
            case 7:
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazany(&_l, number);
                printf("\n");
                break;


            case 10:
                WyswietlListeOdPoczatku(_l);
                break;
            default:
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
