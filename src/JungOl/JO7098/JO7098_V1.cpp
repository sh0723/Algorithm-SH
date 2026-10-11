#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<int> ret;
vector<int> visited;
int T,N,C;
int solve(int idx, int weight) {
    visited[idx] = 1;
    int ret_val = 0;
    int cnt = 0;
    for (pair<int, int> linked : adj[idx]) {
        if (visited[linked.first]) continue;
        cnt++;
        ret_val += solve(linked.first, linked.second);
    }
    if (cnt == 0) return weight;
    else return min(weight, ret_val);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    ret.resize(T);
    for (int i=0; i<T; i++) {
        cin >> N >> C;
        adj.resize(N+1);
        visited.resize(N+1, 0);
        for (int j=0; j<N-1; j++) {
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        ret[i] = solve(C, INT_MAX);
        adj.clear();
        visited.clear();
    }

    for (int i=0; i<T; i++) cout << ret[i] << '\n';


    return 0;
}