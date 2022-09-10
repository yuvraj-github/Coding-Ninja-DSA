#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(char input[])
{
    // Write your code here
    static int i = 0;
    int strLength = strlen(input);
    if (i >= strLength)
    {
        return true;
    }
    if (input[i] == input[strLength - i - 1])
    {
        i++;
        checkPalindrome(input);
    }
    else
    {
        return false;
    }
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}