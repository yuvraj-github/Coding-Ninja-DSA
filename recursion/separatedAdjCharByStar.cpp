/**
 *
 * Sample Input 1 : hello
 *
 * Sample Output 1: hel*lo
 **/

#include <iostream>
#include <string.h>
using namespace std;

void pairStar(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return;
    }
    pairStar(input + 1);
    if (input[0] == input[1])
    {
        int i = strlen(input);
        while (i >= 1)
        {
            input[i + 1] = input[i];
            i--;
        }
        input[1] = '*';
        pairStar(input + 3);
    }
}
int main()
{
    char input[50];
    cin >> input;
    pairStar(input);
    cout << input << endl;
}