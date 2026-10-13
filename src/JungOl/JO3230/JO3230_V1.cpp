#include <bits/stdc++.h>
using namespace std;
int N, str, edr, ret;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<pair<int, int>> ret_path;
bool find_ret = false;
void dfs(int cur, int sum_weight) {
    if (cur == edr) {
        ret = sum_weight;
        find_ret = true;
        return;
    }

    for (auto [next , weight] : adj[cur]) {
        if (find_ret) break;
        if (visited[next]) continue;
        visited[next] = true;
        ret_path.push_back({next,weight});
        dfs(next, sum_weight+weight);
        if (find_ret) break;
        ret_path.pop_back();
        visited[next] = false;
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> str >> edr;
    if (N == 1 || str == edr) {
        cout << 0;
        return 0;
    }
    adj.resize(N+1, vector<pair<int, int>>());
    visited.resize(N+1, false);
    for (int i=0; i<N-1; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    visited[str] = true;
    dfs(str,0);

    int max_weight = INT_MIN;
    for (int i=0; i<ret_path.size(); i++) {
        max_weight = max(max_weight, ret_path[i].second);
    }

    cout << ret - max_weight;
    return 0;
}