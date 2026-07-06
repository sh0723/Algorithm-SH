#include <bits/stdc++.h>
using namespace std;
int visited[2][500001];
int subin, bro;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> bro;

    queue<int> q;
    q.push(subin);
    visited[0][subin] = 1;
    int t=0;
    while(!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            subin = q.front();
            q.pop();
            int bro_pos = bro + ((t * (t+1)) / 2);
            if (bro_pos > 500000) break;

            if (visited[t%2][bro_pos]) {
                cout << t << '\n';
                return 0;
            }
            for (int next : {subin -1, subin + 1, subin * 2}) {
                if (next < 0 || next >500000 || visited[(t+1)%2][next]) continue;
                q.push(next);
                visited[(t+1)%2][next] = 1;
            }
        }
        t++;
    }

    cout << -1 << '\n';

    return 0;
}