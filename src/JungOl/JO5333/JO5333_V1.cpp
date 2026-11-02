#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> inp(N);
    map<int,int> idx;

    for (int i=0; i<N; i++) {
        cin >> inp[i];
    }

    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        idx[tmp] = i;
    }

    int move_cnt = 0;
    int bef_idx = 0;
    for (int i=0; i<N; i++) {
        if (idx[inp[i]] >= bef_idx) {
            bef_idx = idx[inp[i]];
            continue;
        }
       move_cnt++;
    }

    cout << move_cnt;

    return 0;
}