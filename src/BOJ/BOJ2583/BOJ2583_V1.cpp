#include <bits/stdc++.h>
using namespace std;
int M, N, K;
vector<vector<int>> inp_map;
vector<vector<int>> visited;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> result;
int dfs(int y, int x, int size) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N || visited[ny][nx] || !inp_map[ny][nx])
            continue;

        size = dfs(ny, nx, size+1);
    }

    return size;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;

    for (int i = 0; i < M; i++) {
        inp_map.push_back(vector<int>(N, 0));
        visited.push_back(vector<int>(N, 0));
        for (int j = 0; j < N; j++) {
            inp_map[i][j] = 1;
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < K; i++) {
        int sty, stx;
        int edy, edx;
        cin >> stx >> sty >> edx >> edy;
        for (int j=0; j<edy-sty; j++) {
            for (int k=0; k<edx-stx; k++) {
                inp_map[sty+j][stx+k] = 0;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (inp_map[i][j] && !visited[i][j]) {
                result.push_back(dfs(i,j,1));
            }
        }
    }

    cout << result.size() << '\n';

    sort(result.begin(), result.end());
    for (int i : result) {
        cout << i << ' ';
    }



}