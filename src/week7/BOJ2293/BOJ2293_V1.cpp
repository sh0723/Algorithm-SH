#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<int> coin;
int N,K;
int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> N >> K;

    dp.resize(K+1,0);
    dp[0] = 1;
    coin.resize(N);
    for (int i=0; i<N; i++) {
        cin >> coin[i];
    }
    for (int curr_coin : coin) {
        for (int amount = curr_coin; amount <= K; amount++) {
            dp[amount] += dp[amount - curr_coin];
        }
    }

    cout << dp[K];

    return 0;
}