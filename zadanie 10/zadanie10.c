#include <stdio.h>
#include <stdlib.h>

#include "funkcjeA.h"
#include "funkcjeB.h"

int main()
{
    int choice, number, gdzie, opcja;
    
    lista _l = 0;
    listaB _lB = 0;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");
        printf("1 - A - wyswietl zawartosc listy\n");
        printf("2 - A - dodaj element na poczatku listy\n");
        printf("3 - A - dodaj element na koncu listy\n");
        printf("4 - A - usun pierwszy element listy\n");
        printf("5 - A - usun ostatni element listy\n");
        printf("6 - A - odszukaj zadany element\n");
        printf("7 - A - dodaj element przed\n");\
        printf("8 - A - dodaj element za\n");
        printf("9 - A - usun wskazany element\n");
        printf("\n");
        printf("------------------------------------\n");
        printf("11 - B - wyswietl zawartosc listy\n");
        printf("12 - A - dodaj element na poczatku listy\n");
        printf("13 - A - dodaj element na koncu listy\n");
        printf("14 - A - usun pierwszy element listy\n");
        printf("15 - A - usun ostatni element listy\n");
        printf("16 - A - odszukaj zadany element\n");
        printf("17 - A - dodaj element przed\n");\
        printf("18 - A - dodaj element za\n");
        printf("19 - A - usun wskazany element\n");
        
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
                if (opcja == 1) WyswietlListeOdPoczatkuA(_l);
                if (opcja == 2) WyswietlListeOdKoncaA(_l);
                break;
            case 2:
                //funkcja dodawania na poczatku listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaPoczatekA(&_l, number);
                printf("\n");
                printf("dodano na poczatek listy");
                printf("\n");
                break;
            case 3:
                //funkcja dodawania na koncu listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaKoniecA(&_l, number);
                printf("\n");
                printf("dodano na koniec listy");
                printf("\n");
                break;
            case 4:
                //funkcja usuwania pierwszego elementu listy
                printf("\n");
                UsunPierwszyA(&_l);
                printf("\n");
                break;
            case 5:
                //funkcja usuwania ostatniego elementu listy
                printf("\n");
                UsunOstatniA(&_l);
                printf("\n");
                break;
            case 6:
                ///funkcja odszukujaca zadany element
                printf("\n");
                printf("podaj liczbe ktora chcesz odszukac: ");
                scanf("%d", &number);
                lista *znalezionyA = OdszukajElementA(&_l, number);
                if(znalezionyA != NULL)
                {
                    printf("znaleziono element %d\n", (*znalezionyA)->klucz);
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
                DodajPrzedA(&_l, number, gdzie);
                printf("\n");
                break;
            case 8:
                //funkcja dodajaca za wskazanym elementem
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac jako nowy element: ");
                scanf("%d", &number);
                printf("\npodaj liczbe za ktora ma byc dodany nowy element: ");
                scanf("%d", &gdzie);
                DodajZaA(&_l, number, gdzie);
                printf("\n");
                break;
            case 9:
                //funkcja usuwajaca wskazany element
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazanyA(&_l, number);
                printf("\n");
                break;
            case 11:
                //wyswietlanie listy
                printf("\n");
                printf("jak ma byc wyswietlana lista?");
                printf("\n1 - od poczatku\n");
                printf("2 - od konca\n");
                printf("podaj wybor: ");
                scanf("%d", &opcja);
                printf("\n");
                if (opcja == 1) WyswietlListeOdPoczatkuB(_lB);
                if (opcja == 2) WyswietlListeOdKoncaB(_lB);
                break;
            case 12:
                //funkcja dodawania na poczatku listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaPoczatekB(&_lB, number);
                printf("\n");
                printf("dodano na poczatek listy");
                printf("\n");
                break;
            case 13:
                //funkcja dodawania na koncu listy
                printf("\n");
                printf("podaj liczbe ktora ma byc dodana: ");
                scanf("%d", &number);
                DodajNaKoniecB(&_lB, number);
                printf("\n");
                printf("dodano na koniec listy");
                printf("\n");
                break;
            case 14:
                //funkcja usuwania pierwszego elementu listy
                printf("\n");
                UsunPierwszyB(&_lB);
                printf("\n");
                break;
            case 15:
                //funkcja usuwania ostatniego elementu listy
                printf("\n");
                UsunOstatniB(&_lB);
                printf("\n");
                break;
            case 16:
                ///funkcja odszukujaca zadany element
                printf("\n");
                printf("podaj liczbe ktora chcesz odszukac: ");
                scanf("%d", &number);
                listaB *znalezionyB = OdszukajElementB(&_lB, number);
                if(znalezionyB != NULL)
                {
                    printf("znaleziono element %d\n", (*znalezionyB)->klucz);
                }
                else
                {
                    printf("nie znaleziono elementu %d\n", number);
                }
                printf("\n");
                break;
            case 17:
                //funkcja dodajaca przed wskazanym elementem
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac jako nowy element: ");
                scanf("%d", &number);
                printf("\npodaj liczbe przed ktora ma byc dodany nowy element: ");
                scanf("%d", &gdzie);
                DodajPrzedB(&_lB, number, gdzie);
                printf("\n");
                break;
            case 18:
                //funkcja dodajaca za wskazanym elementem
                printf("\n");
                printf("podaj liczbe ktora chcesz dodac jako nowy element: ");
                scanf("%d", &number);
                printf("\npodaj liczbe za ktora ma byc dodany nowy element: ");
                scanf("%d", &gdzie);
                DodajZaB(&_lB, number, gdzie);
                printf("\n");
                break;
            case 19:
                //funkcja usuwajaca wskazany element
                printf("\n");
                printf("podaj liczbe ktora chcesz usunac: ");
                scanf("%d", &number);
                UsunWskazanyB(&_lB, number);
                printf("\n");
                break;
            default:
                printf("\n");
                printf("wybierz poprawne odpowiednia liczbe\n");
        }
    }

    return 0;

}
