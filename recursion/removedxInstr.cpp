/**
 *
 * Sample Input 1 : xaxb
 *
 * Sample Output 1: ab
 **/

#include <iostream>
#include <string.h>
using namespace std;

void removeX(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return;
    }
    removeX(input + 1);
    if (input[0] == 'x')
    {
        int l = strlen(input);
        int i = 0;
        while (i < l)
        {
            input[i] = input[i + 1];
            i++;
        }
    }
}

int main()
{
    char input[50];
    cin >> input;
    removeX(input);
    cout << input << endl;
}