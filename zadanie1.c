#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int choice, number, gdzie, opcja, ktore;
    
    lista _l = 0;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
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
        printf("------------------------------------\n");
        printf("\n");

        if(choice == 0)
        {
            break;
        }
        
        switch(choice)
        {
            case 1:
                //funkcja dodawania na poczatku listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaPoczatek(&_l, number);
                printf("\n");
                printf("dodano na poczatek listy");
                printf("\n");
                break;
            case 2:
                //funkcja dodawania na koncu listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaKoniec(&_l, number);
                printf("\n");
                printf("dodano na koniec listy");
                printf("\n");
                break;
            case 3:
                //funkcja usuwania pierwszego elementu listy
                printf("\n");
                UsunPierwszy(&_l);
                printf("\n");
                break;
            case 4:
                //funkcja usuwania ostatniego elementu listy
                printf("\n");
                UsunOstatni(&_l);
                printf("\n");
                break;
            case 5:
                //funkcja odszukujaca zadany element
                printf("\n");
                printf("podaj liczbe ktora chcesz odszukac: ");
                scanf("%d", &number);
                OdszukajElement(_l, number);
                printf("\n");
                break;
            case 6:
                //funkcja dodajaca przed lub za
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac jako nowy element: ");
                scanf("%d", &number);
                printf("\npodaj liczbe przed lub za ktora chcesz dodac nowy element: ");
                scanf("%d", &gdzie);
                printf("\n1 - dodaj przed\n");
                printf("2 - dodaj za\n");
                printf("Wybierz opcje: ");
                scanf("%d", &opcja);
                printf("\n1 - dodaj tylko przed pierwszym napotkanym\n");
                printf("2 - dodaj przed kazdym napotkanym\n");
                printf("wybierz opcje: ");
                scanf("%d", &ktore);
                if (opcja == 1 || opcja == 2) {
                    DodajPrzedLubZa(&_l, number, gdzie, opcja, ktore);
                } else {
                    printf("Niepoprawna opcja\n");
                }
                printf("\n");
                break;
            case 7:
                //funkcja usuwajaca wskazany element
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                printf("\n1 - usun tylko pierwszy napotkany\n");
                printf("2 - usun kazdy napotkany\n");
                printf("wybierz opcje: ");
                scanf("%d", &opcja);
                UsunWskazany(&_l, number, opcja);
                printf("\n");
                break;


            case 10:
                //wyswietlanie listy
                printf("\n");
                printf("jak ma byc wyswietlana lista?");
                printf("\n1 - od poczatku\n");
                printf("2 - od konca\n");
                printf("podaj wybor: ");
                scanf("%d", &opcja);
                if (opcja == 1) WyswietlListeOdPoczatku(_l);
                if (opcja == 2) WyswietlListeOdKonca(_l);
                printf("\n");
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
