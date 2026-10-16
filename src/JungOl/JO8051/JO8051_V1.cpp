#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<long long int> dp(10001, 0);
    vector<int> inp(N);
    int max_int = 1;
    for (int i=0; i<N; i++) {
        cin >> inp[i];
        max_int = max(max_int, inp[i]);
    }
    dp[0] = 1;
    for (int w : {1,2,3}) {
        for (int i=w; i<=max_int; i++) {
            dp[i] += dp[i-w];
        }
    }

    for (int i=0; i<N; i++) {
        cout << dp[inp[i]] << ' ';
    }



    return 0;
}