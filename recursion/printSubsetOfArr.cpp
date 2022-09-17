#include <iostream>
using namespace std;

void psubset(int input[], int n, int output[], int m)
{
    if (n == 0)
    {
        for (int i = 0; i < m; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }

    int newout[m + 1];
    int i;
    for (i = 0; i < m; i++)
    {
        newout[i] = output[i];
    }
    newout[i] = input[0];
    psubset(input + 1, n - 1, newout, m + 1);
    psubset(input + 1, n - 1, output, m);
}
void printSubsetsOfArray(int input[], int size)
{
    // Write your code here
    int output[0];
    int m = 0;
    psubset(input, size, output, m);
}
int main()
{
    int length, input[20];
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    printSubsetsOfArray(input, length);
}