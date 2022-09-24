#include<iostream>
using namespace std;
#include "test.cpp"

int main() {
    Student s1(101);
    s1.age = 20;

    Student const s2 = s1;
    cout << s2.getRollNumber();
}