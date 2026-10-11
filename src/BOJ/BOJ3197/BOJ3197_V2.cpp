#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> swan;
queue<pair<int, int>> water;

bool water_visited[1500][1500];
bool swan_visited[1500][1500];
char inp[1500][1500];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int R,C;
int main() {

    cin >> R >> C;
    bool find_swan = false;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            inp[i][j] = s[j];
            if (s[j] != 'X') {
                water.push({i, j});
                water_visited[i][j] = true;
            }
            if (s[j] == 'L' && !find_swan) {
                swan.push({i, j});
                find_swan = true;
                inp[i][j] = '.';
                swan_visited[i][j] = true;
            }
        }
    }
    int cnt = 0;
    while(true) {
        queue<pair<int, int>> next_swan;
        queue<pair<int, int>> next_water;
        while(!swan.empty()) {
            pair<int, int> curr_swan = swan.front();
            swan.pop();
            if (inp[curr_swan.first][curr_swan.second] == 'L') {
                cout << cnt << '\n';
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                int ny = curr_swan.first + dy[i];
                int nx = curr_swan.second + dx[i];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C || swan_visited[ny][nx]) continue;
                if (inp[ny][nx] == 'X') {
                    next_swan.push({ny, nx});
                } else {
                    swan.push({ny, nx});
                }
                swan_visited[ny][nx] = true;
            }
        }
        while(!water.empty()) {
            pair<int, int> curr_water = water.front();
            water.pop();
            for (int i = 0; i < 4; i++) {
                int ny = curr_water.first + dy[i];
                int nx = curr_water.second + dx[i];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C || water_visited[ny][nx]) continue;
                if (inp[ny][nx] == 'X') {
                    next_water.push({ny, nx});
                    inp[ny][nx] = '.';
                } else {
                    water.push({ny, nx});
                }
                water_visited[ny][nx] = true;
            }
        }
        cnt++;
        swan = next_swan;
        water = next_water;
    }

    return 0;
}