#include <bits/stdc++.h>
using namespace std;
int r,c;
bool swan_visited[1500][1500];
bool water_visited[1500][1500];
char inp[1500][1500];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
queue<pair<int,int> > swan, next_swan;
queue<pair<int,int> > water, next_water;
void clear_queue() {
    swan = next_swan;
    water = next_water;
    next_swan = queue<pair<int,int> >();
    next_water = queue<pair<int,int> >();
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> r >> c;
    bool flag = true;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            inp[i][j] = s[j];
            if (inp[i][j] != 'X') {
                water.push({i,j});
                water_visited[i][j] = true;
            }

            if (inp[i][j] == 'L' && flag) {
                flag = false;
                swan.push({i,j});
                swan_visited[i][j] = true;
                inp[i][j] = '.';
            }
        }
    }
    int cnt = 0;
    while(true) {
        while(!swan.empty()) {
            pair<int, int> curr = swan.front();
            swan.pop();

            if (inp[curr.first][curr.second] == 'L') {
                cout << cnt << '\n';
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                int ny = curr.first + dy[i];
                int nx = curr.second + dx[i];

                if (ny < 0 || nx < 0 || ny >= r || nx >= c || swan_visited[ny][nx]) continue;

                if (inp[ny][nx] == 'X') {
                    swan_visited[ny][nx] = true;
                    next_swan.push({ny,nx});
                } else {
                    swan_visited[ny][nx] = true;
                    swan.push({ny,nx});
                }
            }
        }
        while(!water.empty()) {
            pair<int, int> curr = water.front();
            water.pop();

            for (int i = 0; i < 4; i++) {
                int ny = curr.first + dy[i];
                int nx = curr.second + dx[i];

                if (ny < 0 || nx < 0 || ny >= r || nx >= c || water_visited[ny][nx]) continue;

                if (inp[ny][nx] == 'X') {
                    water_visited[ny][nx] = true;
                    inp[ny][nx] = '.';
                    next_water.push({ny,nx});
                } else {
                    water_visited[ny][nx] = true;
                    water.push({ny,nx});
                }
            }
        }
        clear_queue();
        cnt++;
    }


    return 0;
}