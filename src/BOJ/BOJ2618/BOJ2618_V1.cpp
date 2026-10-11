#include <bits/stdc++.h>
using namespace std;
int N, M;
int dp[1002][1002];
vector<pair<int, int>> inp;
int dist_diff(int a, int b){
    return abs(inp[a].first - inp[b].first) + abs(inp[a].second - inp[b].second);
}
int solve(int a, int b) {
    if (a == M+1 || b == M+1) return 0; // 기저사례
    if (dp[a][b]) return dp[a][b];
    int next = max(a,b) + 1;
    return dp[a][b] = min(solve(a,next) + dist_diff(b,next), solve(next, b) + dist_diff(a,next)); // 메모이제이션
}
void print_police() {
    int a = 0, b = 1;
    for (int next=2; next<=M+1; next++) {
        if (dp[next][b] + dist_diff(a,next) < dp[a][next] + dist_diff(b,next)) {
            cout << 1 << '\n';
            a = next;
        } else {
            cout << 2 << '\n';
            b = next;
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    inp.push_back({1,1});
    inp.push_back({N,N});
    for (int i=0; i<M; i++) {
        int y,x;
        cin >> y >> x;
        inp.push_back({y,x});
    }
    cout << solve(0,1) << '\n';
    print_police();


    return 0;
}