#include <iostream>
using namespace std;

void isConnected(int **graph, int V, bool *visited, int sv)
{
    visited[sv] = true;
    for (int i = 0; i < V; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (graph[sv][i] == 1 && !visited[i])
        {
            isConnected(graph, V, visited, i);
        }
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    isConnected(graph, V, visited, 0);
    int i = 0;
    for (i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            cout << "false";
            break;
            ;
        }
    }
    if (i == V)
    {
        cout << "true";
    }
    delete[] visited;
    for (int i = 0; i < V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}