#include <bits/stdc++.h>
using namespace std;
int inp_map[100][100];
int visited[100][100];
vector<pair<int, int>> cheese;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int cnt;
int cheese_size;
int N,M;

void dfs(int y, int x) {
    if (inp_map[y][x] == 1) {
        cheese.push_back(make_pair(y, x));
        visited[y][x] = 1;
        return;
    }
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx] == 0) dfs(ny, nx);
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> inp_map[i][j];
        }
    }

    while(true) {
        fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
        dfs(0, 0);
        if (cheese.empty()) break;
        cnt++;
        cheese_size = cheese.size();
        for (pair<int, int> chee : cheese) {
            int y = chee.first;
            int x = chee.second;
            inp_map[y][x] = 0;
        }
        cheese.clear();
    }

    cout << cnt << "\n" << cheese_size << "\n";
    return 0;
}