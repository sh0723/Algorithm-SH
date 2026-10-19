#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    vector<string> strs(T);
    for (int i=0; i<T; i++) {
        cin >> strs[i];
    }
    string rsp = "RSP";
    for (int n=0; n<T; n++) {
        int ret = INT_MAX;

        int size = strs[n].size();
        for (int first=0; first<3; first++) {
            vector<vector<int>> dp(size,vector<int>(3, INT_MAX));
            dp[0][first] = (rsp[first] != strs[n][0]);
            for (int i=1; i<size; i++) {
                for (int cur=0; cur<3; cur++) {
                    for (int prev=0; prev<3; prev++) {
                        if (cur == prev) continue;
                        if (dp[i - 1][prev] == INT_MAX) continue;

                        dp[i][cur] = min(dp[i][cur], dp[i-1][prev] + (rsp[cur] != strs[n][i]));
                    }
                }
            }

            for (int fin=0; fin<3; fin++) {
                if (fin == first) continue;
                ret = min(ret, dp[size-1][fin]);
            }
        }

        cout << "Case #" << n+1 << ": " << ret << '\n';
    }




    return 0;
}