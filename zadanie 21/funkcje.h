struct sortowanie
{
    int porownania;
    int przestawienia;
};

typedef struct sortowanie sortowanie;

void sortowanie_rosnaco(int tab[], int rozmiar);

void sortowanie_malejaco(int tab[], int rozmiar);

void sortowanie_babelkowe(int tab[], int rozmiar, sortowanie *wyniki);

void sortowanie_wstawianie(int tab[], int rozmiar, sortowanie *wyniki);

void sortowanie_szybkie(int tab [], int rozmiar, sortowanie *wyniki, int lewy, int prawy);
int partition(int tab[], int lewy, int prawy, sortowanie *wynik);

void sortowanie_shella(int tab [], int rozmiar, sortowanie *wyniki);



int maximum(int tab[], int k, sortowanie *wyniki);
void SortowanieZliczanie(int tab[], int k, sortowanie *wyniki);
