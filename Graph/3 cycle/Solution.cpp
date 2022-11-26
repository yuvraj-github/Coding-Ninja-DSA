#include <iostream>
using namespace std;

int getCycleCount(int **aj, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check path between i-j
            if (aj[i][j] == 1)
            {
                for (int k = 0; k < n; k++)
                {
                    // check path between j-k , k-i
                    if (aj[j][k] == 1 && aj[k][i] == 1)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count / 6;
}
int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << getCycleCount(graph, n);
    for (int i = 0; i < n; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}