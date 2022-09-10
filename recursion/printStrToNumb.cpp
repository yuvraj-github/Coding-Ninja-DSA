/**
 *
 * Sample Input 1 : 00001231
 *
 * Sample Output 1 : 1231
 *
 *
 **/

#include <iostream>
#include <string.h>
using namespace std;

int convertStrToNumb(char input[], int n)
{
    if (n == 0)
    {
        return input[n] - '0';
    }
    int smallAns = convertStrToNumb(input, n - 1);
    int a = input[n] - '0';
    cout<<smallAns<<endl;
    return smallAns * 10 + a;
}

int stringToNumber(char input[])
{
    int l = strlen(input);
    return convertStrToNumb(input, l - 1);
}

int main()
{
    char input[50];
    cin >> input;
    int output = stringToNumber(input);
    cout << output << endl;
}