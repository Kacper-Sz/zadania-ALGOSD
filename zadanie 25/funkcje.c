#include <stdio.h>

#include "funkcje.h"

Node* StworzNode(int wierzcholek, int waga)
{
    Node *nowy = malloc(sizeof(Node));
    nowy->vertex = wierzcholek;
    nowy->weight = waga;
    nowy->next = NULL;
    return nowy;
}

void DodajKrawedz(Node *lista, int wierzcholek, int waga)
{
    Node *nowy = StworzListe(wierzcholek, waga);
    nowy->next = lista;
    lista = nowy;

    Node *temp = lista;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nowy;
}