#include <iostream>
#include <vector>

class Graph {
private:
  int v_ = 0; // Количество вершин
  std::vector<std::vector<int>> adjMatrix; // Матрица смежности

public:
  Graph(int vertices) : v_(vertices) {
    adjMatrix.resize(v_, std::vector<int>(v_, 0)); // Инициализация матрицы нулями
  }

  void addEdge(int u, int v) {
    adjMatrix[u][v] += 1;
    adjMatrix[v][u] += 1;
  }

  void removeEdge(int u, int v) {
    if (adjMatrix[u][v] > 0) {
      adjMatrix[u][v] -= 1;
      adjMatrix[v][u] -= 1;
    }
  }

  void addVertice() {
    if (v_ >= adjMatrix.size()) {
      for (int i = 0; i < v_; ++i) {
        adjMatrix[i].push_back(0);
      }
      adjMatrix.emplace_back(v_ + 1, 0);
     }
    else {
      for (int i = 0; i < v_ + 1; ++i) {
        adjMatrix[i][v_] = 0;
        adjMatrix[v_][i] = 0;
      }
    }
    ++v_;
  }

  void removeVertice(int x) {
    if (x < v_)
    {
      while (x < v_ - 1) {
        for (int i = 0; i < v_; ++i) adjMatrix[i][x] = adjMatrix[i][x + 1];
        for (int i = 0; i < v_; ++i) adjMatrix[x][i] = adjMatrix[x + 1][i];
        ++x;
      }
      --v_;
    }
  }

  void printGraph() {
    for (int i = 0; i < v_; ++i) {
      for (int j = 0; j < v_; ++j) {
        std::cout << adjMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  Graph g(5); // Создаем граф с 5 вершинами
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  g.printGraph(); // Печатаем матрицу смежности

  g.removeVertice(3);
  std::cout << '\n';
  g.printGraph();

  g.addVertice();
  g.addEdge(4, 3);
  g.addEdge(4, 1);
  g.addEdge(4, 2);
  std::cout << '\n';
  g.printGraph();

  return 0;
}