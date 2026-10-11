#include <bits/stdc++.h>
using namespace std;
bool bitmap[20][20];
int N;
int ret = INT_MAX;
int calculate() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int t=0;
        for (int j = 0; j < N; j++) {
            if (bitmap[j][i]) t++;
        }
        cnt += min(t, N-t);
    }
    return cnt;
}
void flip(int row) {
    for (int i = 0; i < N; i++) {
        bitmap[row][i] = !bitmap[row][i];
    }
}
void solve(int st) {
    if (st == N) {
        ret = min(ret, calculate());
        return;
    }
    solve(st+1);
    flip(st);
    solve(st+1);
    flip(st);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<N; j++) {
            bitmap[i][j] = (s[j] == 'T'); // 뒷면 true
        }
    }

    solve(0);

    cout << ret << '\n';

    return 0;
}