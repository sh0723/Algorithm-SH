#include <bits/stdc++.h>
using namespace std;
long long DP[31][31];
int type[2];
int N;
long long solve(int W, int H) {
    if (W == 0 && H == 0) return 1;
    if (DP[W][H]) return DP[W][H];

    long long int &ret = DP[W][H];
    if (W > 0) ret += solve(W-1, H+1);
    if (H > 0) ret += solve(W, H-1);

    return ret;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    while(true) {
        int n;
        cin >> n;
        if (n == 0) break;
        cout << solve(n, 0) << '\n';
    }


    return 0;
}
