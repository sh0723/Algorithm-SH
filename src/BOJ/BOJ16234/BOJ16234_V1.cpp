#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> country_map;
vector<vector<int>> visited;
vector<vector<pair<int, int>>> connected_country;
vector<int> avg_people_cnt;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N,L,R;

void dfs(int y, int x, int comp_num, bool &found) {
    visited[y][x] = comp_num;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
            int diff = abs(country_map[ny][nx] - country_map[y][x]);
            if (visited[ny][nx] == 0 && diff >= L && diff <= R) {
                found = true;
                dfs(ny, nx, comp_num, found);
            }
        }
    }
    if (found == false) {
        visited[y][x] = 0;
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for (int i=0; i<N; i++) {
        country_map.push_back(vector<int>());
        visited.push_back(vector<int>());
        for (int j=0; j<N; j++) {
            int temp;
            cin >> temp;
            country_map[i].push_back(temp);
            visited[i].push_back(0);
        }
    }
    int day_cnt = 0;
    while(true) {
        bool not_present = true;
        int comp_num = 1;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (visited[i][j] == 0) {
                    bool found = false;
                    dfs(i, j, comp_num, found);
                    if (found) {
                        comp_num++;
                        not_present = false;
                    }
                }
            }
        }

        if (not_present) break;
        for (int cpn=1; cpn<=comp_num; cpn++) {
            connected_country.push_back(vector<pair<int, int>>());
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    if (visited[i][j] == cpn) {
                        connected_country[cpn-1].push_back({i,j});
                    }
                }
            }
        }
        for (vector<pair<int,int>> comp : connected_country) {
            int people_cnt = 0;
            for (pair<int, int> p : comp) {
                people_cnt += country_map[p.first][p.second];
            }

            people_cnt = people_cnt / comp.size();
            for (pair<int, int> p : comp) {
                country_map[p.first][p.second] = people_cnt;
            }
        }
        connected_country.clear();
        fill(visited.begin(), visited.end(), vector<int>(N,0));
        day_cnt++;
    }

    cout << day_cnt << endl;

    return 0;
}