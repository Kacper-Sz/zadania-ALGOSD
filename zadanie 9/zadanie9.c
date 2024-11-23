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
        printf("12 - dodaj element do listy posortowanej z wartownikiem\n");

        printf("\n");

        printf("13 - znajdz element w liscie posrtowanej\n");
        printf("14 - znajdz element w liscie posortowanej z wartownikiem\n");

        printf("\n");

        printf("15 - usun wskazany element z listy posortowanej\n");
        printf("16 - usun wskazany element z listy posortowanej z wartownikiem\n");

        printf("\n");

        printf("17 - pobierz pierwszy element z listy posortowanej\n");
        printf("18 - pobierz pierwszy element z listy posortowanej z wartownikiem\n");

        printf("\n");

        printf("19 - pobierz ostatni element z listy posortowanej\n");
        printf("20 - pobierz ostatni element z listy posortowanej z wartownikiem\n");

        printf("\n");
        
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
            case 12:
                //funkcja dodajaca element do listy posortowanej z wartownikiem
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac: ");
                scanf("%d", &number);
                DodajDoPosortowanejWartownik(&_l, number);
                printf("\n");
                break;
            case 13:
                //funkcja znajdujaca element w liscie posortowanej
                printf("\n");
                printf("podaj liczbe ktora chcesz znalezc: ");
                scanf("%d", &number);
                lista *znaleziony = ZnajdzPosortowana(&_l, number);
                if(znaleziony)
                {
                    printf("znaleziono element %d\n", (*znaleziony)->klucz);
                }
                else
                {
                    printf("nie znaleziono elementu %d\n", number);
                }
                break;
            case 14:
                //funkcja znajdujaca element w liscie posortowanej z wartownikiem
                printf("\n");
                printf("podaj liczbe ktora chcesz znalezc: ");
                scanf("%d", &number);
                lista *znalezionyWartownik = ZnajdzPosortowanaWartownik(&_l, number);
                if(znalezionyWartownik)
                {
                    printf("znaleziono element %d\n", (*znalezionyWartownik)->klucz);
                }
                else
                {
                    printf("nie znaleziono elementu %d\n", number);
                }
                break;
            case 15:
                //funkcja usuwajaca wskazany element z listy posortowanej
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazanyPosortowana(&_l, number);
                break;
            case 16:
                //funkcja usuwajaca wskazany element z listy posortowanej z wartownikiem
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazanyPosortowanaWartownik(&_l, number);
                break;
            case 17:
                //funkcja pobierajaca pierwszy element z listy posortowanej
                printf("\n");
                lista *pierwszy = ZnajdzPierwszy(&_l);
                if(pierwszy)
                {
                    printf("pierwszy element to %d\n", (*pierwszy)->klucz);
                }
                else
                {
                    printf("lista jest pusta\n");
                }
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
