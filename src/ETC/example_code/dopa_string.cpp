#include <bits/stdc++.h>
using namespace std;
string dopa = "umzunsik";
vector<string> result;
void prefixSum(){
    for (int i=0; i<dopa.size(); i++){
        result.push_back(dopa.substr(0,i));
    }
}
int main() {

    prefixSum();
    //Q1
    cout << result[3] << endl;

    //Q2
    reverse(result[3].begin(), result[3].end());
    cout << result[3] << endl;

    //Q3
    result[3] += dopa;
    cout << result[3] << endl;


    return 0;
}