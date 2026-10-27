#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<long long>> dp(N+1,vector<long long>(N+1,0));

    for (int i = 0; i <= N; i++) {
        dp[0][i] = 1;
    }


    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            dp[j][i] = dp[j][i-1];

            if (j >= i) {
                dp[j][i] += dp[j-i][i];
            }
        }
    }

    cout << dp[N][N];

    return 0;
}