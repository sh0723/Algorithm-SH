#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> mnt;

    for (int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        mnt.push_back({x-y, x+y});
    }

    sort(mnt.begin(), mnt.end(), cmp);

    int max_ed = INT_MIN;
    int ret=0;
    for (auto[st, ed] : mnt) {
        if (ed > max_ed) {
            ret++;
            max_ed = ed;
        }
    }

    cout << ret;



    return 0;
}