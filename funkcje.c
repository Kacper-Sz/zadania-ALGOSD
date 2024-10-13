#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void DodajNaPoczatek(lista *l, int klucz)
{
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = klucz;
    nowa->nast = *l;
    *l=nowa;
}

void DodajNaKoniec(lista *l, int klucz)
{
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = klucz;
    nowa->nast = 0;
    while(*l)
    {
        l=&(*l)->nast;
    }
    *l=nowa;
}

void UsunPierwszy(lista *l)
{
    lista poczatek;
    if(*l != 0 )
    {
        poczatek = *l;
        *l = (*l)->nast;
        free(poczatek);
    }
}

void UsunOstatni(lista *l)
{
    if(*l == 0) return;
    while((*l)->nast)
    {
        l=&(*l)->nast;
    }
    free(*l);
    *l=0;
}

void OdszukajElement(lista l, int element)
{
    lista nowa = l;
    int licznik = 0;
    while(nowa) 
    {
        if(nowa->klucz == element)
        {
            licznik++;
            printf("znaleziono element o wartosci %d pod adresem: %p\n", element, nowa);
        }
        nowa = nowa->nast;
    }
    printf("lacznie element: %d, znaleziono %d ", element, licznik);
    if(licznik == 1) printf("raz\n\n");
    else if (licznik == 0) printf("razy, element nie znajduje sie na liscie\n\n");
    else printf("razy\n\n");
}
//OD TEGO MOMENTU MOZNA SIE ZASTANOAWIAC NAD POPRAWA
// OD TEGO MOEMENTU DZIAL DO PIERWSZEGO SPOTKANEGO
void DodajPrzedLubZa(lista *l, int element, int gdzie, int opcja, int ktore)
{
    lista poprzedni = 0;
    lista obecny = *l;
    switch (ktore)
    {
    case 1:
    // DODAWANIE ELEMENTU TYLKO PRZED PIERWSZYM NAPOTKANYM
        lista nowa = (lista)malloc(sizeof(elListy));
        nowa->klucz = element;

        if(*l == 0)
        {
            *l = nowa;
            nowa->nast = 0;
            return;
        }

        while(obecny != 0 && obecny->klucz != gdzie)
        {
            poprzedni = obecny;
            obecny = obecny->nast;
        }

        if(obecny == 0)
        {
            printf("na liscie brak elementu: %d", gdzie);
            free(nowa);
            return;
        }
        //1 dodaje przed
        //2 dodaje za
        if(opcja == 1)
        {
            if(poprzedni)
            {
                poprzedni->nast = nowa;
                nowa->nast = obecny;
            }
            else
            {
                //pokazuja w to samo miejsce
                nowa->nast = *l;
                //pokazuje ze nowa bedzei pierwszym elementem
                *l=nowa;
            }
        }
        else if (opcja == 2)
        {
            nowa->nast = obecny->nast;
            obecny->nast = nowa;
        }
        break;

    case 2:
    // DODAWANIE ELEMENTU PRZED KAZDYM NAPOTKANYM
        while(obecny)
        {
        if (obecny->klucz == gdzie)
        {
            lista nowa = (lista)malloc(sizeof(elListy));
            nowa->klucz = element;

            //1 dodaje przed
            //2 dodaje za
            if (opcja == 1)
            {
                if (poprzedni)
                {
                    poprzedni->nast = nowa;
                    nowa->nast = obecny;
                }
                else
                {
                    nowa->nast = *l;
                    *l = nowa;
                }
            }
            else if(opcja == 2)
            {
                nowa->nast = obecny->nast;
                obecny->nast = nowa;
            }
        }

        poprzedni = obecny;
        obecny = obecny->nast;
        }
        break;
    default:
        printf("bledna opcja");
        break;
    }

}

void UsunWskazany(lista *l, int number, int opcja)
{
    if (*l == 0)
    {
        printf("lista pusta brak elementu: %d", number);
        return;
    }

    
    lista obecny = *l;
    lista poprzedni = 0;
    if (obecny && obecny->klucz == number)
    {
        *l = obecny->nast;
        free(obecny);
        obecny = *l;
        printf("usunieto eleemnt: %d", number);
        //OPCJA 1 USUNIECIE TYLKO PIERWSZEGO SPOTKANEGO
        if (opcja == 1) return;
    }

    switch (opcja)
    {
    //OPCJA 1 USUNIECIE TYLKO PIERWSZEGO SPOTKANEGO
    case 1:
        while(obecny != 0 && obecny->klucz != number)
        {
            poprzedni = obecny;
            obecny = obecny->nast;
        }

            if (obecny == NULL) {
                printf("element %d nie znajduje sie na liscie.\n", number);
                return;
            }

        poprzedni->nast=obecny->nast;
        free(obecny);
        printf("usunieto element %d\n", number);
        break;
    //OPCJA 2 USUN KAZDY KOLEJNY
    case 2:
        while(obecny)
        {
             if (obecny->klucz == number)
            {
                poprzedni->nast = obecny->nast;
                free(obecny);
                obecny = poprzedni->nast;
                printf("Usunięto element: %d\n", number);
            }
            else
            {
                poprzedni = obecny;
                obecny = obecny->nast;
            }
        }
        break;
    default:
        break;
    }
 
}


//DODAC WYSWIETLANIE OD KONCA LISTY

void WyswietlListeOdPoczatku(lista l)
{
    lista nowa = l;
    while (nowa)
    {
        printf("%d ", nowa->klucz);
        nowa = nowa->nast;
    }
    printf("\n\n");    
}

void WyswietlListeOdKonca(lista l)
{
    lista nowa = l;
    lista odwrotna = 0;
    while(nowa)
    {
        DodajNaPoczatek(&odwrotna, nowa->klucz);
        nowa = nowa->nast;
    }
    WyswietlListeOdPoczatku(odwrotna);
}