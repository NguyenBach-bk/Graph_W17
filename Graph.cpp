#include <iostream>

using namespace std;

// Dinh nghia do thi
class Graph
{
private:
  int V;           // So dinh
  int **adjMatrix; // Ma tran ke
  bool *visited;   // Mang danh dau dinh da duyet

public:
  // Khoi tao
  Graph (int vertices)
  {
    V = vertices;

    // Khoi tao ma tran ke voi gia tri 0
    adjMatrix = new int *[V];
    for (int i = 0; i < V; i++)
      {
        adjMatrix[i] = new int[V];
        for (int j = 0; j < V; j++)
          {
            adjMatrix[i][j] = 0;
          }
      }

    // Khoi tao mang danh dau visited
    visited = new bool[V];
    for (int i = 0; i < V; i++)
      {
        visited[i] = false;
      }
  }

  // Them canh
  void
  addEdge (int u, int v)
  {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }

  // Duyet BFS
  void
  BFS (int start)
  {
    // Khoi tao mang danh dau visited
    for (int i = 0; i < V; i++)
      {
        visited[i] = false;
      }

    int queue[100]; // Queue
    int front = 0, rear = 0;

    // Dua dinh bat dau vao hang doi
    queue[rear++] = start;
    visited[start] = true;

    cout << "BFS: ";
    while (front < rear)
      {
        int current = queue[front++];
        cout << current << " ";

        // Duyet cac dinh ke
        for (int i = 0; i < V; i++)
          {
            if (adjMatrix[current][i] == 1 && !visited[i])
              {
                queue[rear++] = i;
                visited[i] = true;
              }
          }
      }
    cout << endl;
  }

  // Duyet DFS (De quy)
  void
  DFSUtil (int v)
  {
    visited[v] = true;
    cout << v << " ";

    // Duyet cac dinh ke
    for (int i = 0; i < V; i++)
      {
        if (adjMatrix[v][i] == 1 && !visited[i])
          {
            DFSUtil (i);
          }
      }
  }

  void
  DFS (int start)
  {
    // Khoi tao mang danh dau visited
    for (int i = 0; i < V; i++)
      {
        visited[i] = false;
      }

    cout << "DFS: ";
    DFSUtil (start);
    cout << endl;
  }

  // Huy giai phong bo nho
  ~Graph ()
  {
    for (int i = 0; i < V; i++)
      {
        delete[] adjMatrix[i];
      }
    delete[] adjMatrix;
    delete[] visited;
  }
};

int
main ()
{
  int V, E;

  cout << "Nhap so dinh: ";
  cin >> V;

  cout << "Nhap so canh: ";
  cin >> E;

  Graph graph (V);

  cout << "Nhap cac canh (u v):" << endl;
  for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      graph.addEdge (u, v);
    }

  int start;
  cout << "Nhap dinh bat dau duyet: ";
  cin >> start;

  graph.BFS (start); // Duyet BFS
  graph.DFS (start); // Duyet DFS

  return 0;
}
