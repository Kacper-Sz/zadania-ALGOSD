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

        printf("2 - dodaj wartownik\n");

        printf("3 - dodaj element lista uporzadkowana\n");
        printf("4 - dodaj element lista uporzadkowana z wartownikiem\n");
        printf("5 - znajdz element w liscie uporzadkowanej\n");
        printf("6 - znajdz element w liscie uporzadkowanej z wartownikem\n");
        printf("7 - usun wskazany element z listy uporzadkowanej\n");
        printf("8 - usun wskazany element z listy uporzadkowanej z wartownikiem\n");
        printf("9 - pobierz pierwszy element z z listy uporzadkowanej\n");
        printf("10 - pobierz pierwszy element z z listy uporzadkowanej z wartownikiem\n");
        printf("11 - pobierz ostatni element z z listy uporzadkowanej\n");
        printf("12 - pobierz ostatni element z z listy uporzadkowanej z wartownikiem\n");
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
                WyswietlListeOdPoczatku(_l);
                break;
            case 2:
                // dodaj wartownik
                printf("\n");
                DodanieWartownika(&_l);
                printf("\n");
                break;
            case 3:
                // dodaj element lista uporzadkowana
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac: ");
                scanf("%d", &number);
                DodajDoPosortowanej(&_l, number);
                printf("\n");
                break;
            case 4:
                // dodaj element lista uporzadkowana z wartownikiem
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac: ");
                scanf("%d", &number);
                DodajDoPosortowanejWartownik(&_l, number);
                printf("\n");
                break;
            case 5:
                // znajdz element w liscie uporzadkowanej
                printf("\n");
                printf("podaj liczbe ktora chcesz znalezc: ");
                scanf("%d", &number);
                lista *znaleziony = ZnajdzPosortowana(&_l, number);
                if (znaleziony) {
                    printf("Znaleziono element %d\n", (*znaleziony)->klucz);
                } else {
                    printf("Nie znaleziono elementu %d\n", number);
                }
                printf("\n");
                break;
            case 6:
                // znajdz element w liscie uporzadkowanej z wartownikiem
                printf("\n");
                printf("podaj liczbe ktora chcesz znalezc: ");
                scanf("%d", &number);
                lista *znalezionyWartownik = ZnajdzPosortowanaWartownik(&_l, number);
                if (znalezionyWartownik) {
                    printf("Znaleziono element %d\n", (*znalezionyWartownik)->klucz);
                } else {
                    printf("Nie znaleziono elementu %d\n", number);
                }
                printf("\n");
                break;
            case 7:
                // usun wskazany element z listy uporzadkowanej
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazanyPosortowana(&_l, number);
                printf("\n");
                break;
            case 8:
                // usun wskazany element z listy uporzadkowanej z wartownikiem
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazanyPosortowanaWartownik(&_l, number);
                printf("\n");
                break;
            case 9:
                // pobierz pierwszy element z z listy uporzadkowanej
                printf("\n");
                lista* pierwszy = ZnajdzPierwszy(&_l);
                if (pierwszy) {
                    printf("Pierwszy element to %d\n", (*pierwszy)->klucz);
                } else {
                    printf("Lista jest pusta\n");
                }
                printf("\n");
                break;
            case 10:
                // pobierz pierwszy element z z listy uporzadkowanej z wartownikiem
                printf("\n");
                lista* pierwszyWartownik = ZnajdzPierwszyWartownik(&_l);
                if (pierwszyWartownik) {
                    printf("Pierwszy element to %d\n", (*pierwszyWartownik)->klucz);
                } else {
                    printf("Lista jest pusta\n");
                }
                printf("\n");
                break;
            case 11:
                // pobierz ostatni element z z listy uporzadkowanej
                printf("\n");
                lista* ostatni = ZnajdzOstatni(&_l);
                if (ostatni) {
                    printf("Ostatni element to %d\n", (*ostatni)->klucz);
                } else {
                    printf("Lista jest pusta\n");
                }
                printf("\n");
                break;
            case 12:
                // pobierz ostatni element z z listy uporzadkowanej z wartownikiem
                printf("\n");
                lista* ostatniWartownik = ZnajdzOstatniWartownik(&_l);
                if (ostatniWartownik) {
                    printf("Ostatni element to %d\n", (*ostatniWartownik)->klucz);
                } else {
                    printf("Lista jest pusta\n");
                }
                printf("\n");
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
