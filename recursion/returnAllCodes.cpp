#include <iostream>
#include<string.h>
using namespace std;

char intToChar(int intValue)
{
    char charValue = 'a' + intValue - 1;
    return charValue;
}
int charToInt(char str)
{
    int intValue = str - '0';
    return intValue;
}
int getCodes(string input, string output[10000])
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if (input.size() == 0)
    {
        output[0] == "";
        return 1;
    }
    if (input.size() == 1)
    {
        output[0] = intToChar(charToInt(input[0]));
        return 1;
    }
    string result1[10000], result2[10000];
    int size1 = getCodes(input.substr(1), result1);
    int size2 = 0;
    if (charToInt(input[0]) * 10 + charToInt(input[1]) >= 10 && charToInt(input[0]) * 10 + charToInt(input[1]) <= 26)
    {
        size2 = getCodes(input.substr(2), result2);
    }

    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        output[k++] = intToChar(charToInt(input[0])) + result1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        output[k++] = intToChar(charToInt(input[0]) * 10 + charToInt(input[1])) + result2[i];
    }
    return k;
}

int main()
{
    string str;
    cin >> str;
    string output[10000];
    int outputSize = getCodes(str, output);
    for (int i = 0; i < outputSize; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}