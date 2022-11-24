#include <iostream>
#include <vector>
using namespace std;

bool getPath(int **edges, int n, bool *visited, int v1, int v2, vector<int> &res)
{
    if (v1 == v2)
    {
        res.push_back(v1);
        return true;
    }
    visited[v1] = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && edges[v1][i] == 1)
        {
            if (getPath(edges, n, visited, i, v2, res))
            {
                res.push_back(v1);
                return true;
            }
        }
    }
    return false;
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
    vector<int> res;
    if (getPath(edges, V, visited, v1, v2, res))
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
    delete[] visited;
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}