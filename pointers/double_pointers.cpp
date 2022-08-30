#include<iostream>
using namespace std;

void increment1(int **p) {  // It can not work.
    p = p+1;
}

void increment2(int **p) { // It works.
    *p = *p+1;
}
 
void increment3(int **p) { // It works.
    **p = **p+1;
}
int main() {
    int i = 10;
    int *p = &i;

    int **p2 = &p;
    cout<< p2 << endl;
    cout << &p << endl;

    cout << p << endl;
    cout << *p2 << endl;
    cout << &i << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;
}