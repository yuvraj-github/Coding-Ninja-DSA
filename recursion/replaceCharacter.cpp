/**
 *
 * Sample Input 1 : abacd
 *                  a x
 *
 * Sample Output 1: xbxcd
 **/

#include <iostream>
using namespace std;

void replaceCharacter(char input[], char c1, char c2)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Change in the given input string itself.
     * Taking input and printing output is handled automatically.
     */
    if (input[0] == '\0')
    {
        return;
    }
    replaceCharacter(input + 1, c1, c2);
    if (input[0] == c1)
    {
        input[0] = c2;
    }
}
int main()
{
    char str[100], c1, c2;
    cin >> str;
    cin >> c1;
    cin >> c2;
    replaceCharacter(str, c1, c2);
    cout << str << endl;
}