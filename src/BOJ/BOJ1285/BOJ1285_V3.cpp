#include <bits/stdc++.h>
using namespace std;
int N;
int bit_arr[21];
int ret = INT_MAX;
int calculate() {
    int ret_val = 0;
    for (int i=0; i<N; i++) {
        int cnt = 0;
        for (int j=0; j<N; j++) {
            if (bit_arr[j] & (1 << i))
                cnt++;
        }
        ret_val += min(cnt, N-cnt);
    }

    return ret_val;
}
void solve(int n) {
    if (n == N) {
        ret = min(ret, calculate());
        return;
    }

    solve(n+1);
    bit_arr[n] = ~bit_arr[n];
    solve(n+1);
    bit_arr[n] = ~bit_arr[n];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int num = 1;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'T') bit_arr[i] |= (1 << (num-1));
            num++;
        }
    }

    solve(0);

    cout << ret << '\n';
    return 0;
}