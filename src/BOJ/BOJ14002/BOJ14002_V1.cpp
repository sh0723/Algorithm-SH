#include <bits/stdc++.h>
using namespace std;
int arr[1000], cnt[1000], ret=1, idx;
int _prev[1000];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(cnt, cnt+1000, 1);
    fill(_prev, _prev+1000, -1);
    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }


    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j] && cnt[j] + 1 > cnt[i]) {
                cnt[i] = cnt[j] + 1;
                _prev[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    cout << ret << '\n';

    stack<int> stk;
    while(true) {
        if (idx == -1) break;
        stk.push(arr[idx]);
        idx = _prev[idx];
    }

    bool first = true;
    while(stk.size()) {
        if (!first) cout << ' ';
        cout << stk.top();
        first = false;
        stk.pop();
    }
    cout << '\n';


    return 0;
}
