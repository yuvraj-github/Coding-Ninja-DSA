#include<iostream>
using namespace std;

int main() {
    string s = "abc";
    cout<<s<<endl;
    getline(cin, s); // don't break string at space.
    cout<<s[0]<<endl;
    s[0] = 'a';
    string s1 = "mno";
    s += s1;
    cout<<s<<endl;
    cout<<s.size()<<endl; // size and length functions works same.
    cout<<s.length()<<endl;
    cout<<s.substr(3)<<endl;
    cout<<s.substr(3, 2)<<endl; // 3 is index and 2 is length
    cout<<s.find("mn")<<endl;

    string *sp = new string;
    *sp = "def";
    cout<<sp<<endl;
    cout<<*sp<<endl;
}