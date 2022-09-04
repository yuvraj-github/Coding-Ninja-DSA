#include <iostream>
using namespace std;

void f(const int *p)
{
    // (*p)++; We can't do this here.
}

void g(const int &a)
{
    //  a++; We can't do this here.
}
int main()
{
    int const i = 10;
    // int *p = &i;  // We can't do this.

    int const *p = &i;

    int j = 12; 
    int *p3 = &j;
    f(p3);
    g(j);
    int const *p2 = &j; // Pointer pointing to a constant integer.
    cout << *p2 << endl;
    j++;
    cout << *p2 << endl;

    // If we can pointer to be constant.
    int *const p4 = &j; // Constant pointer pointing to an integer.

    const int r = 5;
    int const *q = &r;
    p++;
    q++;
    //(*q)++;
}