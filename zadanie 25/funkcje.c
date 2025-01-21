#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

lista StworzNode(int wierzcholek, int waga)
{
    lista nowy = malloc(sizeof(elList));
    nowy->key = wierzcholek;
    nowy->weight = waga;
    nowy->next = NULL;
    return nowy;
}

// tworze krawedz od src do dest o wadze weight
void DodajKrawedz(lista* graph, int src, int dest, int weight)
{
    lista nowy = StworzNode(dest, weight);
    nowy->next = graph[src];
    graph[src] = nowy;
}

// funkcja zwracajaca wierzcholek o najmniejszym dystansie
int MinDystans(int* dist, int* visited, int V)
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// glowna funkcja algorytmu Dijkstry
void Dijkstra(lista* graph, int V, int start)
{
    int* dist = malloc(V * sizeof(int));
    int* visited = malloc(V * sizeof(int));

    // inicjalizacja tablicy dystansow i tablicy odwiedzonych wierzcholkow
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    // dystans od zrodla do samego siebie wynosi 0
    dist[start] = 0;


    // petla glowna algorytmu
    for (int count = 0; count < V - 1; count++)
    {
        // wybieram wierzcholek o najmniejszym dystansie
        int u = MinDystans(dist, visited, V);
        // oznaczam go jako odwiedzony
        visited[u] = 1;

        // dla kazdego sasiada wierzcholka u
        lista temp = graph[u];
        // jesli sasiad nie byl odwiedzony i dystans do niego jest mniejszy niz obecny dystans
        // to aktualizuje dystans
        while (temp != NULL)
        {
            int v = temp->key;
            int weight = temp->weight;

            if (visited[v] == 0 && dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }
    
    printf("Wierzcholek \t Odleglosc od zrodla\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }

    free(dist);
    free(visited);
}
