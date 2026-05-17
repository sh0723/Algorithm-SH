#include <bits/stdc++.h>
using namespace std;
vector<int> littleMan;
vector<int> realMan;
void checkSum() {
    int sum = 0;
    for (int i=0; i<7; i++){
       sum += littleMan[i];
    }

    if (sum == 100) {
        for (int i=0; i<7; i++){
            realMan.push_back(littleMan[i]);
        }
        sort(realMan.begin(), realMan.end());
        for (int i=0; i<7; i++){
            cout << realMan[i] << "\n";
        }
        exit(0);
    }
}
void makePermutation(int n, int r, int depth){
    if(depth == r) {
        checkSum();
        return;
    }

    for (int i=depth; i<n; i++){
        swap(littleMan[i], littleMan[depth]);
        makePermutation(n, r, depth+1);
        swap(littleMan[i], littleMan[depth]);
    }
}
int main() {
    for (int i=0; i<9; i++){
        int temp;
        cin >> temp;
        littleMan.push_back(temp);
    }

    makePermutation(9, 7, 0);
}