#include <iostream>
using namespace std;

bool checkAB(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return true;
    }   
    if(input[0] == 'a') {
        return checkAB(input+1);
    } else if(input[0] == 'b' && input[1] == 'b' && (input[2] == 'a' || input[2] == '\0')) {
        return checkAB(input+2);
    } else {
        return false;
    }
}
int main()
{
    char input[100];
    cin >> input;
    bool checkABOccurence = checkAB(input);
    if (checkABOccurence)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}