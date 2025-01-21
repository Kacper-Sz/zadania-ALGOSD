#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "funkcje.h"

int main()
{
    srand(time(NULL));
    int M = 1000;

    int tab_nieposortowana[1000];
    int tab_kopia[1000];
    int tab_rosnaco[1000];
    int tab_malejaco[1000];


    for(int i=0; i<M; i++)
    {
        tab_nieposortowana[i] = rand() % 1000;
    }

    memcpy(tab_rosnaco, tab_nieposortowana, sizeof(tab_nieposortowana));
    memcpy(tab_malejaco, tab_nieposortowana, sizeof(tab_nieposortowana));
    
    sortowanie_rosnaco(tab_rosnaco,M);
    sortowanie_malejaco(tab_malejaco,M);

    sortowanie wynik_babelkowe_nieposortowana = {0, 0};
    sortowanie wynik_wstawianie_nieposortowana = {0, 0};
    sortowanie wynik_szybkie_nieposortowana = {0, 0};
    sortowanie wynik_shella_nieposortowana = {0, 0};

    sortowanie wynik_babelkowe_rosnaco = {0, 0};
    sortowanie wynik_wstawianie_rosnaco = {0, 0};
    sortowanie wynik_szybkie_rosnaco = {0, 0};
    sortowanie wynik_shella_rosnaco = {0, 0};

    sortowanie wynik_babelkowe_malejaco = {0, 0};
    sortowanie wynik_wstawianie_malejaco = {0, 0};
    sortowanie wynik_szybkie_malejaco = {0, 0};
    sortowanie wynik_shella_malejaco = {0, 0};


    // sortowanie nieposortowanej
    memcpy(tab_kopia, tab_nieposortowana, sizeof(tab_nieposortowana));
    sortowanie_babelkowe(tab_kopia, M, &wynik_babelkowe_nieposortowana);

    memcpy(tab_kopia, tab_nieposortowana, sizeof(tab_nieposortowana));
    sortowanie_wstawianie(tab_kopia, M, &wynik_wstawianie_nieposortowana);

    memcpy(tab_kopia, tab_nieposortowana, sizeof(tab_nieposortowana));
    sortowanie_szybkie(tab_kopia, M, &wynik_szybkie_nieposortowana, 0, M - 1);

    memcpy(tab_kopia, tab_nieposortowana, sizeof(tab_nieposortowana));
    sortowanie_shella(tab_kopia, M, &wynik_shella_nieposortowana);

    // sortowanie rosnaco
    memcpy(tab_kopia, tab_rosnaco, sizeof(tab_rosnaco));
    sortowanie_babelkowe(tab_kopia, M, &wynik_babelkowe_rosnaco);

    memcpy(tab_kopia, tab_rosnaco, sizeof(tab_rosnaco));
    sortowanie_wstawianie(tab_kopia, M, &wynik_wstawianie_rosnaco);

    memcpy(tab_kopia, tab_rosnaco, sizeof(tab_rosnaco));
    sortowanie_szybkie(tab_kopia, M, &wynik_szybkie_rosnaco, 0, M - 1);

    memcpy(tab_kopia, tab_rosnaco, sizeof(tab_rosnaco));
    sortowanie_shella(tab_kopia, M, &wynik_shella_rosnaco);

    // sortowanie malejaco
    memcpy(tab_kopia, tab_malejaco, sizeof(tab_malejaco));
    sortowanie_babelkowe(tab_kopia, M, &wynik_babelkowe_malejaco);

    memcpy(tab_kopia, tab_malejaco, sizeof(tab_malejaco));
    sortowanie_wstawianie(tab_kopia, M, &wynik_wstawianie_malejaco);

    memcpy(tab_kopia, tab_malejaco, sizeof(tab_malejaco));
    sortowanie_szybkie(tab_kopia, M, &wynik_szybkie_malejaco, 0, M - 1);

    memcpy(tab_kopia, tab_malejaco, sizeof(tab_malejaco));
    sortowanie_shella(tab_kopia, M, &wynik_shella_malejaco);

    printf("SORTOWANIE NIEPOSORTOWANEJ\n");
    printf("Sortowanie babelkowe (nieposortowana): przestawienia = %d, porownania = %d\n", wynik_babelkowe_nieposortowana.przestawienia, wynik_babelkowe_nieposortowana.porownania);
    printf("Sortowanie przez wstawianie (nieposortowana): przestawienia = %d, porownania = %d\n", wynik_wstawianie_nieposortowana.przestawienia, wynik_wstawianie_nieposortowana.porownania);
    printf("Sortowanie szybkie (nieposortowana): przestawienia = %d, porownania = %d\n", wynik_szybkie_nieposortowana.przestawienia, wynik_szybkie_nieposortowana.porownania);
    printf("Sortowanie Shella (nieposortowana): przestawienia = %d, porownania = %d\n", wynik_shella_nieposortowana.przestawienia, wynik_shella_nieposortowana.porownania);
    printf("\n");

    printf("SORTOWANIE ROSNACEJ\n");
    printf("Sortowanie babelkowe (rosnaco): przestawienia = %d, porownania = %d\n", wynik_babelkowe_rosnaco.przestawienia, wynik_babelkowe_rosnaco.porownania);
    printf("Sortowanie przez wstawianie (rosnaco): przestawienia = %d, porownania = %d\n", wynik_wstawianie_rosnaco.przestawienia, wynik_wstawianie_rosnaco.porownania);
    printf("Sortowanie szybkie (rosnaco): przestawienia = %d, porownania = %d\n", wynik_szybkie_rosnaco.przestawienia, wynik_szybkie_rosnaco.porownania);
    printf("Sortowanie Shella (rosnaco): przestawienia = %d, porownania = %d\n", wynik_shella_rosnaco.przestawienia, wynik_shella_rosnaco.porownania);
    printf("\n");

    printf("SORTOWANIE MALEJACEJ\n");
    printf("Sortowanie babelkowe (malejaco): przestawienia = %d, porownania = %d\n", wynik_babelkowe_malejaco.przestawienia, wynik_babelkowe_malejaco.porownania);
    printf("Sortowanie przez wstawianie (malejaco): przestawienia = %d, porownania = %d\n", wynik_wstawianie_malejaco.przestawienia, wynik_wstawianie_malejaco.porownania);
    printf("Sortowanie szybkie (malejaco): przestawienia = %d, porownania = %d\n", wynik_szybkie_malejaco.przestawienia, wynik_szybkie_malejaco.porownania);
    printf("Sortowanie Shella (malejaco): przestawienia = %d, porownania = %d\n", wynik_shella_malejaco.przestawienia, wynik_shella_malejaco.porownania);
    return 0;
}