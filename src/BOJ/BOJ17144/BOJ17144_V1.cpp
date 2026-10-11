#include <bits/stdc++.h>
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
pair<int, int> puri[2];
int input_data[50][50];
int plus_data[50][50];
int R,C,T;
void flooding() {
    while(!q.empty()){
        auto[y,x] = q.front();
        q.pop();
        int each = input_data[y][x] / 5;
        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if ((puri[0].first == ny && puri[0].second == nx) || (puri[1].first == ny && puri[1].second == nx)) continue;
            input_data[y][x] -= each;
            plus_data[ny][nx] += each;
        }
    }
}
void clockly_puri() {
    int y = puri[1].first;

    // 왼쪽 벽: 아래에서 위로 이동
    for (int r = y + 1; r < R - 1; r++) {
        input_data[r][0] = input_data[r + 1][0];
    }

    // 아래쪽 행: 오른쪽에서 왼쪽으로 이동
    for (int c = 0; c < C - 1; c++) {
        input_data[R - 1][c] = input_data[R - 1][c + 1];
    }

    // 오른쪽 벽: 위에서 아래로 이동
    for (int r = R - 1; r > y; r--) {
        input_data[r][C - 1] = input_data[r - 1][C - 1];
    }

    // 공기청정기 행: 왼쪽에서 오른쪽으로 이동
    for (int c = C - 1; c > 1; c--) {
        input_data[y][c] = input_data[y][c - 1];
    }

    input_data[y][1] = 0;
}

void antiClockly_puri() {
    int y = puri[0].first;

    // 왼쪽 벽: 위에서 아래로 이동
    for (int r = y - 1; r >= 1; r--) {
        input_data[r][0] = input_data[r - 1][0];
    }

    // 위쪽 행: 오른쪽에서 왼쪽으로 이동
    for (int c = 0; c < C - 1; c++) {
        input_data[0][c] = input_data[0][c + 1];
    }

    // 오른쪽 벽: 아래에서 위로 이동
    for (int r = 0; r < y; r++) {
        input_data[r][C - 1] = input_data[r + 1][C - 1];
    }

    // 공기청정기 행: 왼쪽에서 오른쪽으로 이동
    for (int c = C - 1; c > 1; c--) {
        input_data[y][c] = input_data[y][c - 1];
    }

    input_data[y][1] = 0;
}
void plus_flooding() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (i == puri[0].first && j == puri[0].second) continue;
            if (i == puri[1].first && j == puri[1].second) continue;
            input_data[i][j] += plus_data[i][j];
        }
    }
}
void add_queue() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (input_data[r][c] > 0) {
                q.push({r, c});
            }
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> T;
    int puri_num=0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> input_data[i][j];
            if (input_data[i][j] > 0) q.push({i,j});
            if (input_data[i][j] == -1) puri[puri_num++] = {i,j};
        }
    }

    for (int i=0; i<T; i++) {
        memset(plus_data, 0, sizeof(plus_data));
        flooding();
        plus_flooding();
        clockly_puri();
        antiClockly_puri();
        add_queue();
    }

    int ret = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (i == puri[0].first && j == puri[0].second) continue;
            if (i == puri[1].first && j == puri[1].second) continue;
            ret += input_data[i][j];
        }
    }

    cout << ret;

    return 0;
}