#include <bits/stdc++.h>
using namespace std;
int N, H, M;
int visited[31][11];
int ret = 4;
bool check() {
    int start;
    for (int i=1; i<N; i++) {
        start = i;
        for (int j=1; j<=H; j++) {
            if (visited[j][start]) start++;
            else if (visited[j][start-1]) start--;
        }
        if (start != i) return false;
    }
    return true;
}
void solve(int here, int cnt) {
    if (cnt > 3 || cnt >= ret) return;

    if (check()) {
        ret = min(ret, cnt);
    }
    for (int i=here; i<=H; i++) {
        for (int j=1; j<N; j++) {
            if (visited[i][j] || visited[i][j+1] || visited[i][j-1]) continue;
            visited[i][j] = 1;
            solve(i, cnt+1);
            visited[i][j] = 0;
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    for (int i=0; i<M; i++) {
        int y,x;
        cin >> y >> x;
        visited[y][x] = 1;
    }

    solve(1, 0);

    if (ret == 4) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}