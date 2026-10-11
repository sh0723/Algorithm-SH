#include <bits/stdc++.h>
using namespace std;
int N,M;
int jy, jx, ty, tx;
queue<pair<int, int>> q;
char inp[301][301];
int visited[301][301];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin >> jy >> jx >> ty >> tx;
    jy--; jx--; ty--; tx--;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) {
            inp[i][j] = s[j];
        }
    }

    int cnt = 0;
    q.push({jy, jx});
    while(true) {
        queue<pair<int, int>> next_q;
        while(!q.empty()) {
            int qsize = q.size();
            pair<int, int> curr = q.front();
            q.pop();

            if (curr.first == ty && curr.second == tx) {
                cout << cnt << '\n';
                return 0;
            }
            for (int i=0; i<4; i++) {
                int ny = curr.first + dy[i];
                int nx = curr.second + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
                if (inp[ny][nx] != '0') {
                    next_q.push({ny, nx});
                } else {
                    q.push({ny, nx});
                }
                visited[ny][nx] = 1;
            }
        }
        q = next_q;
        cnt++;
    }



    return 0;
}