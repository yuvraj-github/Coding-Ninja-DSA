#include <iostream>
using namespace std;

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    string str[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int smallNumb = num % 10;
    string smallNumbStr = str[smallNumb];
    int smallOutput = keypad(num / 10, output);
    int ansSize = smallNumbStr.size() * smallOutput;
    string temp[ansSize];
    int k = 0;
    for (int i = 0; i < smallOutput; i++)
    {
        for (int j = 0; j < smallNumbStr.size(); j++)
        {
            temp[k] = output[i] + smallNumbStr[j];
            k++;
        }
    }
    for(int i=0; i<ansSize; i++) {
        output[i] = temp[i];
    }
    return ansSize;
}

int main()
{
    int n;
    cin >> n;
    string *output = new string[1000];
    int count = keypad(n, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    delete[] output;
}