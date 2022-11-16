#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int sumSubset(int arr[], int idx, int sum, int count, string set, int n, int k){
   if(idx == n) {
        if(sum == k) {
           count++;
       }
       return count;
   }
   count = sumSubset(arr, idx+1, sum+arr[idx], count, set+to_string(arr[idx])+",",n,k);
   count = sumSubset(arr, idx+1, sum, count, set,n,k);
   return count;
}
int main() {
    // Write C++ code here
   int t;
   cin>>t;
   while(t--) {
       int size, target;
       cin>>size>>target;
       
       int arr[size];
       for(int i=0; i<size; i++) {
           cin>>arr[i];
       }
       cout<<sumSubset(arr, 0, 0,0,"",size,target)<<endl;
   }

    return 0;
}