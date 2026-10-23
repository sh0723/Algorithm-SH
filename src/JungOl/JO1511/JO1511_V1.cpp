#include <bits/stdc++.h>
using namespace std;
vector<string> dp(5001);
void fill_dp(int num) {
    int n_1_idx=dp[num-1].size()-1;
    int n_2_idx=dp[num-2].size()-1;
    int carr = 0;

    while(true) {
        if (n_2_idx < 0 && n_1_idx < 0) {
            break;
        }
        int put_num;
        if (n_2_idx >=0 && n_1_idx >= 0) {
            put_num = (int)(dp[num-1][n_1_idx] - '0') + (int)(dp[num-2][n_2_idx] - '0') + carr;
        } else {
            put_num = (int)(dp[num-1][n_1_idx] - '0') + carr;
        }

        if (put_num >= 10) {
            put_num -= 10;
            carr = 1;
        } else {
            carr = 0;
        }
        dp[num].push_back('0'+put_num);
        n_2_idx--;
        n_1_idx--;
    }
    if (carr != 0) {
        dp[num].push_back('0'+carr);
    }

    reverse(dp[num].begin(), dp[num].end());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    dp[0] = "0";
    dp[1] = "1";
    for(int i=2; i<=5000; i++) {
        fill_dp(i);
    }

    while(T--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }


    return 0;
}