#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> space;
vector<vector<int>> visited;
int N;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int water){
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] || space[ny][nx] <= water) continue;

        dfs(ny, nx, water);
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int max_val = -1;
    for (int i = 0; i < N; i++) {
        space.push_back(vector<int>());
        visited.push_back(vector<int>());
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (temp > max_val) max_val = temp;
            space[i].push_back(temp);
            visited[i].push_back(0);
        }
    }


    int max_cnt = -1;
    for (int k=0; k <= max_val; k++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (space[i][j] > k && !visited[i][j]) {
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }
        if (cnt > max_cnt) max_cnt = cnt;
        fill(visited.begin(), visited.end(), vector<int>(N,0));
    }


    cout << max_cnt << '\n';

    return 0;
}