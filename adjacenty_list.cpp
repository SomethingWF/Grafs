#include<iostream>
#include<vector>
#include<forward_list>

class Graph {
public:
    // Конструктор, принимающий количество вершин
    Graph(int v) {
        v_ = v;
        adjList.resize(v_); // Инициализация списка смежности
    }

    // Метод для добавления ребра
    void addEdge(int x, int y) {
      if (x < v_ && y < v_) {
        if (x != y)
        {
          for (auto bgn = adjList[x].begin(); bgn != adjList[x].end(); ++bgn) {
            if (*bgn == y) {
              std::cout << "Trying to create already existing edge" << std::endl;
              return;
            }
          }
          adjList[x].push_front(y);
          adjList[y].push_front(x);
        }
        else std::cout << "Trying to create a loop" << std::endl;
      }
      else std::cout << "Some of vertices does not exist" << std::endl;
    }

    void removeEdge(int x, int y) {
      if (x < v_ && y < v_) {
        auto bgn_prev = adjList[x].begin();
        auto bgn_curr = adjList[x].begin();
        if ((*bgn_curr) == y) {
          adjList[x].pop_front();
        }
        else {
          ++bgn_curr;
          for (bgn_curr; bgn_curr != adjList[x].end(); ++bgn_curr) {
            if ((*bgn_curr) == y) {
              adjList[x].erase_after(bgn_prev);
              break;
            }
            ++bgn_prev;
          }
        }

        bgn_prev = adjList[y].begin();
        bgn_curr = adjList[y].begin();
        if ((*bgn_curr) == x) {
          adjList[y].pop_front();
        }
        else {
          ++bgn_curr;
          for (bgn_curr; bgn_curr != adjList[y].end(); ++bgn_curr) {
            if ((*bgn_curr) == x) {
              adjList[y].erase_after(bgn_prev);
              break;
            }
            ++bgn_prev;
          }
        }
      }
      else std::cout << "Trying to erase not existing edge" << std::endl;
    }

    void addVertice() {
      if (v_ >= adjList.size()) {
        adjList.emplace_back();
      }
      else {
        adjList[v_].clear();
      }
      ++v_;
    }

    void removeVertice(int x) {
      if (x < v_) {
        for (int i = 0; i < v_; ++i) {
          auto bgn_curr = adjList[i].begin();
          auto bgn_prev = adjList[i].begin();
          if ((*bgn_curr) == x) {
            adjList[i].pop_front();
          }
          else {
            ++bgn_curr;
            for (bgn_curr; bgn_curr != adjList[i].end(); ++bgn_curr) {
              if ((*bgn_curr) == x) {
                adjList[i].erase_after(bgn_prev);
                break;
              }
              ++bgn_prev;
            }
          }
        }
        for (int i = 0; i < v_; ++i) {
          auto bgn = adjList[i].begin();
          for (bgn; bgn != adjList[i].end(); ++bgn) {
            *bgn -= (*bgn > x);
          }
        }
        for (int i = x; i + 1 < v_; ++i) {
          adjList[i] = adjList[i + 1];
        }
        --v_;
      }
      else std::cout << "Trying to remove not existing vertice" << std::endl;
    }

    void merge(int x, int y) {
      for (int i : adjList[x]) {
        bool isExist = false;
        for (int j : adjList[y]) {
          if (i == j) {
            isExist = true;
            break;
          }
        }
        if (isExist == false && i != y) {
          adjList[y].push_front(i);
        }
        isExist = false;
        for (int j : adjList[i]) {
          if (j == y) isExist = true;
        }
        if (isExist == false && i != y) adjList[i].push_front(y);
      }
      removeVertice(x);
    }
    
    // Метод для отображения списка смежности
    void printGraph() {
        for (int v = 0; v < v_; ++v) {
            std::cout << "Vertice " << v << ": ";
            for (int w : adjList[v]) {
                std::cout << w << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int v_; // Количество вершин
    std::vector<std::forward_list<int>> adjList; // Список смежности
};

int main() {
    Graph g(5); // Создаем граф с 5 вершинами

    // Добавляем рёбра
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addVertice();
    g.addEdge(2, 5);
    g.merge(1, 2);

    // Выводим список смежности
    g.printGraph();

    return 0;
}
