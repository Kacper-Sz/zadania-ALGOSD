#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"


//wyswietlanie listy
void WyswietlListeOdPoczatku(lista l)
{
    lista nowa = l;
    if(nowa == 0)
    {
        printf("\nlista jest pusta\n");
        return;
    }
    while (nowa)
    {
        if(nowa->klucz == INT_MAX)
        {
            printf("Wartownik");
            nowa = nowa->nast;
            continue;
        }
        printf("%d ", nowa->klucz);
        nowa = nowa->nast;
    }
    printf("\n\n");    
}

void DodanieWartownika(lista *l)
{
    //alokacja pamieci dla wartownika
    lista wartownik = malloc(sizeof(elListy));
    wartownik->klucz = INT_MAX;
    //dodam na koniec wiec pole nast to 0
    wartownik->nast = 0;
    //dopoki nie znajdziemy ostatniego elementu
    while(*l)
    {
        l=&(*l)->nast;
    }
    //przypisanie ostatniego elementu jako wartownika
    *l=wartownik;
}

//dodanie elementu do listy uporzadkowanej z wartownikiem
void DodajDoPosortowanejWartownik(lista *l, int klucz)
{
    //alokacja pamieci dla nowego elementu
    lista nowa = malloc(sizeof(elListy));
    nowa->klucz = klucz;

    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    //zawsze bedzei wiekszy bo jest wartownik
    while((*l)->klucz < klucz)
    {
        l = &((*l)->nast);
    }

    //dodajemy element przed elementem wiekszym
    nowa->nast = *l;
    *l = nowa;
}

elListy* ZnajdzPosortowanaWartownik(lista l, int klucz)
{
    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while((l)->klucz < klucz)
    {
        l = ((l)->nast);
    }
    //jesli element jest rowny
    if((l)->klucz == klucz)
    {
        return l;
    }
    else
    {
        return NULL;
    }
}

lista PobierzListe(char* nazwaPliku)
{
    FILE *plik = fopen(nazwaPliku, "r");
    int liczba;
    lista l = 0;

    if(plik == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 0;
    }

    DodanieWartownika(&l);

    while(fscanf(plik, "%d", &liczba) != EOF)
    {
        DodajDoPosortowanejWartownik(&l, liczba);
    }
    fclose(plik);
    return l;
}


// uzywajac przykaldowych list powinno wyjsc:
// wynikL: 1 3 6
// wynikQ: 8 9 10
void PorownajListy(lista l, lista q, lista *wynikL, lista *wynikQ)
{
    lista elementL = l;
    lista elementQ = q;
    lista tmp = 0;

    // przejscie przez liste l

    while(elementL != NULL && elementL->klucz != INT_MAX)
    {
        tmp = ZnajdzPosortowanaWartownik(q, elementL->klucz);
        if(tmp == NULL)
        {
            DodajDoPosortowanejWartownik(wynikL, elementL->klucz);
        }
        elementL = elementL->nast;
    }

    // przejscie przez liste q
    while(elementQ != NULL && elementQ->klucz != INT_MAX)
    {
        tmp = ZnajdzPosortowanaWartownik(l, elementQ->klucz);
        if(tmp == NULL)
        {
            DodajDoPosortowanejWartownik(wynikQ, elementQ->klucz);
        }
        elementQ = elementQ->nast;
    }
    
}