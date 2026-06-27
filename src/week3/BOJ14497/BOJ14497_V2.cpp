#include <bits/stdc++.h>
using namespace std;
int visited[300][300];
char inp[300][300];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N,M,jx, jy, tx,ty;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> jy >> jx >> ty >> tx;
    jy--;jx--;ty--;tx--;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++){
            inp[i][j] = s[j];
        }
    }


    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({jy, jx});
    visited[jy][jx] = 1;

    while(true) {
        queue<pair<int, int>> next_q;
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first == ty && p.second == tx) {
                cout << cnt << '\n';
                return 0;
            }
            for (int i=0; i<4; i++) {
                int ny = p.first + dy[i];
                int nx = p.second + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (visited[ny][nx]) continue;
                if (inp[ny][nx] == '1') {
                    next_q.push({ny, nx});
                    visited[ny][nx] = 1;
                } else {
                    q.push({ny, nx});
                    visited[ny][nx] = 1;
                }
            }
        }
        cnt++;
        q = next_q;
    }

    cout << cnt << '\n';

    return 0;
}