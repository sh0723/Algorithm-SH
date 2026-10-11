#include <bits/stdc++.h>
using namespace std;
int N,M;
int max_cnt;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<vector<int>> inp_map;
vector<vector<int>> visited;
vector<pair<int, int>> empty_cells;


void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;

        if (inp_map[ny][nx] == 1)
            continue;
        dfs(ny, nx);
    }
}

void solve(pair<int, int> first, pair<int, int> second, pair<int, int> third) {
    inp_map[first.first][first.second] = 1;
    inp_map[second.first][second.second] = 1;
    inp_map[third.first][third.second] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (inp_map[i][j] == 2 && visited[i][j] == 0) {
                dfs(i, j);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (inp_map[i][j] == 2 || visited[i][j] == 1 || inp_map[i][j] == 1) continue;
            cnt++;
        }
    }
    if (cnt > max_cnt) max_cnt = cnt;
    for (int i = 0; i < visited.size(); i++) {
        fill(visited[i].begin(), visited[i].end(), 0);
    }
    inp_map[first.first][first.second] = 0;
    inp_map[second.first][second.second] = 0;
    inp_map[third.first][third.second] = 0;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        inp_map.push_back(vector<int>());
        visited.push_back(vector<int>());
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            inp_map[i].push_back(temp);
            visited[i].push_back(0);
            if (temp == 0)
                empty_cells.push_back(make_pair(i, j));
        }
    }

    for (int i=0; i<empty_cells.size(); i++) {
        for (int j=i+1; j<empty_cells.size(); j++) {
            for (int k=j+1; k<empty_cells.size(); k++) {
                solve(empty_cells[i], empty_cells[j], empty_cells[k]);
            }
        }
    }

    cout << max_cnt << endl;

    return 0;
}