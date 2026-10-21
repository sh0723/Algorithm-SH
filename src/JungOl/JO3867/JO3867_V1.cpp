#include <bits/stdc++.h>
using namespace std;
long long N,M,low,mid,high,ret;
int dy[4] = {-1,1,0,0,};
int dx[4] = {0,0,1,-1};
vector<vector<long long>> inp;
bool visited[500][500];
vector<pair<int, int>> step_place;
bool solve(int max_dis) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(step_place[0]);
    visited[step_place[0].first][step_place[0].second] = true;

    while(!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();

        long long cur_h = inp[cy][cx];
        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= N || nx >= M || nx < 0 || ny < 0 || visited[ny][nx]) continue;
            if ( abs(cur_h - inp[ny][nx]) > max_dis) continue;
            q.push({ny,nx});
            visited[ny][nx] = true;
        }
    }

    for (auto [y,x] : step_place) {
        if (!visited[y][x]) return false;
    }

    return true;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    inp.resize(N,vector<long long>(M));
    long long max_val=-1, min_val=LONG_MAX;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> inp[i][j];
            if (inp[i][j] > max_val) {
                max_val = inp[i][j];
            }
            if (inp[i][j] < min_val) {
                min_val = inp[i][j];
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int isStepPlace;
            cin >> isStepPlace;
            if (isStepPlace) step_place.push_back({i,j});
        }
    }
    high = max_val - min_val;

    while(high >= low) {
        mid = (high + low) / 2;
        if (solve(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << ret;

    return 0;
}