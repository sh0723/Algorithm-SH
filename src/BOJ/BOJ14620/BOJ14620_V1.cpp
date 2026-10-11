#include <bits/stdc++.h>
using namespace std;
int N;
int isplanted[10][10];
int inp_map[10][10];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int ret = INT_MAX;
bool canPlant(int y, int x) {
    for (int k = 0; k < 4; k++) {
        int vy = y + dy[k];
        int vx = x + dx[k];
        if (0 > vy || vy >= N || 0 > vx || vx >= N || isplanted[vy][vx]) {
            return false;
        }
    }
    return true;
}
int plant(int y, int x) {
    int cost = inp_map[y][x];
    for (int k = 0; k < 4; k++) {
        int vy = y + dy[k];
        int vx = x + dx[k];
        isplanted[vy][vx] = 1;
        cost += inp_map[vy][vx];
    }

    return cost;
}
void unplant(int y, int x) {
    for (int k = 0; k < 4; k++) {
        int vy = y + dy[k];
        int vx = x + dx[k];
        isplanted[vy][vx] = 0;
    }
}
void solve(int cost, int cnt) {
    if (cnt == 3) {
        ret = min(ret, cost);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (canPlant(i, j)) {
                int next_cost = cost + plant(i, j);
                solve(next_cost, cnt + 1);
                unplant(i, j);
            }
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inp_map[i][j];
        }
    }

    solve(0,0);

    cout << ret << '\n';



    return 0;
}