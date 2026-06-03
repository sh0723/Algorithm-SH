#include <bits/stdc++.h>
using namespace std;
int N;

int main() {

    cin >> N;
    vector<int> arr = vector<int>(N,0);
    vector<int> ret = vector<int>(N,-1);
    stack<int> stk;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        while (stk.size() && arr[stk.top()] < arr[i]) {
            ret[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i : ret) {
        cout << i << " ";
    }





    return 0;
}