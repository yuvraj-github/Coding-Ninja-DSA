#include<iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int sum = arr[0];
    for(int i=1; i<n;i++) {
        sum+=arr[i];
    }

    /** Sum of n-2 natural numbers.**/
    int sumOfNaturalNumbs = ((n-2)*(n-1))/2;
    return sum-sumOfNaturalNumbs;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int output = findDuplicate(arr, n);
    cout<<output<<endl;
}