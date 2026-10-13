#include <bits/stdc++.h>
using namespace std;
int N,M,sty,stx,edy,edx,ret = INT_MAX;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0,0,-1,1};
char inp_map[1000][1000];
bool used_telpo[10];
vector<pair<int, int>> telpo[10];
int visited[1000][1000];
int bfs(){
    for (int y = 0; y < N; y++) {
        fill(visited[y], visited[y] + M, -1);
    }

    queue<pair<int, int>> q;
    q.push({sty, stx});
    visited[sty][stx] = 0;

    while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();

        if (cy == edy && cx == edx) {
            return visited[cy][cx];
        }

        if (inp_map[cy][cx] >= '0' && inp_map[cy][cx] <= '9') {
            int number = inp_map[cy][cx] - '0';

            if (!used_telpo[number]) {
                used_telpo[number] = true;

                for (auto [ny, nx] : telpo[number]) {
                    if (visited[ny][nx] != -1) continue;

                    visited[ny][nx] = visited[cy][cx] + 1;
                    q.push({ny, nx});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visited[ny][nx] != -1 || inp_map[ny][nx] == '#') continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    return -1;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                telpo[s[j]-'0'].push_back({i,j});
            }
            if (s[j] == 'S') {
                sty = i;
                stx = j;
            }
            if (s[j] == 'E') {
                edy = i;
                edx = j;
            }
            inp_map[i][j] = s[j];
        }
    }



    cout << bfs();

    return 0;
}