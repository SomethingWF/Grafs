#include <iostream>
#include <vector>

class Graph {
private:
  int V; // ���������� ������
  int E; // ���������� ����
  std::vector<std::vector<int>> incidenceMatrix; // ������� �������������

public:
  Graph(int vertices, int edges) : V(vertices), E(edges) {
    incidenceMatrix.resize(V, std::vector<int>(E, 0)); // ������������� ������� ������
  }

  void addEdge(int edgeIndex, int u, int v) {
    incidenceMatrix[u][edgeIndex] = 1; // ������� u ���������� �����
    incidenceMatrix[v][edgeIndex] = 1; // ������� v ���������� �����
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
  int vertices = 5; // ���������� ������
  int edges = 7;    // ���������� ����
  Graph g(vertices, edges); // ������� ����

  // ��������� ���� (������ �����, ������� u, ������� v)
  g.addEdge(0, 0, 1);
  g.addEdge(1, 0, 4);
  g.addEdge(2, 1, 2);
  g.addEdge(3, 1, 3);
  g.addEdge(4, 1, 4);
  g.addEdge(5, 2, 3);
  g.addEdge(6, 3, 4);

  g.printGraph(); // �������� ������� �������������
  return 0;
}
