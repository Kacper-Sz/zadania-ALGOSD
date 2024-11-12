#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"


// dodanie wartownika
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


//dodawanie na poczatek dla listy uporzadkowanej
void DodajDoPosortowanej(lista *l, int klucz)
{
    //alokacja pamieci dla nowego elementu
    lista nowa = malloc(sizeof(elListy));
    nowa->klucz = klucz;

    //jesli lista jest pusta
    if(*l == 0)
    {
        nowa->nast = *l;
        *l = nowa;
        return;
    }

    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while(*l != NULL && (*l)->klucz < klucz)
    {
        //adres czesci nastepnej
        l = &((*l)->nast);
    }

    //dodajemy element przed elementem wiekszym
    nowa->nast = *l;
    *l = nowa;
}


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



lista* ZnajdzPosortowana(lista *l, int klucz)
{
    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while((*l) != NULL && (*l)->klucz < klucz)
    {
        l = &((*l)->nast);
    }
    //jesli nie ma elementu lub jest wiekszy
    if((*l) == NULL || (*l)->klucz > klucz)
    {
        return NULL;
    }
    else
    {
        return l;
    }
}

lista* ZnajdzPosortowanaWartownik(lista *l, int klucz)
{
    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while((*l)->klucz < klucz)
    {
        l = &((*l)->nast);
    }
    //jesli element jest rowny
    if((*l)->klucz == klucz)
    {
        return l;
    }
    else
    {
        return NULL;
    }
}

void UsunWskazanyPosortowana(lista *l, int number)
{
    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while((*l) != NULL && (*l)->klucz < number)
    {
        l = &((*l)->nast);
    }
    //jesli element jest rowny usuwamy
    if((*l) != NULL && (*l)->klucz == number)
    {
        lista nowa = *l;
        *l = (*l)->nast;
        free(nowa);
    }
    else
    {
        printf("element %d nie znajduje sie na liscie.\n", number);
    }
}

void UsunWskazanyPosortowanaWartownik(lista *l, int number)
{
    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while((*l)->klucz < number)
    {
        //przejscie do nastepnej czesci adresu
        l = &((*l)->nast);
    }

    //jesli element jest rowny usuwamy
    if((*l)->klucz == number)
    {
        lista nowa = *l;
        *l = (*l)->nast;
        free(nowa);
    }
    else
    {
        printf("element %d nie znajduje sie na liscie.\n", number);
    }
}

//zobaczyc jeszcze z cwiczen jak pisalismy te funkcje

lista* ZnajdzPierwszy(lista *l)
{
    //jesli lista jest pusta
   if (l == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    //zwraca pierwszy element
    return l;
}

lista* ZnajdzPierwszyWartownik(lista *l)
{
    //zakladam ze jedyny element to wartownik
    //czy nastepepny element jest nullem ten po wartowniku
    if ((*l)->nast == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    //zwraca pierwszy element
    return l;
}

lista* ZnajdzOstatni(lista *l)
{
    //jesli lista jest pusta
    if (l == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    //ide na koniec listy
    while ((*l)->nast != NULL) {
        l = &((*l)->nast);
    }
    //zwracam ostatni element
    return l;
}

lista* ZnajdzOstatniWartownik(lista *l)
{
    //jesli lista jest pusta
    if ((*l)->nast == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    //ide na koniec listy
    //sprawdzam czy element po wartowniku nie jest nullem
    while ((*l)->nast->nast != NULL) {
        l = &((*l)->nast);
    }
    //zwracam ostatni element
    return l;
}






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