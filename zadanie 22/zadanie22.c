#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funkcje.h"

int main()
{
    char* tab[] = {"8", "7", "1", "5", "4", "0", "2", "6", "3"};
    //char* tab_slowa[] = {"Ala", "ma", "kota", "a", "kot", "ma", "Ale"}; 
    //Ala i Ale predzej bo a male to 97 a A duze to 65
    
    int n = sizeof(tab) / sizeof(tab[0]);

    printf("Przed sortowaniem:\n");
    wyswietl(tab, n);

    hsort(tab, n);

    printf("\nPo sortowaniu:\n");
    wyswietl(tab, n);

    return 0;
}