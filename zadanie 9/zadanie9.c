#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int choice, number, gdzie, opcja;
    
    lista _l = 0;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");
        printf("1 - wyswietl zawartosc listy\n");
        printf("2 - dodaj element na poczatku listy\n");
        printf("3 - dodaj element na koncu listy\n");
        printf("4 - usun pierwszy element listy\n");
        printf("5 - usun ostatni element listy\n");
        printf("6 - odszukaj zadany element\n");
        printf("7 - dodaj element przed\n");
        printf("8 - dodaj element za\n");
        printf("9 - usun wskazany element\n");

        printf("\n");

        printf("10 - dodaj wartownik\n");
        printf("11 - dodaj element do listy posortowanej\n");

        
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
                printf("jak ma byc wyswietlana lista?");
                printf("\n1 - od poczatku\n");
                printf("2 - od konca\n");
                printf("podaj wybor: ");
                scanf("%d", &opcja);
                printf("\n");
                if (opcja == 1) WyswietlListeOdPoczatku(_l);
                if (opcja == 2) WyswietlListeOdKonca(_l);
                break;
            case 2:
                //funkcja dodawania na poczatku listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaPoczatek(&_l, number);
                printf("\n");
                printf("dodano na poczatek listy");
                printf("\n");
                break;
            case 3:
                //funkcja dodawania na koncu listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaKoniec(&_l, number);
                printf("\n");
                printf("dodano na koniec listy");
                printf("\n");
                break;
            case 4:
                //funkcja usuwania pierwszego elementu listy
                printf("\n");
                UsunPierwszy(&_l);
                printf("\n");
                break;
            case 5:
                //funkcja usuwania ostatniego elementu listy
                printf("\n");
                UsunOstatni(&_l);
                printf("\n");
                break;
            case 6:
                //funkcja odszukujaca zadany element
                printf("\n");
                printf("podaj liczbe ktora chcesz odszukac: ");
                scanf("%d", &number);
                lista *q = OdszukajElement(&_l, number);
                if(q != NULL)
                {
                    printf("znaleziono element %d\n", (*q)->klucz);
                }
                else
                {
                    printf("nie znaleziono elementu %d\n", number);
                }
                printf("\n");
                break;
            case 7:
                //funkcja dodajaca przed wskazanym elementem
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac jako nowy element: ");
                scanf("%d", &number);
                printf("\npodaj liczbe przed ktora ma byc dodany nowy element: ");
                scanf("%d", &gdzie);
                DodajPrzed(&_l, number, gdzie);
                printf("\n");
                break;
            case 8:
                //funkcja dodajaca za wskazanym elementem
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac jako nowy element: ");
                scanf("%d", &number);
                printf("\npodaj liczbe za ktora ma byc dodany nowy element: ");
                scanf("%d", &gdzie);
                DodajZa(&_l, number, gdzie);
                printf("\n");
                break;
            case 9:
                //funkcja usuwajaca wskazany element
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazany(&_l, number);
                printf("\n");
                break;
            case 10:
                //funkcja dodajaca wartownik
                printf("\n");
                DodanieWartownika(&_l);
                printf("\n");
                break;
            case 11:
                //funkcja dodajaca element do listy posortowanej
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac: ");
                scanf("%d", &number);
                DodajDoPosortowanej(&_l, number);
                printf("\n");
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
