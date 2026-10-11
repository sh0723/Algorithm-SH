#include <bits/stdc++.h>
using namespace std;
int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> inp_map;
vector<vector<int>> visited;

void BFS(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {

            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (visited[ny][nx] == 0 && inp_map[ny][nx] == 1) {
                    visited[ny][nx] = visited[cy][cx] + 1;
                    q.push(make_pair(ny, nx));
                }

            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        inp_map.push_back(vector<int>());
        visited.push_back(vector<int>());
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++) {
            inp_map[i].push_back(tmp[j]-'0');
            visited[i].push_back(0);
        }
    }

    BFS(0, 0);

    cout << visited[N-1][M-1] << "\n";
    return 0;
}