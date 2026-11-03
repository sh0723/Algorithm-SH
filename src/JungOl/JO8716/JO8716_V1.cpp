#include <bits/stdc++.h>
using namespace std;
long long solve(long long num, long long m, long long p) {
    if (p == 1) {
        return (num % m);
    }

    int half = solve(num, m, p/2);
    int ret = ((half % m) * (half % m)) % m;
    if (p % 2 != 0) ret = (ret * num) % m;

    return ret;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long X,Y,N;
    long long A,B,M;

    cin >> X >> Y >> N;
    cin >> A >> B >> M;

    cout << solve(X, N, Y) << '\n';
    cout << solve(A, M, B) << '\n';


    return 0;
}