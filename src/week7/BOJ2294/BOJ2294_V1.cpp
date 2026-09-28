#include <bits/stdc++.h>
using namespace std;
int N,k;
int dp[100001];
vector<int> inp(100);
int solve(int n) {
    if (dp[n] != -1) return dp[n];


    int min_val = k+1;
    for (int i = 0; i < N; i++) {
        int coin_val = inp[i];
        if (coin_val <= n) {
            min_val = min(min_val, solve(n - coin_val) + 1);
        }
    }
    return dp[n] = min_val;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> k;
    for (int i=0; i<N; i++) {
        cin >> inp[i];
    }

    fill(dp, dp + k + 1, -1);
    dp[0] = 0;

    int ret = solve(k);
    cout << (ret > k ? -1 : ret) << '\n';

    return 0;
}