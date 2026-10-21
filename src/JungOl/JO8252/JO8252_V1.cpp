#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> dp(N + 1, 1);

    for (int cur = 1; cur <= N; cur++) {
        int plus_num = 0;

        string num_to_str = to_string(cur);
        int len = num_to_str.size();
        for (int i=0; i<len; i++) {
            plus_num += (num_to_str[i]-'0');
        }

        int next = cur + plus_num;

        if (next <= N) {
            dp[next] += dp[cur];
        }
    }

    cout << dp[N];

    return 0;
}