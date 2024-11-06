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
  std::vector<std::list<int>> adjList; // ������ ���������
};

Graph::Graph() {}

void Graph::addVertex() {
  adjList.emplace_back(); // ��������� ����� ������� � ������ ������� ���������
}

void Graph::addEdge(int u, int v) {
  if (u >= adjList.size() || v >= adjList.size()) {
    std::cout << "One or both vertices do not exist." << std::endl;
    return;
  }
  adjList[u].push_back(v);
  adjList[v].push_back(u); // ��� ������������������ �����
}

void Graph::removeEdge(int u, int v) {
  if (u >= adjList.size() || v >= adjList.size()) {
    std::cout << "One or both vertices do not exist." << std::endl;
    return;
  }
  adjList[u].remove(v);
  adjList[v].remove(u); // ��� ������������������ �����
}

void Graph::removeVertex(int v) {
  if (v >= adjList.size()) {
    std::cout << "Vertex does not exist." << std::endl;
    return;
  }

  // ������� ��� ����, ��������� � �������� v
  for (int i = 0; i < adjList.size(); ++i) {
    adjList[i].remove(v); // ������� v �� ������ ��������� ���� ������
  }

  // ������� ������� v �� ������ ���������
  adjList.erase(adjList.begin() + v);
}

void Graph::mergeVertices(int u, int v) {
  if (u >= adjList.size() || v >= adjList.size()) {
    std::cout << "One or both vertices do not exist." << std::endl;
    return;
  }

  // ��������� ��� ���� �� v � u
  
  for (auto bgn = adjList[v].begin(); bgn != adjList[v].end(); ++bgn) {
    int neighbor = (*bgn);
    if (neighbor != u && neighbor != v) { // �������� ���������� u � ��� ����������� ������
      adjList[u].push_back(neighbor);
      adjList[neighbor].remove(v); // ������� v �� ������ ��������� �������
      adjList[neighbor].push_back(u); // ��������� u � ������ ��������� �������
    }
  }

  // ������� ������� v �� ������ ���������
  adjList[v].clear(); // ������� ������ ��������� v
  adjList.erase(adjList.begin() + v); // ������� ���� ������� v
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

  // ��������� �������
  g.addVertex(); // 0
  g.addVertex(); // 1
  g.addVertex(); // 2
  g.addVertex(); // 3
  g.addVertex(); // 4

  // ��������� ����
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  std::cout << "Graph before any operations:" << std::endl;
  g.printGraph();

  // ������� �����
  g.removeEdge(1, 4);
  std::cout << "Graph after removing edge (1, 4):" << std::endl;
  g.printGraph();

  // ������� �������
  g.removeVertex(2);
  std::cout << "Graph after removing vertex 2:" << std::endl;
  g.printGraph();

  // ������� �������
  g.mergeVertices(1, 3);
  std::cout << "Graph after merging vertices 1 and 3" << std::endl;
  g.printGraph();

  return 0;
}
