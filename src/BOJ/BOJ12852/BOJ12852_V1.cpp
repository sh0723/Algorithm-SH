#include <bits/stdc++.h>
using namespace std;
int dp[1000004];
void solve(int n) {
    if (n == 0) return;
    cout << n << ' ';
    if (n%3 == 0 && dp[n/3] + 1 == dp[n]) solve(n/3);
    else if (n%2 == 0 && dp[n/2] + 1 == dp[n]) solve(n/2);
    else if (n > 1 && dp[n-1] + 1 == dp[n]) solve(n-1);

    return;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    fill(dp, dp+1000004, INT_MAX);

    dp[1] = 0;

    for (int i=2; i<=n; i++) {
        if (i%3 == 0) dp[i] = min(dp[i/3] + 1, dp[i]);
        if (i%2 == 0) dp[i] = min(dp[i/2] + 1, dp[i]);

        dp[i] = min(dp[i-1] + 1, dp[i]);
    }

    cout << dp[n] << '\n';
    solve(n);
    cout << '\n';


    return 0;
}
