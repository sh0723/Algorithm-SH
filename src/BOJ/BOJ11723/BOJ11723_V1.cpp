#include <bits/stdc++.h>
using namespace std;
int ret;
void solve(string s, int num) {
    if (s == "add") {
        ret |= (1 << num);
    } else if (s == "remove") {
        ret &= ~(1 << num);
    } else if (s == "check") {
        if (ret & (1 << num)) cout << 1 << '\n';
        else cout << 0 << '\n';
    } else if (s == "toggle") {
        ret ^= (1 << num);
    } else if (s == "all") {
        for (int i=1; i<=20; i++) {
            ret |= (1 << i);
        }
    } else {
        ret = 0;
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<string,int>> inp;
    for (int i = 0; i < n; i++) {
        string s;
        int num;
        cin >> s;
        if (s == "all" || s == "empty") {
            inp.push_back({s, 0});
        } else {
            cin >> num;
            inp.push_back({s, num});
        }
    }

    for (int i = 0; i < n; i++) {
        solve(inp[i].first, inp[i].second);
    }





    return 0;
}