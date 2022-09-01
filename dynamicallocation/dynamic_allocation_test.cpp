#include <iostream>
using namespace std;

void updateValue(int *p)
{
    *p = 610 % 255;
    cout << *p <<endl;
}
int main()
{
    char ch = 'A';
    char *pt = &ch;
    updateValue((int *)pt);
    cout << ch;
}