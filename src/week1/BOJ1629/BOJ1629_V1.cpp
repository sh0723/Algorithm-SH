#include <bits/stdc++.h>
using namespace std;
long long a,b,c;

long long power(long long x, long long y) {

    if (y == 1)
        return 1;

    long long half = power(x, y/2);
    half = (half * half) % c;

    if (y % 2 == 1)
        half = (half * x) % c;

   return half;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;

    cout << power(a, b) % c << "\n";
}