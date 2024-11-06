#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

class Graph {
public:
  Graph();
  void addVertex();
  void addEdge(int u, int v);
  void removeEdge(int u, int v);
  void removeVertex(int v);
  void mergeVertices(int u, int v);
  void printGraph();

private:
  std::vector<std::list<int>> adjList; // Список смежности
};

Graph::Graph() {}

void Graph::addVertex() {
  adjList.emplace_back(); // Добавляем новую вершину с пустым списком смежности
}

void Graph::addEdge(int u, int v) {
  if (u >= adjList.size() || v >= adjList.size()) {
    std::cout << "One or both vertices do not exist." << std::endl;
    return;
  }
  adjList[u].push_back(v);
  adjList[v].push_back(u); // Для неориентированного графа
}

void Graph::removeEdge(int u, int v) {
  if (u >= adjList.size() || v >= adjList.size()) {
    std::cout << "One or both vertices do not exist." << std::endl;
    return;
  }
  adjList[u].remove(v);
  adjList[v].remove(u); // Для неориентированного графа
}

void Graph::removeVertex(int v) {
  if (v >= adjList.size()) {
    std::cout << "Vertex does not exist." << std::endl;
    return;
  }

  // Удаляем все рёбра, связанные с вершиной v
  for (int i = 0; i < adjList.size(); ++i) {
    adjList[i].remove(v); // Удаляем v из списка смежности всех вершин
  }

  // Удаляем вершину v из списка смежности
  adjList.erase(adjList.begin() + v);
}

void Graph::mergeVertices(int u, int v) {
  if (u >= adjList.size() || v >= adjList.size()) {
    std::cout << "One or both vertices do not exist." << std::endl;
    return;
  }

  // Переносим все рёбра из v в u
  
  for (auto bgn = adjList[v].begin(); bgn != adjList[v].end(); ++bgn) {
    int neighbor = (*bgn);
    if (neighbor != u && neighbor != v) { // Избегаем добавления u в его собственный список
      adjList[u].push_back(neighbor);
      adjList[neighbor].remove(v); // Удаляем v из списка смежности соседей
      adjList[neighbor].push_back(u); // Добавляем u в список смежности соседей
    }
  }

  // Удаляем вершину v из списка смежности
  adjList[v].clear(); // Очищаем список смежности v
  adjList.erase(adjList.begin() + v); // Удаляем саму вершину v
}

void Graph::printGraph() {
  for (int i = 0; i < adjList.size(); ++i) {
    std::cout << "Vertex " << i << ":";
    for (int neighbor : adjList[i]) {
      std::cout << " " << neighbor;
    }
    std::cout << std::endl;
  }
}

int main() {
  Graph g;

  // Добавляем вершины
  g.addVertex(); // 0
  g.addVertex(); // 1
  g.addVertex(); // 2
  g.addVertex(); // 3
  g.addVertex(); // 4

  // Добавляем рёбра
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  std::cout << "Graph before any operations:" << std::endl;
  g.printGraph();

  // Удаляем ребро
  g.removeEdge(1, 4);
  std::cout << "Graph after removing edge (1, 4):" << std::endl;
  g.printGraph();

  // Удаляем вершину
  g.removeVertex(2);
  std::cout << "Graph after removing vertex 2:" << std::endl;
  g.printGraph();

  // Сливаем вершины
  g.mergeVertices(1, 3);
  std::cout << "Graph after merging vertices 1 and 3" << std::endl;
  g.printGraph();

  return 0;
}
