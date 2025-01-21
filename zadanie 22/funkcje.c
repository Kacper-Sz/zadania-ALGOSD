#include <stdio.h>
#include <string.h>

#include "funkcje.h"


void heapify(char** tab, int n, int i)
{
    // najwiekszy element
    int najwiekszy = i;
    // po drzewie poruszam sie za pomoca indeksow
    // indeksy lewego i prawego dziecka
    int lewy_index = 2 * i + 1;
    int prawy_index = 2 * i + 2;

    // jesli lewe dziecko jest wieksze niz korzen to staje sie najwiekszym
    if(lewy_index < n && strcmp(tab[lewy_index], tab[najwiekszy]) > 0)
    {
        najwiekszy = lewy_index;
    }
    // analogicznie do poprzedniego
    if(prawy_index < n && strcmp(tab[prawy_index], tab[najwiekszy]) > 0)
    {
        najwiekszy = prawy_index;
    }

    // jesli najwiekszy nie jest korzeniem to zamieniamy miejscami
    if(najwiekszy != i)
    {
        char* temp = tab[i];
        tab[i] = tab[najwiekszy];
        tab[najwiekszy] = temp;
        heapify(tab, n, najwiekszy);
    }
}

// glowna funkcja sortujaca
void hsort(char** tab, int n)
{
    // budujemy kopiec z tablicy
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(tab, n, i);
    }
    // wyciagamy elementy z kopca
    for(int i = n - 1; i > 0; i--)
    {
        // przenosze korzen kopca na koniec tablicy
        char* temp = tab[0];
        tab[0] = tab[i];
        tab[i] = temp;
        // ponownie budujemy kopiec z nowej tablicy
        heapify(tab, i, 0);
    }
}

// wyswietlenie tablicy
void wyswietl(char** tab, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s ", tab[i]);
    }
    printf("\n");
}