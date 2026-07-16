#include <bits/stdc++.h>
using namespace std;
int N;
int arr[16][16];
int dp[16][16][3];
vector<pair<int,int>> dirs = {{0,1}, {1,0}, {1,1}};
int dfs(int y, int x, int direction) {
    if (y == N-1 && x == N-1) return 1;

    int &ret = dp[y][x][direction];
    if (ret != -1) return ret;

    int cnt = 0;
    for (int i=0; i<3; i++) {
        int ny = y + dirs[i].first;
        int nx = x + dirs[i].second;
        if (ny >= N || nx >= N) continue;
        if (dirs[i].first == 1 && dirs[i].second == 1) {
            if (arr[ny][x] || arr[y][nx] || arr[ny][nx]) continue;
        } else {
            if (arr[ny][nx]) continue;
            if (direction == 0 && dirs[i].first == 1 && dirs[i].second == 0) continue;
            if (direction == 1 && dirs[i].first == 0 && dirs[i].second == 1) continue;
        }

        cnt += dfs(ny, nx, i);
    }

    return ret = cnt;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }


    memset(dp, -1, sizeof(dp));
    cout << dfs(0,1,0);

    return 0;
}