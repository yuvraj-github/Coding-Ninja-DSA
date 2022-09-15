/** 
 * 
 * subsequece and substring is different. for e.g;
 * substing of abc : ab, bc
 * subsequence of abc: '',b,c,bc,a,ab,ac,abc.
 * 
 * 
 **/

#include<iostream>
using namespace std;

int subConsequences(string input, string output[]) {
    if(input.empty()) {
        output[0] = "";
        return 1;
    }
    string smallString = input.substr(1);
    int smallOutput = subConsequences(smallString, output);
    for(int i=0; i<smallOutput; i++) {
        output[i+smallOutput] = input[0]+output[i];
    }    
    return 2*smallOutput;
}
int main() {
    string str;
    cin>>str;
    string *output = new string[1000];
    int subConsequencesCount = subConsequences(str, output);
    for(int i=0; i<subConsequencesCount; i++) {
        cout<<output[i]<<endl;        
    }
    delete [] output;
}