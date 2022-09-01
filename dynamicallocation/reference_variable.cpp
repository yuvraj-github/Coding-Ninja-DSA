#include<iostream>
using namespace std;

/* Pass by reference.*/
void increment(int& n) {
    n++;
}

int main() {
    int i =10;
    increment(i);
    cout << i << endl;
    int &j = i; //Reference variable.

    i++;
    cout << j <<endl;
    j++;
    cout<< i << endl;

    int k = 100;
    j = k;
    cout << i << endl;
}