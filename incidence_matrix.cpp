#include <iostream>
#include <vector>

class Graph {
private:
  int V; // Количество вершин
  int E; // Количество рёбер
  std::vector<std::vector<int>> incidenceMatrix; // Матрица инцидентности

public:
  Graph(int vertices, int edges) : V(vertices), E(edges) {
    incidenceMatrix.resize(V, std::vector<int>(E, 0)); // Инициализация матрицы нулями
  }

  void addEdge(int edgeIndex, int u, int v) {
    incidenceMatrix[u][edgeIndex] = 1; // Вершина u инцидентна ребру
    incidenceMatrix[v][edgeIndex] = 1; // Вершина v инцидентна ребру
  }

  void printGraph() {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < E; ++j) {
        std::cout << incidenceMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  int vertices = 5; // Количество вершин
  int edges = 7;    // Количество рёбер
  Graph g(vertices, edges); // Создаем граф

  // Добавляем рёбра (индекс ребра, вершина u, вершина v)
  g.addEdge(0, 0, 1);
  g.addEdge(1, 0, 4);
  g.addEdge(2, 1, 2);
  g.addEdge(3, 1, 3);
  g.addEdge(4, 1, 4);
  g.addEdge(5, 2, 3);
  g.addEdge(6, 3, 4);

  g.printGraph(); // Печатаем матрицу инцидентности
  return 0;
}
