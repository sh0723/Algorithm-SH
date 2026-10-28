#include <bits/stdc++.h>
using namespace std;
long long A,B;
bool ret;
void solve(long long num) {
    if (num == B) {
        ret = true;
        return;
    }

    if (ret || num <= 1) {
        return;
    }

    if (num % 2 == 0) {
        solve(num / 2);
    } else {
        solve(num / 2);
        solve(num / 2 + 1);
    }

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B;
    solve(A);
    cout << ret;

    return 0;
}