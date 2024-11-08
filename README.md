Aqui está uma documentação simples para o código Python e C do algoritmo de Dijkstra:

---

### Documentação do Código em Python

**Função `CalcularDijkstra(grafo, origem)`**  
Esta função calcula o caminho mais curto a partir de um vértice de origem para todos os outros vértices em um grafo usando o algoritmo de Dijkstra.

- **Parâmetros**:
  - `grafo`: Um dicionário que representa o grafo, onde as chaves são vértices e os valores são dicionários de adjacência. Por exemplo:
    ```python
    {
      'A': {'B': 5, 'C': 3, 'D': 2},
      'B': {'A': 5, 'C': 2, 'E': 4},
      ...
    }
    ```
  - `origem`: O vértice de origem de onde será calculada a menor distância para os demais vértices.

- **Retorno**: Um dicionário contendo as menores distâncias do vértice de origem para cada outro vértice.

- **Exceções**:
  - Levanta `ValueError` se um vértice adjacente não existe no grafo.

- **Exemplo de Uso**:
  ```python
  grafo = {
      'A': {'B': 5, 'C': 3, 'D': 2},
      'B': {'A': 5, 'C': 2, 'E': 4},
      ...
  }
  origem = 'A'
  menores_distancias = CalcularDijkstra(grafo, origem)
  ```

**Explicação do Código**:
1. Inicializa as distâncias de todos os vértices como infinitas (`sys.maxsize`), exceto a origem, que é `0`.
2. Em um loop, escolhe o vértice não visitado com a menor distância conhecida.
3. Para cada vizinho do vértice atual, calcula uma possível nova distância e a atualiza se for menor que a distância registrada.
4. Retorna um dicionário com as menores distâncias para cada vértice.

---

### Documentação do Código em C

**Função `int menorDistancia(int distancias[], int visitados[])`**  
Essa função encontra o vértice não visitado com a menor distância atual.

- **Parâmetros**:
  - `distancias[]`: Um array que contém as distâncias atuais do vértice de origem para cada vértice.
  - `visitados[]`: Um array binário que indica se um vértice já foi visitado.

- **Retorno**: O índice do vértice com a menor distância que ainda não foi visitado.

---

**Função `void calcularDijkstra(int grafo[NUM_VERTICES][NUM_VERTICES], int origem)`**  
Esta função implementa o algoritmo de Dijkstra para encontrar o caminho mais curto a partir de um vértice de origem para todos os outros vértices.

- **Parâmetros**:
  - `grafo`: Uma matriz de adjacência que representa o grafo, onde `grafo[i][j]` é o peso da aresta entre os vértices `i` e `j`.
  - `origem`: O vértice de origem.

- **Exemplo de Uso**:
  ```c
  int grafo[NUM_VERTICES][NUM_VERTICES] = {
      {0, 5, 3, 2, 0},
      {5, 0, 2, 0, 4},
      ...
  };
  calcularDijkstra(grafo, 0);
  ```

**Explicação do Código**:
1. Inicializa as distâncias de todos os vértices como `INT_MAX`, exceto a origem, que é `0`.
2. Usa um loop para iterar pelos vértices e, em cada iteração, escolhe o vértice não visitado com a menor distância.
3. Atualiza as distâncias dos vértices adjacentes ao vértice atual se uma menor distância for encontrada.
4. Após o loop, imprime as menores distâncias da origem para cada vértice.
