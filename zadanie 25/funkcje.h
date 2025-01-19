#include <stdio.h>

struct el
{
    int key;
    int weight;
    struct el* next;
};

typedef struct el elList;
typedef elList* lista;


lista StworzNode(int wierzcholek, int waga);

void DodajKrawedz(lista* graph, int src, int dest, int weight);

int MinDystans(int* dist, int* visited, int V);

void Dijkstra(lista* graph, int V, int start);