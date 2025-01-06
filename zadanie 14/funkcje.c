#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funkcje.h"

// 1 wypisuje drzewo
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
    printf("%s\n",T->wyraz);
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


// 2 dodaje element do drzewa
void DodajElement(drzewo *root, char *value, drzewo rodzic)
{
    if (*root == NULL)
    {
        drzewo nowy = malloc(sizeof(wDrzewoB));
        // strdup alokuje pamiec na nowy string i kopiuje do niej wartosc value
        nowy->wyraz = strdup(value);
        nowy->lewy = nowy->prawy = NULL;
        nowy->rodzic = rodzic;

        *root = nowy;
    }
    else
    {
        // strcmp porownuje dwa stringi
        // jesli str > 0 to znaczy ze
        // value jest wieksze od (*root)->wyraz czyli dodaje do prawego
        // jesli str < 0 to znaczy ze dodaje do lewego
        int str = strcmp(value, (*root)->wyraz);

        if (str > 0)
        {
            DodajElement(&(*root)->prawy, value, *root);
        }
        else if (str < 0)
        {
            DodajElement(&(*root)->lewy, value, *root);
        }
    }
}


// 3 usuwa element z drzewa
void UsunElement(drzewo *root, char *value)
{
    drzewo *element = SzukajElementu(root, value);

    if(element == NULL)
    {
        return;
    }

    // jesli element jest ostatnim elementem w drzewie
    if((*element)->lewy == NULL && (*element)->prawy == NULL)
    {
        free((*element)->wyraz);
        free(*element);
        *element = NULL;
    }
    else if((*element)->lewy == NULL || (*element)->prawy == NULL)
    {
        drzewo temp = *element;

        if((*element)->lewy == NULL)
        {
            *element = (*element)->prawy;
        }
        else
        {
            *element = (*element)->lewy;
        }

        if (*element != NULL)
        {
            (*element)->rodzic = temp->rodzic;
        }

        free(temp->wyraz);
        free(temp);
    }
    // wezel ma dwoje dzieci
    else
    {
        drzewo *nastepnik = &(*element)->prawy;
        while ((*nastepnik)->lewy != NULL)
        {
            nastepnik = &(*nastepnik)->lewy;
        }

        // Kopiowanie danych z następnika do elementu
        free((*element)->wyraz);
        (*element)->wyraz = strdup((*nastepnik)->wyraz);

        // Usunięcie następnika
        drzewo temp = *nastepnik;
        *nastepnik = (*nastepnik)->prawy;

        if (*nastepnik != NULL)
        {
            (*nastepnik)->rodzic = temp->rodzic;
        }

        free(temp->wyraz);
        free(temp);
    }

    return;
}


// 4 szuka elementu w drzewie
drzewo* SzukajElementu(drzewo *root, char *value)
{
    while(*root != NULL)
    {
        int str = strcmp(value, (*root)->wyraz);

        if(str == 0)
        {
            return root;
        }
        else if(str > 0)
        {
            root = &(*root)->prawy;
        }
        else if(str < 0)
        {
            root = &(*root)->lewy;
        }
    }

    return NULL;
}


// 5 zwraca minimum z drzewa
char* Minimum(drzewo root)
{
    if (root != NULL)
    {
        while(root->lewy != NULL)
        {
            root = root->lewy;
        }
    }

    return root->wyraz;
}


// 6 zwraca maksimum z drzewa
char* Maksimum(drzewo root)
{
    if (root != NULL)
    {
        while(root->prawy != NULL)
        {
            root = root->prawy;
        }
    }

    return root->wyraz;
}


// 7 zwraca poprzednika wskazanego elementu mozna kozystac z poprzednika
drzewo Poprzednik(drzewo root)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->lewy != NULL)
    {
        drzewo obecny = root->lewy;

        while(obecny->prawy != NULL)
        {
            obecny = obecny->prawy;
        }

        return obecny;
    }

    drzewo rodzic = root->rodzic;
    while(rodzic != NULL && root == rodzic->lewy)
    {
        root = rodzic;
        rodzic = rodzic->rodzic;
    }

    return rodzic;
}


// 8 zwraca nastepnika wskazanego elementu mozna kozystac z poprzednika
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