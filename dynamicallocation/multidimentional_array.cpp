
#include<iostream>
using namespace std;

int main() {
    int m,n;
    cin>>m >> n;

    int **p = new int *[m];
    for(int i; i<m; i++) {
        p[i] = new int[n];
        for(int j=0; j<n; j++) {
            cin>>p[i][j];
        }
    }
    for(int i; i<m; i++) {       
        for(int j=0; j<n; j++) {
            cout<<p[i][j]<<endl;
        }
    }

    for(int i=0; i<m; i++) {
        delete [] p[i];
    }
    delete [] p;
}