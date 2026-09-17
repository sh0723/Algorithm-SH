#include <bits/stdc++.h>
using namespace std;
int N,M;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int arr[50][50], visited[50][50];
int dp[50][50];
bool cycle;
int dfs(int y, int x) {
    if (y >= N || x >= M || y < 0 || x < 0 || arr[y][x] == -1) {
        return 0;
    }

    if (visited[y][x]) {
        cycle = true;
        return 0;
    }

    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    visited[y][x] = 1;
    dp[y][x] = 0;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i] * arr[y][x];
        int nx = x + dx[i] * arr[y][x];

        dp[y][x] = max(dp[y][x], 1 + dfs(ny,nx));
    }

    visited[y][x] = 0;

    return dp[y][x];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        for (int j=0; j<M; j++) {
            if (temp[j] != 'H')
                arr[i][j] = (int)(temp[j] - '0');
            else
                arr[i][j] = -1;
        }
    }

    int ret = dfs(0,0);

    if (cycle) {
        cout << -1 << '\n';
        return 0;
    }

    cout << ret << '\n';

    return 0;
}
