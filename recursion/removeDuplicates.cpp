/**
 *
 * Sample Input 1 : aabccba
 *
 * Sample Output 1: abcba
 **/

#include <iostream>
#include <string.h>
using namespace std;

void removeConsecutiveDuplicates(char *input)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given string itself.
     * No need to return or print anything
     * Taking input and printing output is handled automatically.
     */
    if (input[0] == '\0')
    {
        return;
    }
    removeConsecutiveDuplicates(input + 1);
    if (input[0] == input[1])
    {
        int i = 0;
        while (input[i] != '\0')
        {
            input[i] = input[i + 1];
            i++;
        }
        input[i - 1] = input[i];
    }
}
int main()
{
    char str[100];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str << endl;
}