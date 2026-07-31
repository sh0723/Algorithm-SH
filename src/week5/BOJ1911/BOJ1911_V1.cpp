#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> inp;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,L;
    cin >> N >> L;

    for (int i=0; i<N; i++) {
        int st,ed;
        cin >> st >> ed;
        inp.push_back({st,ed});
    }

    sort(inp.begin(), inp.end());

    int ret = 0;
    int st =0, ed=0;
    for (pair<int, int> curr : inp) {
        int cnt = 0;
        if (ed >= curr.second) continue;

        if (ed < curr.first) {
            st = curr.first;
        } else {
            st = ed;
        }
        ed = curr.second;

        cnt += (ed-st)/L;
        if ((ed-st)%L) cnt+=1;
        ret += cnt;
        ed = st + L * cnt;
    }
    cout << ret;

    return 0;
}