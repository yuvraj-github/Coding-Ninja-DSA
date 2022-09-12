#include <iostream>
using namespace std;

int lengthOfString(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    int smallStrLength = lengthOfString(str + 1);
    return 1 + smallStrLength;
}

int main()
{
    char str[100];
    cin >> str;
    int output = lengthOfString(str);
    cout << output << endl;
}