/** 
 * 
 * Sample Input 1 : xpix
 * 
 * Sample Output 1: x3.14x
 **/

#include <iostream>
#include <string.h>
using namespace std;

void replacePi(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return;
    }
    replacePi(input + 1);
    if (input[0] == 'p' && input[1] == 'i')
    {
        int i = strlen(input);
        while (i >= 2)
        {
            input[i + 2] = input[i];
            i--;
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 4);
    }
}

int main()
{
    char input[50];
    cin >> input;
    replacePi(input);
    cout << input << endl;
}