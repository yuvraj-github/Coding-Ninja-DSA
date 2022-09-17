#include <iostream>
#include <string.h>
using namespace std;

void printPermutationHelper(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; i <= output.length(); i++)
    {
        printPermutationHelper(input.substr(1), output.substr(0, i) + input[0] + output.substr(i));
    }
}
void printPermutations(string input)
{

    /* Don't write main() function.
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question
     */
    printPermutationHelper(input, "");
}
int main()
{
    string input;
    cin >> input;
    printPermutations(input);
}