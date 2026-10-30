#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    vector<int> dp(10001, INT_MAX);
    for (int i=1; i<=100; i++) {
        dp[i*i] = 1;
    }

    for (int num=2; num<=10000; num++) {
        for (int i=1; i<=num/2; i++) {
            dp[num] = min(dp[i] + dp[num-i], dp[num]);
        }
    }

    cout << dp[N];

    return 0;
}