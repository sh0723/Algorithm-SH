#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> inp;

    for (int i=0; i<n; i++) {
        int st,ed;
        cin >> st >> ed;
        inp.push_back({ed,st});
    }

    sort(inp.begin(), inp.end());

    int t=0, ret=0;
    for (pair<int, int> next : inp) {
        if (next.second >= t) {
            ret++;
            t = next.first;
        }
    }

    cout << ret;

    return 0;
}