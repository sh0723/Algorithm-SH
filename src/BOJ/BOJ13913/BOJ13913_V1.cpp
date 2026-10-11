#include <bits/stdc++.h>
using namespace std;
stack<int> ret;
int subin, brother;
int curr_val, next_val;
int visited[100001];
int parent[100001];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> brother;
    queue <int> q;
    q.push(subin);
    visited[subin] = 1;
    while (!q.empty()) {
        curr_val = q.front();
        q.pop();
        if (curr_val == brother) {
            break;
        }
        for (int next : {curr_val + 1, curr_val - 1, curr_val * 2}) {
            if (next < 0 || next > 100000) continue;
            if (visited[next]) continue;
            visited[next] = visited[curr_val] + 1;
            parent[next] = curr_val;
            q.push(next);
        }
    }

    cout << visited[brother]-1 << '\n';
    int cur = brother;
    while(true) {
        ret.push(cur);
        if (cur == subin) break;
        cur = parent[cur];
    }

    while(!ret.empty()) {
        cout << ret.top() << ' ';
        ret.pop();
    }


    return 0;
}