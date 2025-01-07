#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funkcje.h"

// 1 wypisuje drzewo
void Wypisz(drzewo T,int lvl)
{
    // jesli drzewo jest puste to nic nie robie
    if(T==0)
    {
        return;
    }
    // rekurencyjnie wypisuje prawe poddrzewo
    Wypisz(T->prawy,lvl+1);

    int i;
    // wypisuje tyle tabow ile wynosi poziom
    for(i=0;i<lvl;i++)
    {
        printf("\t");
    }
    // wypisuje wyraz jaki jest w wezle drzewa
    printf("%s\n",T->wyraz);
    // rekurencyjnie wypisuje lewe poddrzewo
    Wypisz(T->lewy,lvl+1);
}

void DrukujDrzewo(drzewo root)
{
    // jesli drzewo jest puste to o tym informuje
    if(root == NULL)
    {
        printf("Drzewo jest puste\n");
        return;
    }
    // wypisuje drzewo z poziomem 0
    Wypisz(root,0);
    printf("\n");
}


// 2 dodaje element do drzewa
void DodajElement(drzewo *root, char *value, drzewo rodzic)
{
    // jesli drzewo jest puste to tworez glowny element
    if (*root == NULL)
    {
        drzewo nowy = malloc(sizeof(wDrzewoB));
        // strdup alokuje pamiec na nowy string i kopiuje do niej wartosc value
        nowy->wyraz = strdup(value);
        // prawe i lewe poddrzewo sa puste
        nowy->lewy = nowy->prawy = NULL;

        // rodzic wskazuje na rodzica
        nowy->rodzic = rodzic;

        // drzewo wskazuje na nowy element
        *root = nowy;
    }
    else
    {
        // strcmp porownuje dwa stringi
        // jesli str > 0 to znaczy ze
        // value jest wieksze od (*root)->wyraz czyli dodaje do prawego
        // jesli str < 0 to znaczy ze dodaje do lewego
        // jak jest rowne to jest ten sam wyraz
        int str = strcmp(value, (*root)->wyraz);

        // czyli jak wyraz jest wiekszy to dodaje do prawego
        if (str > 0)
        {
            DodajElement(&(*root)->prawy, value, *root);
        }
        // jak mniejszy to dodaje do lewego
        else if (str <= 0)
        {
            DodajElement(&(*root)->lewy, value, *root);
        }
    }
}


// 3 usuwa element z drzewa
void UsunElement(drzewo *root, char *value)
{
    // szuka elementu w drzewie i zwraca wskaznik na niego
    drzewo *element = SzukajElementu(root, value);

    // jesli nie znaleziono elementu to nic nie robie
    if(element == NULL)
    {
        return;
    }

    // jesli element jest ostatnim elementem w drzewie
    if((*element)->lewy == NULL && (*element)->prawy == NULL)
    {
        // to zwalniam pamiec
        // najpierw wyraz bo jest alokowany przez strdup
        free((*element)->wyraz);
        // potem zwalniam pamiec dla elementu
        free(*element);
        *element = NULL;
    }
    // jesli element ma jedno dziecko
    else if((*element)->lewy == NULL || (*element)->prawy == NULL)
    {
        // tworze nowy wskaznik na element
        drzewo temp = *element;

        // jak element ma prawe dziecko to na niego wskazuje
        if((*element)->lewy == NULL)
        {
            *element = (*element)->prawy;
        }
        // jak lewe to na lewe
        else
        {
            *element = (*element)->lewy;
        }

        // zmianiam rodzica 
        if (*element != NULL)
        {
            (*element)->rodzic = temp->rodzic;
        }

        // zwalniam pamiec dla wyrazu i elementu znalezionego elemntu do usuniecia
        free(temp->wyraz);
        free(temp);
    }
    // wezel ma dwoje dzieci
    else
    {
        // szukam nastepnika elementu ktory chce usunac
        drzewo *nastepnik = &(*element)->prawy;
        while ((*nastepnik)->lewy != NULL)
        {
            nastepnik = &(*nastepnik)->lewy;
        }

        // przepisanie wyrazu z nastepnika do elementu
        // najpierw zwalniam pamiec dla wyrazu elementu bo jest alokowany przez strdup
        free((*element)->wyraz);
        // alokuje pamiec na nowy wyraz i przepisuje do niego wyraz z nastepnika
        (*element)->wyraz = strdup((*nastepnik)->wyraz);

        // zapisuje wskaznik na nastepnika zeby potem go usunac
        drzewo temp = *nastepnik;
        // przepisuje wskaznik na nastepnika na jego prawe dziecko
        *nastepnik = (*nastepnik)->prawy;

        // jezeli nastepnik ma prawe dziecko to zmieniam rodzica
        if (*nastepnik != NULL)
        {
            (*nastepnik)->rodzic = temp->rodzic;
        }

        // zwalniam pamiec dla wyrazu i elementu nastepnika
        free(temp->wyraz);
        free(temp);
    }

    return;
}


