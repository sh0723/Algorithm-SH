#include <bits/stdc++.h>
using namespace std;
int N,M,T;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> T;
    vector<vector<int>> dist(N+1, vector<int>(N+1, INT_MAX));
    for (int i=1; i<=N; i++) {
        dist[i][i] = 0;
    }

    for (int i=0; i<M; i++) {
        int st,ed, h;
        cin >> st >> ed >> h;
        dist[st][ed] = min(dist[st][ed], h);
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (dist[j][i] == INT_MAX) continue;

            for (int k=1; k<=N; k++) {
                if (dist[i][k] == INT_MAX) continue;

                dist[j][k] = min(dist[j][k], max(dist[j][i], dist[i][k]));
            }
        }
    }

    for (int i=0; i<T; i++) {
        int st,ed;
        cin >> st >> ed;
        if (dist[st][ed] == INT_MAX) cout << -1 << '\n';
        else cout << dist[st][ed] << '\n';
    }


    return 0;
}