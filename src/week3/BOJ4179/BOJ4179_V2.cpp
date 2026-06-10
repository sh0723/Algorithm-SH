#include <bits/stdc++.h>
using namespace std;
int N,M;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
vector<vector<char>> inp_map;
int fires[1004][1004];
int human[1004][1004];
queue<pair<int,int>> q;
int ret, sty,stx;
int max_val = INT_MAX;
int main() {

    cin >> N >> M;
    fill(&fires[0][0], &fires[0][0] + 1004 * 1004, max_val);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        inp_map.push_back(vector<char>());
        for (int j = 0; j < M; j++) {
            if (s[j] == 'J') {
                inp_map[i].push_back(s[j]);
                sty = i, stx = j;
            } else if (s[j] == 'F') {
                fires[i][j] = 1;
                inp_map[i].push_back(s[j]);
                q.push(make_pair(i,j));
            } else {
                inp_map[i].push_back(s[j]);
            }
        }
    }

    while(!q.empty()) {
        int y, x;
        tie(y,x) = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (fires[ny][nx] != max_val || inp_map[ny][nx] == '#') continue;
            fires[ny][nx] = fires[y][x] + 1;
            q.push(make_pair(ny,nx));
        }
    }

    human[sty][stx] = 1;
    q.push(make_pair(sty,stx));
    while(!q.empty()) {
        int y,x;
        tie(y,x) = q.front();
        q.pop();
        if (y == N-1 || x == M-1 || y == 0 || x == 0) {
            ret = human[y][x];
            break;
        }
        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (human[ny][nx] || inp_map[ny][nx] == '#') continue;
            if (fires[ny][nx] <= human[y][x] + 1) continue;
            human[ny][nx] = human[y][x] + 1;
            q.push(make_pair(ny,nx));
        }
    }

    if (ret == 0) cout << "IMPOSSIBLE";
    else cout << ret;


    return 0;
}