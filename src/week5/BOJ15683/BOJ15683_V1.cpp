#include <bits/stdc++.h>
using namespace std;
int N,M;
int room[8][8];
struct cctv_struct{
    int y, x;
    int num;
};
vector<cctv_struct> cctv;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int directionMask[6] = {
    0,   // 0000
    1,   // 0001
    5,   // 0101
    3,   // 0011
    7,   // 0111
    15   // 1111
};

int cctv_cnt;
int ret = INT_MAX;

int get_cnt() {
    int cnt=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (room[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
void watch(int y, int x, int dir) {
    while (true) {
        y += dy[dir];
        x += dx[dir];

        if (y < 0 || y >= N || x < 0 || x >= M)
            break;

        if (room[y][x] == 6)
            break;

        if (room[y][x] == 0)
            room[y][x] = -1;
    }
}

void do_cctv(cctv_struct cctv_arg, int rotation) {
    int mask = directionMask[cctv_arg.num];

    mask = ((mask << rotation) | (mask >> (4 - rotation))) & 0b1111;

    for (int dir = 0; dir < 4; dir++) {
        if (mask & (1 << dir)) {
            watch(cctv_arg.y, cctv_arg.x, dir);
        }
    }
}

void solve(int n) {
    if (n == cctv_cnt) {
        ret = min(ret, get_cnt());
        return;
    }

    for (int i=0; i<4; i++) {
        int temp[8][8];
        memcpy(temp, room, sizeof(room));
        do_cctv(cctv[n], i);
        solve(n+1);
        memcpy(room,temp,sizeof(room));
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> room[i][j];
            if (room[i][j] >=1 && room[i][j] <=5) {
                cctv.push_back({i,j,room[i][j]});
            }
        }
    }

    cctv_cnt = cctv.size();

    solve(0);

    cout << ret;

    return 0;
}