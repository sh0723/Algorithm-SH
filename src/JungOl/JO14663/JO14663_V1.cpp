#include <bits/stdc++.h>
using namespace std;
int solve(int l, int r) {
    if (l == 1 && r == 1) return 1;

    if (l > r) {
        return 2*solve(l-r, r)+1;
    } else {
        return 2*solve(l,r-l);
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    vector<int> ret;
    vector<pair<int, int>> inp;

    for (int i=0; i<T; i++) {
        pair<int, int> tmp;
        int K;
        char slash;

        cin >> K >> tmp.first  >> slash >> tmp.second;
        inp.push_back(tmp);
    }

    for (int i=0; i<T; i++) {
        ret.push_back(solve(inp[i].first, inp[i].second));
    }

    for (int i=0; i<T; i++) cout << i+1  << " " << ret[i] << '\n';

    return 0;
}