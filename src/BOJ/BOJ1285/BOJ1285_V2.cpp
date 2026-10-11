#include <bits/stdc++.h>
using namespace std;
int N;
int inp[21];
int ret = INT_MAX;
int calculate() {
    int sum = 0;
    for (int i=1; i<=(1 << (N-1)); i*=2) {
        int cnt = 0;
        for (int j=1; j<=N; j++) {
            if (inp[j] & i) cnt++;
        }
        sum += min(cnt, N-cnt);
    }
    return sum;
}
void solve(int st) {
    if (st == N+1) {
        ret = min(ret, calculate());
        return;
    }

    solve(st+1);
    inp[st] = ~inp[st];
    solve(st+1);
    inp[st] = ~inp[st];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        int tmp = 1;
        for (int j=0; j<s.length(); j++) {
            if (s[j] == 'T')inp[i] |= tmp;
            tmp *= 2;
        }
    }

    solve(1);

    cout << ret << '\n';

    return 0;
}