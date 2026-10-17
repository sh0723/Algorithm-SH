#include <bits/stdc++.h>
using namespace std;
long long dp[40][391];
int N ,tar;
long long int solve(int num, int sum) {
    if (sum > tar) return 0;

    if (num > N) return sum == tar;

    if (dp[num][sum] != -1) return dp[num][sum];



    dp[num][sum] = solve(num+1, sum) + solve(num+1, sum+num);

    return dp[num][sum];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    memset(dp, -1, sizeof(dp));

    cin >> N;
    tar = N * (N+1) / 2;
    if (tar % 2 == 1) {
        cout << 0;
        return 0;
    }
    tar/=2;
    cout << solve(1,0) / 2;


    return 0;
}