#include <bits/stdc++.h>
using namespace std;
int a;
int solve(int po) {
    if (po == 1) {
        return a % 1000;
    }
    int ret = (solve(po/2) % 1000);
    ret = ((ret % 1000) * (ret % 1000)) % 1000;

    if (po % 2 != 0) ret = ((ret * a) % 1000);

    return ret;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int b;
    cin >> a >> b;
    int ret = ((solve(b/2) * solve(b/2)) % 1000);

    if (b%2 != 0) {
        ret = ((ret * a) % 1000);
    }

    if (ret - 10 < 0) {
        cout << 0 << 0;
    } else if (ret - 100 < 0) {
        cout << 0;
    }

    cout << ret;

    return 0;

}