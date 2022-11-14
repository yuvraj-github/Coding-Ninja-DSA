#include <bits/stdc++.h>
using namespace std;
#include <vector>
// void ratInMaize(int n) {

// }
int main()
{

    // Write your code here
    int n;
    cin >> n;
    vector<vector<int>> maize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maize[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << maize[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}
