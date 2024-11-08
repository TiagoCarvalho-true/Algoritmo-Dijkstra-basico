import sys

def CalcularDijkstra(grafo, origem):
    distancias = {vertice:sys.maxsize for vertice in grafo}
    distancias[origem] = 0

    visitados = set()

    while visitados != set(grafo.keys()):
        vertice_atual= None
        menor_distancia = sys.maxsize
        for vertice in grafo:
            if vertice not in visitados and distancias[vertice] < menor_distancia:
                vertice_atual = vertice
                menor_distancia = distancias[vertice]

        if vertice_atual is None:
            break

        visitados.add(vertice_atual)

        for vizinho, peso in grafo [vertice_atual].items():
            if vizinho not in grafo:
                raise ValueError(f"O vertice {vizinho} não existe no grafo. ")
        
            nova_distancia = distancias[vertice_atual] + peso
            if nova_distancia < distancias[vizinho]:
                distancias[vizinho] = nova_distancia
    return distancias

grafo = {
    'A':{'B':5,'C':3,'D':2},
    'B':{'A':5,'C':2,'E':4},
    'C':{'A':3,'B':2,'D':1},
    'D': {'A':2, 'C':1, 'E':7},
    'E':{'B': 4, 'D': 7}
}
origem = 'A'

try:
    caminhos_mais_curtos = CalcularDijkstra(grafo, origem)
    print(f"Menores distancias a partir do vertice '{origem}': ")
    for destino, distancia in caminhos_mais_curtos.items():
        print(f"Distancia de {origem}, para {destino}:{distancia}")

except ValueError as e:
    print(e)
    