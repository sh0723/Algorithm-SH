#include <bits/stdc++.h>
using namespace std;
int N,visited[1001];
vector<vector<int>> inj;
vector<bool> ret;
void dfs(int here) {
    visited[here] = 1;
    for (int next : inj[here]) {
        if (!visited[next]) dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        memset(visited, 0, sizeof(visited));
        int nodes;
        int inp_num;
        cin >> nodes >> inp_num;
        inj.clear();
        inj.resize(nodes + 1);

        for (int j = 0; j < inp_num; j++) {
            int a, b;
            cin >> a >> b;
            inj[a].push_back(b);
            inj[b].push_back(a);
        }

        if (inp_num != nodes - 1) {
            ret.push_back(false);
            continue;
        }

        int cnt = 0;
        for (int j = 1; j <= nodes; j++) {
            if (!visited[j]) {
                dfs(j);
                cnt++;
            }
        }
        if (cnt != 1) {
            ret.push_back(false);
            continue;
        }

        ret.push_back(true);
    }

    for (int i = 0; i < N; i++) {
        if (ret[i]) cout << "tree\n";
        else cout << "graph\n";
    }
}