#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> swan;
queue<pair<int, int>> water;
int day;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int water_visited[1501][1501];
int swan_visited[1501][1501];
char lake_map[1501][1501];
int main() {

    int N,M;
    cin >> M >> N;
    bool swan_once = false;
    for (int i=1; i<=M; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=N; j++) {
            lake_map[i][j] = s[j-1];
            if (lake_map[i][j] == 'L' && !swan_once) {
                swan_once = true;
                swan_visited[i][j] = 1;
                swan.push({i, j});
                lake_map[i][j] = '.';
            } else if (lake_map[i][j] != 'X')
            {
                water.push({i,j});
                water_visited[i][j] = 1;
            }
        }
    }

    while(true) {
        queue<pair<int, int>> next_swan;
        queue<pair<int, int>> next_water;

        while(!swan.empty()) {
            pair<int,int> curr_swan = swan.front();
            swan.pop();

            if (lake_map[curr_swan.first][curr_swan.second] == 'L') {
                cout << day << '\n';
                return 0;
            }

            for (int i=0; i<4; i++) {
                int ny = curr_swan.first + dy[i];
                int nx = curr_swan.second + dx[i];
                if (ny < 1 || ny > M || nx < 1 || nx > N) continue;
                if (swan_visited[ny][nx]) continue;

                if (lake_map[ny][nx] == 'X') {
                    next_swan.push(make_pair(ny, nx));
                } else  {
                    swan.push(make_pair(ny, nx));
                }
                swan_visited[ny][nx] = 1;
            }
        }

        while(!water.empty()) {
            pair<int, int> curr_water = water.front();
            water.pop();

            for (int i=0; i<4; i++) {
                int ny = curr_water.first + dy[i];
                int nx = curr_water.second + dx[i];
                if (ny < 1 || ny > M || nx < 1 || nx > N) continue;
                if (water_visited[ny][nx]) continue;
                if (lake_map[ny][nx] == 'X') {
                    next_water.push(make_pair(ny, nx));
                    lake_map[ny][nx] = '.';
                }
                water_visited[ny][nx] = 1;
            }
        }

        swan = next_swan;
        water = next_water;
        day++;
    }



    return 0;
}