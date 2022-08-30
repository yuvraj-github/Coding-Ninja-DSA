#include<iostream>
using namespace std;

void getOutput(int *p) {
    cout << *p << endl;
}

/** Pass by value. **/
void incrementPointer(int *p) {
    p = p+1;
}

void increment(int *p) {
    (*p)++;
}
int main() {
    int i=10;
    int *p = &i;

    getOutput(p);

    cout << p << endl;
    incrementPointer(p);
    cout << p << endl;

    cout << *p << endl;
    increment(p);
    cout << *p << endl;
}