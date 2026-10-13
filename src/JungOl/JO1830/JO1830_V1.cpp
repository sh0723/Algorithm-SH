#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> inp(N);
    for (int i=0; i<N; i++) {
        cin >> inp[i];
    }
    sort(inp.begin(), inp.end());

    int g=0;
    for (int i=1; i<N; i++) {
        g = gcd(g, inp[i] - inp[i-1]);
    }

    vector<int> ret;
    for (int i=2; i<=sqrt(g); i++) {
        if (g % i == 0) {
            ret.push_back(i);
            if (i != g / i) ret.push_back(g / i);
        }
    }
    ret.push_back(g);
    sort(ret.begin(), ret.end());

    for (int i=0; i<ret.size(); i++) cout << ret[i] << ' ';

    return 0;
}