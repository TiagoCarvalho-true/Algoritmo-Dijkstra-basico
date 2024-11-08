#include <stdio.h>
#include <limits.h>

#define NUM_VERTICES 5

int menorDistancia(int distancias[], int visitados[]) {
    int menor = INT_MAX, indice_menor;

    for (int v = 0; v < NUM_VERTICES; v++) {
        if (visitados[v] == 0 && distancias[v] <= menor) {
            menor = distancias[v];
            indice_menor = v;
        }
    }
    return indice_menor;
}

void calcularDijkstra(int grafo[NUM_VERTICES][NUM_VERTICES], int origem) {
    int distancias[NUM_VERTICES];
    int visitados[NUM_VERTICES] = {0};

    for (int i = 0; i < NUM_VERTICES; i++) {
        distancias[i] = INT_MAX;
    }
    distancias[origem] = 0;

    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        int u = menorDistancia(distancias, visitados);
        visitados[u] = 1;

        for (int v = 0; v < NUM_VERTICES; v++) {
            if (!visitados[v] && grafo[u][v] && distancias[u] != INT_MAX &&
                distancias[u] + grafo[u][v] < distancias[v]) {
                distancias[v] = distancias[u] + grafo[u][v];
            }
        }
    }

    printf("Menores distancias a partir do vertice %d:\n", origem);
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("Distancia de %d para %d: %d\n", origem, i, distancias[i]);
    }
}

int main() {
    int grafo[NUM_VERTICES][NUM_VERTICES] = {
        {0, 5, 3, 2, 0},
        {5, 0, 2, 0, 4},
        {3, 2, 0, 1, 0},
        {2, 0, 1, 0, 7},
        {0, 4, 0, 7, 0}
    };
    int origem = 0;

    calcularDijkstra(grafo, origem);

    return 0;
}
