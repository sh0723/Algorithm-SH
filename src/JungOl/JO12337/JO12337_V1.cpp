#include <bits/stdc++.h>
using namespace std;
int N;
long long int inp[200000];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> inp[0];
    if (N == 1) {
        cout << 0;
        return 0;
    }
    bool cant = false;
    int prev = inp[0];
    for (int i=1; i<N; i++) {
        cin >> inp[i];
        if ((prev - inp[i]) % 2 != 0) cant = true;
    }

    if (cant) {
        cout << -1;
        return 0;
    }

    sort(inp, inp+N);
    long long int cnt = 0;
    for (int i=1; i<N; i++) {
        cnt += (inp[i]-inp[0])/2;
    }

    cout << cnt;
    return 0;
}
