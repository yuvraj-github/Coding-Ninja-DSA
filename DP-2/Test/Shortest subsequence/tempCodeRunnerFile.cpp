#include <iostream>
#include <string>
#include <vector>
using namespace std;

int helper(vector<vector<int>> &dp, string s, string v)
{

    if (s.size() == 0)
        return 1550;

    if (v.size() <= 0)
        return 1;

    if (dp[s.size()][v.size()])
        return dp[s.size()][v.size()];
    int i;
    for (i = 0; i < v.size(); i++)
    {

        if (s[0] == v[i])
            break;
    }
    if (i == v.size())
        return 1;

    int option1 = helper(dp, s.substr(1), v);
    int option2 = 1 + helper(dp, s.substr(1), v.substr(i + 1));

    int ans = min(option1, option2);

    dp[s.size()][v.size()] = ans;
    return ans;
}

int solve(string s, string v)
{
    // Write your code here
    vector<vector<int>> dp(s.size() + 1, vector<int>(v.size() + 1, 0));
    int ans = helper(dp, s, v);

    return ans;
}
int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}