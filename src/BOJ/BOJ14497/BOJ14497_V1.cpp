#include <bits/stdc++.h>
using namespace std;
int visited[301][301];
int inp_class[301][301];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
pair<int, int> friends, junan;
int M,N;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    cin >> junan.first >> junan.second >> friends.first >> friends.second;

    for (int i=1; i<=M; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=N; j++) {
            if (i == junan.first && j == junan.second) inp_class[i][j] = -1;
            else if (i == friends.first && j == friends.second) inp_class[i][j] = 2;
            else inp_class[i][j] = s[j-1] - '0';
        }
    }
    int cost = 0;
    queue<pair<int, int> > q;
    q.push(junan);
    visited[junan.first][junan.second] = 1;
    while(true) {
        queue<pair<int, int> > next_q;

        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            if (inp_class[curr.first][curr.second] == 2) {
                cout << cost << '\n';
                return 0;
            }

            for (int i=0; i<4; i++) {
                int ny = curr.first + dy[i];
                int nx = curr.second + dx[i];
                if (ny < 1 || ny > M || nx < 1 || nx > N) continue;
                if (visited[ny][nx]) continue;
                if (inp_class[ny][nx] == 0) {
                    q.push({ny,nx});
                    visited[ny][nx] = 1;
                } else {
                    next_q.push({ny,nx});
                    visited[ny][nx] = 1;
                }
            }
        }
        cost++;
        q = next_q;
    }



    return 0;
}