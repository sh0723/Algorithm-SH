#include <bits/stdc++.h>
using namespace std;
int visited[101];
vector<int> adj;
vector<int> inp;
map<int, int> st_idx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    adj.resize(N);
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        inp.push_back(num);
    }

    if (N==1 || N == 2) {
        cout << 1;
        return 0;
    }

    sort(inp.begin(), inp.end());
    adj[0]= 1;
    adj[N-1] = N-2;

    for (int i=1; i<N-1; i++) {
        if (abs(inp[i]-inp[i-1]) <= abs(inp[i]-inp[i+1])) {
            adj[i] = i-1;
        } else {
            adj[i] = i+1;
        }
    }

    for (int i=0; i<N; i++) {
        queue<int> q;
        if (visited[i]) continue;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            visited[cur] = true;
            q.pop();
            if (visited[adj[cur]]) {
                int next = adj[cur];
                st_idx.erase(next);
                if (adj[adj[next]] == next) {
                    st_idx.erase(adj[next]);
                }
                st_idx[i] = 1;
                break;
            }
            q.push(adj[cur]);
        }
    }

    cout << st_idx.size();
    return 0;
}