#include<bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int P;
    cin >> P;
    vector<pair<int, long long>> ret;
    long long int dp[65][10];
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<10; i++) dp[1][i] = 1;
    for (int len=2; len<=64; len++) {
        for (int i=0; i<10; i++) {
            for (int j=0; j<=i; j++) {
                dp[len][i] += dp[len-1][j];
            }
        }
    }

    while(P--) {
        int set_num, len;
        cin >> set_num >> len;

        long long int ret_num = 0;
        for (int i=0; i<10; i++) {
            ret_num += dp[len][i];
        }
        ret.push_back({set_num, ret_num});
    }

    for (int i=0; i<ret.size(); i++) {
        cout << ret[i].first << ' ' << ret[i].second << '\n';
    }



    return 0;
}