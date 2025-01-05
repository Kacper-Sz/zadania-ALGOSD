#include <stdio.h>

struct DrzewoB
{
    char *wyraz;
    struct DrzewoB *lewy;
    struct DrzewoB *prawy;
    struct DrzewoB *rodzic;
};
typedef struct DrzewoB wDrzewoB;
typedef wDrzewoB* drzewo;

// 1 wypisuje drzewo
void Wypisz(drzewo d,int lvl);
void DrukujDrzewo(drzewo root);

// 2 dodaje element do drzewa
void DodajElement(drzewo *root, char *value, drzewo rodzic);

// 3 usuwa element z drzewa
void UsunElement(drzewo *root, char *value);

// 4 szuka elementu w drzewie
drzewo* SzukajElementu(drzewo *root, char *value);

// 5 zwraca minimum z drzewa
char* Minimum(drzewo root);

// 6 zwraca maksimum z drzewa
char* Maksimum(drzewo root);

// 7 zwraca poprzednika wskazanego elementu mozna kozystac z poprzednika
drzewo Poprzednik(drzewo root);

// 8 zwraca nastepnika wskazanego elementu mozna kozystac z poprzednika
drzewo Nastepnik(drzewo root);

// 9 zapisuje drzewo do pliku
void ZapiszDoPlikuRekurencyjnie(FILE *plik, drzewo root);
int ZapiszDoPliku(drzewo root);

// 10 odczytuje drzewo z pliku
drzewo OdczytajZPliku();