#include <bits/stdc++.h>
using namespace std;
int N;
int input_arr[20][20];
int ret = INT_MAX;
int check(vector<int> a, vector<int> b) {
    int a_sum=0;
    int b_sum=0;

    for (int i=0; i<N/2; i++) {
        for (int j=0; j<N/2; j++) {
            a_sum += input_arr[a[i]][a[j]];
            b_sum += input_arr[b[i]][b[j]];
        }
    }

    return abs(b_sum - a_sum);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> input_arr[i][j];
        }
    }
    for (int i=0; i<(1<<N); i++) {
        if(__builtin_popcount(i) != N / 2) continue;
        vector<int> a,b;
        for (int j=0; j<N; j++) {
            if (i & (1<<j)) a.push_back(j);
            else b.push_back(j);
        }
        ret = min(ret, check(a,b));
    }
    cout << ret;


    return 0;
}