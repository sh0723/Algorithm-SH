#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<string> arr(N);
    vector<vector<int>> adj(N, vector<int>());
    vector<int> pop(N,0);

    for(int i=0; i<N; i++) {
        cin >> arr[i];
        for (int j=0; j<N; j++) {
            if (arr[i][j] == 'Y') {
                adj[i].push_back(j);
            }
        }
    }

    for (int i=0; i<N; i++) {
        vector<bool> visited(N, false);
        visited[i] = true;

        for (int j=0; j<N; j++) {
            if (arr[i][j] == 'Y'){
                if (!visited[j]) {
                    visited[j] = true;
                    pop[i]++;
                }

                for (int next : adj[j]) {
                    if (visited[next]) continue;
                    visited[next] = true;
                    pop[i]++;
                }
            }


        }
    }

    int ret = 0;
    for (int i=0; i<N; i++) {
        ret = max(ret, pop[i]);
    }

    cout << ret;

    return 0;
}