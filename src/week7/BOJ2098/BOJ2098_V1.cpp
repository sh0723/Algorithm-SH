#include <bits/stdc++.h>
using namespace std;
int dist[16][16];
int N;
int dp[16][1 << 16];
int tsp(int here, int visited) {
    if (visited == (1 << N)-1)
        return dist[here][0] ? dist[here][0] : INT_MAX;

    int &ret = dp[here][visited];
    if (ret != -1) return ret;
    ret = INT_MAX;
    for (int i=0; i<N; i++) {
        if (visited & (1 << i)) continue;
        if (!dist[here][i]) continue;

        ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
    }

    return ret;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(0,1) << '\n';



    return 0;
}