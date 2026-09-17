#include <bits/stdc++.h>
using namespace std;
int T,W, dp[1000][2][31];
int arr[1000];
int solve(int idx, int tree, int cnt) {
    if (cnt < 0) return -1e9;

    if (idx == T) return 0;

    int &ret = dp[idx][tree][cnt];

    if (ret != -1) return ret;

    return ret = max(solve(idx+1, tree, cnt), solve(idx+1, tree^1, cnt-1)) + (tree == arr[idx]-1);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T >> W;

    memset(dp, -1, sizeof(dp));

    for (int i=0; i<T; i++) {
        cin >> arr[i];
    }

    int ret = max(solve(0,0,W),solve(0, 1, W-1));

    cout << ret;

    return 0;
}