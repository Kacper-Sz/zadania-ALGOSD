#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

//wypisywanie listy od poczatku
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

//dodawanie elementu na poczatek listy
void DodajNaPoczatek(lista *l, int number)
{
    //tworze nowy element
    lista nowa = malloc(sizeof(elListy));

    //kiedy lista pusta to dodaje element
    if(*l == NULL)
    {
        nowa->klucz = number;
        //lista ma byc cykliczna
        //wiec nastepny to ten sam
        nowa->nast = nowa;
        *l = nowa;
    }
    else //kiedy jest wiecej niz jeden element
    {
        nowa->klucz = (*l)->klucz;
        (*l)->klucz = number;
        nowa->nast = (*l)->nast;
        (*l)->nast = nowa;
    }
}

void DodajNaKoniec(lista *l, int number)
{
    //dodanie na poczatek
    DodajNaPoczatek(l, number);
    //przesuniecie glowy na drugi
    *l = (*l)->nast;
}

void UsunPowtorzenia(lista *l, lista *q)
{
    //jezeli ktoras z list jest pusta to nie ma co usuwac
    if (*l == NULL || *q == NULL)
    {
        return;
    }

    //wskaznik na element z listy q
    lista obecnyQ = *q;

    do
    {
        //wskaznik na poprzedni element
        lista poprzedni = NULL;
        //wskaznik na obecny element listy l
        lista obecny = *l;
        //oznaczenia pierwszego przejscia przez liste
        int pierwszaIteracja = 1;

        //jak jest pierwsza iteracja albo obecny element nie jest rowny pierwszemu elementowi listy
        while (pierwszaIteracja || obecny != *l)
        {
            //oznaczenie ze nie jest juz to pierwsza iteracja
            pierwszaIteracja = 0;

            //jak znajde element listy L to przyrownuje go z elementem z listy Q
            if (obecny->klucz == obecnyQ->klucz)
            {
                //jak nie ma poprzedniego elementu to usuwam pierwszy element
                if (poprzedni == NULL)
                {
                    // Usuwamy pierwszy element
                    lista usuwany = obecny;
                    //kiedy jest tylko 1 element w liście
                    if (obecny->nast == obecny) 
                    {
                        *l = NULL;
                        obecny = NULL;
                        //lista staje sie pusta
                    }
                    //kiedy jest wiecej niz 1 element
                    else
                    {
                        //szukam ostatniego elementu
                        lista koniec = *l;
                        while (koniec->nast != *l)
                        {
                            koniec = koniec->nast;
                        }
                        //przypisuje nastepny element jako pierwszy
                        koniec->nast = obecny->nast;
                        *l = obecny->nast;
                        obecny = *l;
                    }
                    //usuwam element
                    free(usuwany);
                }
                //kiedy jest poprzedni element
                else
                {
                    //ustawiam elementy
                    poprzedni->nast = obecny->nast;
                    lista usuwany = obecny;
                    obecny = obecny->nast;
                    free(usuwany);
                }

                //znowu zaczynam od poczatku
                //wiec dalej jest pierwsza iteracja
                pierwszaIteracja = 1;
            }
            //jak element nie jest rowny to ide dalej
            else
            {
                poprzedni = obecny;
                obecny = obecny->nast;
            }

            //kiedy l juz puste to koncze
            if (*l == NULL)
            {
                break;
            }
        }
        //po przejsciu calej listy L to ide do nastepnego elementu z listy Q
        obecnyQ = obecnyQ->nast;
    } while (obecnyQ != *q && *l != NULL); // Iteruj po liście `q` do końca lub dopóki `l` nie jest pusta
}