#include<iostream>
using namespace std;
int counter =0;
int count(int n){
    //write your code here
    if(n==0) {
        return counter;
    }    
   int remainingPart = n/10;
   counter++;
   count(remainingPart);
}
int main() {
    int n;
    cin>>n;
    int countNoOfDigits = count(n);
    cout<<countNoOfDigits<<endl;
}