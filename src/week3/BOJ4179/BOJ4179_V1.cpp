#include <bits/stdc++.h>
using namespace std;
int N,M;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int min_exit = INT_MAX;
vector<vector<int>> inp_map;
vector<vector<int>> fires_map;
vector<vector<pair<int,int>>> fires;
vector<vector<int>> visited;
bool can_exit = false;
void fire_flood(int level) {
    for (int f=0; f<fires[level].size(); f++) {
        int y = fires[level][f].first;
        int x = fires[level][f].second;
        fires_map[y][x] = 1;
        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && nx >= 0 && ny < N && nx < M && inp_map[ny][nx] != 0 && inp_map[ny][nx] != 2) {
                fires_map[ny][nx] = 1;
                fires[level+1].push_back(make_pair(ny,nx));
            }
        }
    }
}
void return_flood(int level) {
    for (int f=0; f<fires[level].size(); f++) {
        fires_map[fires[level][f].first][fires[level][f].second] = 0;
    }
}
void dfs(int y, int x, int level) {
    if (y == N-1 || x == M-1 || y == 0 || x == 0) {
        can_exit = true;
        min_exit = min(min_exit, level);
        return;
    }
    visited[y][x] = 1;
    fires.push_back(vector<pair<int,int>>());
    fire_flood(level);
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && nx >= 0 && ny < N && nx < M && inp_map[ny][nx] != 0) {
            if (inp_map[ny][nx] == 1 && visited[ny][nx] == 0) {
                dfs(ny, nx, level+1);
            }
        }
    }
    return_flood(level+1);
    fires.pop_back();

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fires.push_back(vector<pair<int,int>>());
    cin >> N;
    cin >> M;
    int sty, stx;
    for (int i=0; i<N; i++) {
        inp_map.push_back(vector<int>());
        fires_map.push_back(vector<int>(M,0));
        visited.push_back(vector<int>(M,0));
        string temp;
        cin >> temp;
        for (int j=0; j<M; j++) {
            if (temp[j] == '#')
                inp_map[i].push_back(0);
            else if (temp[j] == 'F') {
                inp_map[i].push_back(2);
                fires[0].push_back(make_pair(i,j));
            } else if (temp[j] == 'J') {
                inp_map[i].push_back(3);
                sty = i, stx = j;
            } else
                inp_map[i].push_back(1);
        }
    }

    dfs(sty,stx,0);
    if (can_exit) cout << min_exit+1;
    else cout << "IMPOSSIBLE";



    return 0;
}
