/** 
 * Stack memory is small. (Static memory allocation). Automatically memory release.
 * Heap memory concept is used in this programming. (Dynamic memory allocation). Manual release of memory is required.
 * delete is used to release dynamically allocated memory.
 * 
 **/

#include<iostream>
using namespace std;

int main() {
    int *p = new int;
    //delete p;  in case of single variable. (single element deletion)
    *p = 10;
    cout << *p << endl;

    int n;
    cout << "Enter num of elements" << endl;
    cin>>n;

    int* arr = new int[n];
    //delete [] p; in case of array. (array deletion)
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }
    int max = -1;
    for(int i=0; i<n; i++) {
        if(max<arr[i]) {
            max= arr[i];
        }
    }
    cout<< max << endl;
}