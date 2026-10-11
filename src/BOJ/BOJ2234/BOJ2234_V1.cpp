#include <bits/stdc++.h>
using namespace std;
int inp[50][50];
int room_num[50][50];
int N,M;
bool visited[50][50];
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
int ret[3];
vector<int> room_size;
int dfs(int y, int x, int rn) {
    int ret_val = 1;
    for (int i=0; i<4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
        if (inp[y][x] & (1 << i)) continue;
        visited[ny][nx] = true;
        room_num[ny][nx] = rn;
        ret_val += dfs(ny, nx, rn);
    }

    return ret_val;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> inp[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                room_num[i][j] = ret[0];
                int room = dfs(i, j, ret[0]);
                ret[0]++;
                room_size.push_back(room);
                ret[1] = max(ret[1], room);
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (!(inp[i][j] & (1 << k))) continue;
                int room_a = room_num[ny][nx];
                int room_b = room_num[i][j];
                if (room_a == room_b) continue;
                ret[2] = max(ret[2], room_size[room_a] + room_size[room_b]);
            }
        }
    }

    for (int i=0; i<3; i++) {
        cout << ret[i] << '\n';
    }

    return 0;
}