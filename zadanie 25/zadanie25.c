#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    int V = 6; //Zmienna wskazujaca ilosc wierzcholkow

    lista* graph = malloc(V * sizeof(lista));

    for (int i = 0; i < V; i++)
    {
        graph[i] = NULL;
    }

    //miejsce na dodawanie nowych wierzcholkow i krawedzi miedzy nimi w grafie

    DodajKrawedz(graph, 0, 1, 10);
    DodajKrawedz(graph, 0, 4, 1);

    DodajKrawedz(graph, 1, 2, 3);

    DodajKrawedz(graph, 2, 3, 2);
    DodajKrawedz(graph, 2, 4, 1);
    DodajKrawedz(graph, 2, 0, 3);
    
    DodajKrawedz(graph, 3, 0, 8);
    DodajKrawedz(graph, 3, 1, 1);
    DodajKrawedz(graph, 3, 5, 1);
    
    DodajKrawedz(graph, 4, 5, 4);

    DodajKrawedz(graph, 5, 4, 4);
    DodajKrawedz(graph, 5, 3, 1);
    DodajKrawedz(graph, 5, 2, 6);

    Dijkstra(graph, V, 0);

    for (int i = 0; i < V; i++)
    {
        elList* temp = graph[i];
        while (temp != NULL)
        {
            elList* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}