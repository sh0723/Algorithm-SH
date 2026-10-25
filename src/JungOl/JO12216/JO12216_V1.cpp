#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> f;
vector<vector<int>> dp;
int solve(int p_idx, int f_idx) {
    if (p_idx < f_idx) return INT_MAX;
    if (f_idx == 0) return 0;

    if (dp[p_idx][f_idx] != -1) return dp[p_idx][f_idx];

    dp[p_idx][f_idx] = min(
        (solve(p_idx-1,f_idx-1) + abs(p[p_idx-1] - f[f_idx-1])),
        solve(p_idx-1, f_idx)
    );

    return dp[p_idx][f_idx];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int P,F;
    cin >> P >> F;
    p.resize(P);
    f.resize(F);
    dp.resize(P+1, vector<int>(F+1, -1));

    for (int i=0; i<P; i++) {
        cin >> p[i];
    }
    for (int i=0; i<F; i++) {
        cin >> f[i];
    }

    cout << solve(P,F);

    return 0;
}