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
void DodajElement(drzewo *root, char *value)
{
    if (*root == NULL)
    {
        drzewo nowy = malloc(sizeof(wDrzewoB));
        // strdup alokuje pamiec na nowy string i kopiuje do niej wartosc value
        nowy->wyraz = strdup(value);
        nowy->lewy = nowy->prawy = NULL;
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
            DodajElement(&(*root)->prawy, value);
        }
        else if (str < 0)
        {
            DodajElement(&(*root)->lewy, value);
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
        free(temp->wyraz);
        free(temp);
    }

    return;
}


// 4 szuka elementu w drzewie
drzewo* SzukajElementu(drzewo* root, char *value)
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