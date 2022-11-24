#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printDFSHelper(int **graph, bool *visited, int n, int sv, vector<int> &ans)
{
    ans.push_back(sv);
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[sv][i] == 1)
        {
            printDFSHelper(graph, visited, n, i, ans);
        }
    }
}
void printDFS(int **graph, bool *visited, int n, int sv)
{
    vector<int> ans;
    printDFSHelper(graph, visited, n, sv, ans);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            printDFS(graph, visited, V, i);
            cout << endl;
        }
    }
    delete[] visited;
    for (int i = 0; i < V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}