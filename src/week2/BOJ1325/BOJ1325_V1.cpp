#include <bits/stdc++.h>
using namespace std;
int visited[10000];
vector<vector<int>> relation;
int N,M;
int max_cnt = -1;
vector<int> ret;

int dfs(int here) {
    visited[here] = 1;
    int ret = 1;

    for (int i : relation[here]) {
        if (visited[i]) continue;
        ret += dfs(i);
    }

    return ret;
}

int main() {

    cin >> N >> M;
    relation = vector<vector<int>>(N+1);

    for (int i = 0; i < M; i++) {
        int A,B;
        cin >> A >> B;
        relation[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        fill(visited, visited + N + 1, 0);
        int cnt = dfs(i);
        if (cnt > max_cnt) {
            ret.clear();
            max_cnt = cnt;
            ret.push_back(i);
        } else if (cnt == max_cnt) {
            ret.push_back(i);
        }
    }

    for (int i : ret) {
        cout << i << " ";
    }


    return 0;
}