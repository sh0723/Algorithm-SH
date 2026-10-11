#include <bits/stdc++.h>
using namespace std;
int brother, subin;
int visited[100001];
int cnt[100001];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> brother;
    queue<int> q;
    q.push(subin);
    visited[subin] = 1;
    cnt[subin] = 1;
    int now;
    while(!q.empty()) {
        now = q.front();
        q.pop();
        for (int next : {now-1, now+1, now *2}) {
            if (0 <= next && next <= 100000) {
                if (visited[next] == 0) {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] = cnt[now];
                } else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }

            }
        }

    }

    cout << visited[brother]-1 << '\n' << cnt[brother] << '\n';
    return 0;
}