#include <bits/stdc++.h>
using namespace std;
int N,M;
int jewel[300000];
int l=1, r, m, result = INT_MAX;
bool search(int num) {
    int ret = 0;
    for (int i=0; i<M; i++) {
        ret += jewel[i] / num;
        if (jewel[i] % num) ret++;
    }

    return ret <= N;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<M; i++) {
        cin >> jewel[i];
        r = max(r, jewel[i]);
    }

    while(l <= r) {
        m = (l + r) / 2;

        if (search(m)) {
            result = min(result, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << result << '\n';

    return 0;
}