#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> come_cnt(N+1,0);
    vector<int> to(N+1);

    for (int from=1; from<=N; from++) {
        cin >> to[from];
        come_cnt[to[from]]++;
    }

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (come_cnt[i] == 0) q.push(i);
    }

    int cnt = N;
    while(!q.empty()) {
        int go_out = q.front();
        q.pop();
        cnt--;

        come_cnt[to[go_out]]--;
        if (come_cnt[to[go_out]] == 0) {
            q.push(to[go_out]);
        }
    }

    cout << cnt;
    return 0;
}