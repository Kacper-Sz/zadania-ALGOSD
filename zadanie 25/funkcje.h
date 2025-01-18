#include <stdio.h>

typedef struct Node
{
    int vertex;
    int weight;
    struct Node *next;
} Node;

Node* StworzNode(int wierzcholek, int waga);

void DodajKrawedz(Node *lista, int wierzcholek, int waga);