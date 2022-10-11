#include <iostream>
#include <string>
using namespace std;
#include <stack>

bool isBalanced(string expression)
{
    // Write your code here

    stack<char> paran;
    for (int i = 0; i < expression.length(); i++)
    {
        if (paran.empty())
        {
            paran.push(expression[i]);
        }
        else if (paran.top() == '(' && expression[i] == ')' || paran.top() == '{' && expression[i] == '}' || paran.top() == '[' && expression[i] == ']')
        {
            paran.pop();
        }
        else
        {
            paran.push(expression[i]);
        }
    }
    if (paran.empty())
    {
        return 1;
    }
    return 0;
}
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}