// 4 szuka elementu w drzewie
drzewo* SzukajElementu(drzewo *root, char *value)
{
    // dopoki drzewo nie jest puste
    while(*root != NULL)
    {
        // porownuje wyraz szukany z wyrazem w wezle
        int str = strcmp(value, (*root)->wyraz);

        // jak jest rowne to znalazlem element
        if(str == 0)
        {
            return root;
        }
        // jak strcmp wyszlo wieksze od 0 to ide w prawo
        else if(str > 0)
        {
            root = &(*root)->prawy;
        }
        // jak mniejsze to ide w lewo
        else if(str < 0)
        {
            root = &(*root)->lewy;
        }
    }
    // jak nie znalazlem elementu to zwracam NULL
    return NULL;
}


// 5 zwraca minimum z drzewa
char* Minimum(drzewo root)
{
    if (root != NULL)
    {
        // dopoki istnieje lewe poddrzewo to ide w lewo
        while(root->lewy != NULL)
        {
            root = root->lewy;
        }
    }
    // zwracam wyraz
    return root->wyraz;
}


// 6 zwraca maksimum z drzewa
char* Maksimum(drzewo root)
{
    if (root != NULL)
    {
        // dopoki istnieje prawe poddrzewo to ide w prawo
        while(root->prawy != NULL)
        {
            root = root->prawy;
        }
    }

    // zwracam wyraz
    return root->wyraz;
}


// 7 zwraca poprzednika wskazanego elementu mozna kozystac z poprzednika
drzewo Poprzednik(drzewo root)
{
    // poprzednik to maksymalny element z lewego poddrzewa

    // jesli drzewo jest puste to zwracam NULL
    if(root == NULL)
    {
        return NULL;
    }

    // jak istnieje lewe poddrzewo to ide w lewo
    if(root->lewy != NULL)
    {
        drzewo obecny = root->lewy;

        // ide w prawo do konca
        while(obecny->prawy != NULL)
        {
            obecny = obecny->prawy;
        }

        // zwracam element
        return obecny;
    }

    // jak nie ma lewego poddrzewa

    // tworze dodatkowy wskaznik na rodzica
    drzewo rodzic = root->rodzic;
    // dopoki istnieje rodzic i root jest lewym dzieckiem
    while(rodzic != NULL && root == rodzic->lewy)
    {
        // ide w gore
        root = rodzic;
        rodzic = rodzic->rodzic;
    }
    // zwracam rodzica
    return rodzic;
}


// 8 zwraca nastepnika wskazanego elementu mozna kozystac z poprzednika
drzewo Nastepnik(drzewo root)
{
    // nastepnik to minimalny element z prawego poddrzewa

    // jesli drzewo jest puste to zwracam NULL
    if(root == NULL)
    {
        return NULL;
    }

    // jak istnieje prawe poddrzewo to ide w prawo
    if(root->prawy != NULL)
    {
        drzewo obecny = root->prawy;

        // ide w lewo do konca
        while(obecny->lewy != NULL)
        {
            obecny = obecny->lewy;
        }

        // zwracam element
        return obecny;
    }

    // jak nie ma prawego poddrzewa

    // tworze dodatkowy wskaznik na rodzica
    drzewo rodzic = root->rodzic;
    // dopoki istnieje rodzic i root jest prawym dzieckiem
    while(rodzic != NULL && root == rodzic->prawy)
    {
        // ide w gore
        root = rodzic;
        rodzic = rodzic->rodzic;
    }

    // zwracam rodzica
    return rodzic;
}