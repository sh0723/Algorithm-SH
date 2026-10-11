#include <bits/stdc++.h>
using namespace std;
int R,C,K;
int visited[5][5];
char inp_map[5][5];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ret;
void dfs(int y, int x, int distance){
    if (distance > K || (distance != K && y == 0 && x == C-1) )
        return;
    if (y == 0 && x == C-1 && distance == K) {
        ret += 1;
        return;
    }

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || inp_map[ny][nx] == 'T')
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, distance+1);
        visited[ny][nx] = 0;
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;

    for (int i=0; i<R; i++) {
        string s;
        cin >> s;
        for (int j=0; j<C; j++) {
            inp_map[i][j] = s[j];
        }
    }
    visited[R-1][0] = 1;
    dfs(R-1, 0, 1);

    cout << ret << '\n';

    return 0;
}