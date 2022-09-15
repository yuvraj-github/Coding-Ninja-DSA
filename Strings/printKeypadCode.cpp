#include <iostream>
using namespace std;
void print(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    string str[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string smallNumbString = str[num % 10];
    for (int i = 0; i < smallNumbString.size(); i++)
    {
        print(num / 10, smallNumbString[i]+output);
    }
}

void printKeypad(int num)
{
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */

    print(num, "");
}

int main()
{
    int num;
    cin >> num;
    printKeypad(num);
}