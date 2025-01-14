struct sortowanie
{
    int porownania;
    int przestawienia;
};

typedef struct sortowanie sortowanie;

void sortowanie_babelkowe(int tab[], int rozmiar, sortowanie *wyniki);

void sortowanie_wstawianie(int tab[], int rozmiar, sortowanie *wyniki);