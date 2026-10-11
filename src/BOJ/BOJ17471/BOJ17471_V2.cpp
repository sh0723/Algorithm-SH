#include <bits/stdc++.h>
using namespace std;
int N, ret = INT_MAX;
bool selected[11], visited[11];
vector<vector<int>> inj;
int people[11];
pair<int, int> dfs(int here,bool group) {
    visited[here] = true;
    pair<int, int> ret_val = {1, people[here]};
    for (int next : inj[here]) {
        if (selected[next] != group || visited[next]) continue;
        pair<int, int> temp = dfs(next,group);
        ret_val.first += temp.first;
        ret_val.second += temp.second;
    }

    return ret_val;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> people[i];
    }
    inj.resize(N+1);
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            inj[i].push_back(a);
            inj[a].push_back(i);
        }
    }

    for (int i = 1; i<(1 << N)-1; i++) {
        memset(selected, false, sizeof(selected));
        memset(visited, false, sizeof(visited));
        int ast,bst;
        for (int j=0; j<N; j++) {
            if (i & (1 << j)) {
                selected[j+1] = true;
                ast = j+1;
            } else {
                bst = j+1;
            }
        }

        pair<int, int> group_a = dfs(ast, true);
        pair<int, int> group_b = dfs(bst, false);

        if (group_a.first + group_b.first == N) ret = min(ret, abs(group_a.second - group_b.second));
    }

    if (ret == INT_MAX) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}