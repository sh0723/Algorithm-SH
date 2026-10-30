#include <bits/stdc++.h>
using namespace std;
int H,W,N;
vector<string> inp;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W >> N;
    vector<pair<int, int>> loc(N+1);
    inp.resize(H);

    for (int i=0; i<H; i++) {
        cin >> inp[i];
    }

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (inp[i][j] == 'S') {
                loc[0] = {i,j};
            } else if (inp[i][j] - '0' >= 1 && inp[i][j] - '0' <= 9) {
                loc[inp[i][j] - '0'] = {i,j};
            }
        }
    }

    int t=0;
    vector<vector<int>> visited(H, vector<int>(W,0));
    for (int i=0; i<N; i++) {
        for (auto& row : visited) {
            fill(row.begin(), row.end(), false);
        }
        queue<pair<int, int>> q;
        q.push(loc[i]);
        visited[loc[i].first][loc[i].second] = 1;
        while(!q.empty()) {
            auto[cy, cx] = q.front();
            q.pop();
            for (int j=0; j<4; j++) {
                int ny = cy + dy[j];
                int nx = cx + dx[j];
                if (ny >= H || nx >= W || ny < 0 || nx < 0) continue;
                if (visited[ny][nx] != 0 || inp[ny][nx] == 'X') continue;
                visited[ny][nx] = visited[cy][cx] + 1;
                q.push({ny,nx});
                if (ny == loc[i+1].first && nx == loc[i+1].second) {
                    while(!q.empty()) q.pop();
                    break;
                }
            }
        }
        t += (visited[loc[i+1].first][loc[i+1].second] - 1);
    }

    cout << t;

    return 0;
}