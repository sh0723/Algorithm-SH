#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> inp_map;
vector<pair<int, int>> lands;
vector<vector<int>> visited;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int L, W;

int main() {

    cin >> L >> W;

    for (int i=0; i < L; i++) {
        inp_map.push_back(vector<int>());
        visited.push_back(vector<int>());
        string temp;
        cin >> temp;
        for (int j=0; j < W; j++) {
            if (temp[j] == 'W')
                inp_map[i].push_back(0);
            else {
                inp_map[i].push_back(1);
                lands.push_back(make_pair(i, j));
            }

            visited[i].push_back(0);
        }
    }

    int max_distance = -1;
    for (pair<int, int> land : lands) {
        queue<pair<int, int>> q;
        q.push(land);
        int distance = 0;
        visited[land.first][land.second] = 1;
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                int ny = p.first + dy[i];
                int nx = p.second + dx[i];

                if (ny >= 0 && nx >= 0 && ny < L && nx < W) {
                    if (inp_map[ny][nx] == 1 && !visited[ny][nx]) {
                        q.push(make_pair(ny, nx));
                        visited[ny][nx] = visited[p.first][p.second] + 1;
                        max_distance = max(max_distance, visited[ny][nx]);
                    }
                }
            }
        }
        fill(visited.begin(), visited.end(), vector<int>(W,0));
    }

    cout << max_distance-1 << '\n';

    return 0;
}