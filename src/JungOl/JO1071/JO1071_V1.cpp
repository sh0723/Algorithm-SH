#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    vector<int> arr;
    cin >> N;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int tar;
    cin >> tar;

    int ret1=0, ret2=0;

    for (int i=0; i<N; i++) {
        if (tar % arr[i] == 0) ret1 += arr[i];
        if (arr[i] % tar == 0) ret2 += arr[i];
    }

    cout << ret1 << '\n' << ret2;

    return 0;
}