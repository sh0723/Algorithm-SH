#include <bits/stdc++.h>
using namespace std;
int bro, subin;
int visited[2][500001];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> subin >> bro;

    queue<int> q;
    q.push(subin);
    visited[0][subin] = 1;
    int t = 0;
    while(!q.empty()) {
        int size = q.size();
        int bro_pos = t * (t + 1) / 2 + bro;
        if (bro_pos > 500000) break;
        if (visited[t%2][bro_pos]) {
            cout << t;
            return 0;
        }

        while(size--) {
            int curr = q.front();
            q.pop();

            for (int next : {curr+1, curr-1, curr*2}) {
                if (next < 0 || next > 500000) continue;
                if (visited[(t+1)%2][next]) continue;
                visited[(t+1)%2][next] = 1;
                q.push(next);
            }
        }
        t++;
    }

    cout << -1;

    return 0;
}