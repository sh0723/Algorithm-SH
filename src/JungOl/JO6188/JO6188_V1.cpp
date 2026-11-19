#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int cur) {
    visited[cur] = true;
    for (int next : adj[cur]) {
        if (visited[next]) continue;
        dfs(next);
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    adj.resize(N+1, vector<int>());

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.resize(N+1, false);
    int ret = 0;
    for (int i=1; i<=N; i++) {
        if(visited[i]) continue;
        dfs(i);
        ret++;
    }

    cout << ret;
    return 0;
}