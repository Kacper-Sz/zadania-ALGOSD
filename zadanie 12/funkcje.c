#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"


void WyswietlListeOdPoczatku(lista l)
{
    if(l == NULL)
    {
        printf("lista jest pusta\n");
        return;
    }

    lista q = l;
    do
    {
        printf("%d ", q->klucz);
        q = q->nast;
    } while(q != l);
    printf("\n");
}

void DodajNaPoczatek(lista *l, int number)
{
    lista nowa = malloc(sizeof(elListy));

    if(*l == NULL)
    {
        nowa->klucz = number;
        nowa->nast = nowa;
        *l = nowa;
    }
    else
    {
        nowa->klucz = (*l)->klucz;
        (*l)->klucz = number;
        nowa->nast = (*l)->nast;
        (*l)->nast = nowa;
    }
}

void DodajNaKoniec(lista *l, int number)
{
    DodajNaPoczatek(l, number);
    *l = (*l)->nast;
}

void UsunPowtorzenia(lista *l, lista *q)
{
    if (*l == NULL || *q == NULL)
    {
        return;
    }

    lista obecnyQ = *q; // Iterujemy po liście q
    do
    {
        lista poprzedni = NULL; // Wskaźnik do poprzedniego elementu
        lista obecny = *l;      // Iterujemy po liście l
        do
        {
            if (obecny->klucz == obecnyQ->klucz)
            {
                // Znaleziono element do usunięcia
                if (poprzedni == NULL)
                {
                    // Usuwamy pierwszy element w liście
                    lista usuwany = obecny;
                    if (obecny->nast == obecny) // Jedyny element w liście
                    {
                        *l = NULL;
                    }
                    else
                    {
                        // Przesunięcie głowy i aktualizacja cyklu
                        lista koniec = *l;
                        while (koniec->nast != *l)
                        {
                            koniec = koniec->nast;
                        }
                        koniec->nast = obecny->nast;
                        *l = obecny->nast;
                    }
                    obecny = obecny->nast;
                    free(usuwany);
                }
                else
                {
                    // Usuwanie środka lub końca
                    poprzedni->nast = obecny->nast;
                    lista usuwany = obecny;
                    obecny = obecny->nast;
                    free(usuwany);
                }
            }
            else
            {
                // Przesuwanie wskaźników
                poprzedni = obecny;
                obecny = obecny->nast;
            }
        } while (obecny != *l); // Przejście przez całą listę l

        obecnyQ = obecnyQ->nast; // Przejście do kolejnego elementu w liście q
    } while (obecnyQ != *q); // Przejście przez całą listę q
}
