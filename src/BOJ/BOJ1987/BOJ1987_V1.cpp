#include <bits/stdc++.h>
using namespace std;
int inp[20][20], visited[20][20];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
map<int,int> ret;
int R,C;
int max_val = INT_MIN;
void dfs(int y, int x, int level) {
    visited[y][x] = 1;
    ret[inp[y][x]] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (visited[ny][nx]) continue;

        if (ret.find(inp[ny][nx]) != ret.end()) continue;
        dfs(ny, nx, level + 1);
    }
    visited[y][x] = 0;
    ret.erase(inp[y][x]);
    max_val = max(max_val, level);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i=0; i<R; i++) {
        string s;
        cin >> s;
        for (int j=0; j<C; j++) {
            inp[i][j] = s[j] - 'A';
        }
    }
    ret[inp[0][0]] = 1;
    dfs(0,0,1);

    cout << max_val << '\n';
    return 0;
}