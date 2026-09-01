#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> inp;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; i++) {
        int st,ed;
        cin >> st >> ed;
        inp.push_back({st,ed});
    }

    sort(inp.begin(), inp.end());

    int ret=0;
    int st=inp[0].first,ed=inp[0].second;

    for (int i=1; i<N; i++) {
        if (inp[i].first > ed) {
            ret += (ed-st);
            st = inp[i].first;
            ed = inp[i].second;
        } else {
            if (ed < inp[i].second) ed = inp[i].second;
        }
    }

    ret += (ed-st);

    cout << ret << '\n';

    return 0;
}