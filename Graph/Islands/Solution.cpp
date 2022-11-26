#include <iostream>
using namespace std;

void countConnectedHelper(int **graph, bool *visited, int n, int sv)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[sv][i] == 1)
        {
            countConnectedHelper(graph, visited, n, i);
        }
    }
}
int countConnected(int **graph, bool *visited, int n, int sv)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            countConnectedHelper(graph, visited, n, i);
        }
    }
    return count;
}
int main()
{
    // Write your code here
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
    int total = countConnected(graph, visited, V, 0);
    cout << total << endl;
    delete[] visited;
    for (int i = 0; i < V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}