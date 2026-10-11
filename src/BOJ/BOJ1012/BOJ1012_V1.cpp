#include <bits/stdc++.h>
using namespace std;
int T,M,N,K;
vector<vector<int>> farm;
vector<vector<int>> visited;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= M || ny < 0 || nx >= N || nx < 0 || visited[ny][nx] || !farm[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> T;

    for (int n = 0; n < T; n++) {
        cin >> M >> N >> K;
        int cnt = 0;
        for (int i=0; i<M; i++) {
            farm.push_back(vector<int>(N, 0));
            visited.push_back(vector<int>(N, 0));
        }
        for (int i = 0; i < K; i++) {
            int y,x;
            cin >> y >> x;
            farm[y][x] = 1;
        }

        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(farm[i][j] && !visited[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
        farm.clear();
        visited.clear();
    }





    return 0;
}