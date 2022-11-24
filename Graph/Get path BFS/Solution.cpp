#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void getPath(int **edges, int n, bool *visited, int v1, int v2)
{
    if (v1 == v2)
    {
        cout << v1 << " ";
        return;
    }
    unordered_map<int, int> map;
    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                if (i == v2)
                {
                    cout << v2 << " ";
                    map[v2] = currentVertex;
                    int j = v2;
                    while (j != v1)
                    {
                        cout << map[j] << " ";
                        j = map[j];
                    }
                    return;
                }
                else
                {
                    pendingVertices.push(i);
                    visited[i] = true;
                    map[i] = currentVertex;
                }
            }
        }
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    int v1, v2;
    cin >> v1 >> v2;
    getPath(edges, V, visited, v1, v2);
    delete[] visited;
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}