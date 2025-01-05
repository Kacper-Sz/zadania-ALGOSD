#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

// wypisuje drzewo
void Wypisz(drzewo T,int lvl)
{
    if(T==0)
    {
        return;
    }
    Wypisz(T->prawy,lvl+1);

    int i;
    for(i=0;i<lvl;i++)
    {
        printf("\t");
    }
    printf("%d\n",T->klucz);
    Wypisz(T->lewy,lvl+1);
}

void DrukujDrzewo(drzewo root)
{
    if(root == NULL)
    {
        printf("Drzewo jest puste\n");
        return;
    }
    Wypisz(root,0);
    printf("\n");
}


// dodanie elementu do drzewa
void DodajElement(drzewo *root, int wartosc, drzewo rodzic)
{
    if (*root == NULL)
    {
        drzewo nowy = malloc(sizeof(wDrzewoB));
        nowy->klucz = wartosc;
        nowy->lewy = nowy->prawy = NULL;
        nowy->rodzic = rodzic;

        *root = nowy;
    }
    else
    {
        if((*root)->klucz > wartosc)
        {
            DodajElement(&(*root)->lewy, wartosc, *root);
        }
        else
        {
            DodajElement(&(*root)->prawy, wartosc, *root);
        }
    }
}

// zwraca minimalny element w drzewie
drzewo Minimum(drzewo root)
{
    if (root != NULL)
    {
        while(root->lewy != NULL)
        {
            root = root->lewy;
        }
    }

    return root;
}

// zwraca nastepnika wskazanego elementu mozna kozystac z poprzednika
drzewo Nastepnik(drzewo root)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->prawy != NULL)
    {
        drzewo obecny = root->prawy;

        while(obecny->lewy != NULL)
        {
            obecny = obecny->lewy;
        }

        return obecny;
    }

    drzewo rodzic = root->rodzic;
    while(rodzic != NULL && root == rodzic->prawy)
    {
        root = rodzic;
        rodzic = rodzic->rodzic;
    }

    return rodzic;
}

// sprawdza czy dwa drzewa sa takie same
int CzyTakieSame(drzewo root1, drzewo root2)
{
    //  zwracam 1 jak drzewa sa takie same
    // zwracam 0 jak drzewa sa rozne

    if(root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }

    drzewo najmniejszy1 = Minimum(root1);
    drzewo najmniejszy2 = Minimum(root2);

    while(najmniejszy1 != NULL && najmniejszy2 != NULL)
    {
        if(najmniejszy1->klucz != najmniejszy2->klucz)
        {
            return 0;
        }
        najmniejszy1 = Nastepnik(najmniejszy1);
        najmniejszy2 = Nastepnik(najmniejszy2);
    }

    // sprawdzam czy oba drzewa sa przejrzane do konca
    if(najmniejszy1 != NULL || najmniejszy2 != NULL)
    {
        return 0;
    }

    return 1;
}