#include <iostream>
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
void printPossibleCodes(string input, string output)
{
    if (input.size() == 0)
    {
        cout<<output<<endl;
        return;
    }    
    char smallOutput1 = intToChar(charToInt(input[0]));
    printPossibleCodes(input.substr(1), output+smallOutput1);
    if (charToInt(input[0]) * 10 + charToInt(input[1]) >= 10 && charToInt(input[0]) * 10 + charToInt(input[1]) <= 26)
    {
        char smallOutput2 = intToChar(charToInt(input[0]) * 10 + charToInt(input[1]));
        printPossibleCodes(input.substr(2), output+smallOutput2);
    }  
}
void printAllPossibleCodes(string input)
{
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output[1000];
    printPossibleCodes(input, "");
}
int main()
{
    string input;
    cin >> input;
    printAllPossibleCodes(input);
}