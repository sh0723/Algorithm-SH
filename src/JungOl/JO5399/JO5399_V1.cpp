#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> adj;
vector<vector<int>> dp;
void solve(int cur){

    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (int next : adj[cur]) {
        solve(next);

        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    adj.resize(N+1,vector<int>());
    for (int i=2; i<=N; i++) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }

    dp.resize(N+1, vector<int>(2, 0));

    solve(1);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}