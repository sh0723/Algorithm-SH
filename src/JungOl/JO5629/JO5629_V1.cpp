#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int P;
    cin >> N;
    vector<pair<int, int>> trees_x(N);
    vector<pair<int, int>> trees_y(N);

    for (int i=0; i<N; i++) {
        cin >> trees_x[i].first >> trees_x[i].second;
        trees_y[i].first = trees_x[i].first;
        trees_y[i].second = trees_x[i].second;
    }
    sort(trees_x.begin(), trees_x.end());
    sort(trees_y.begin(), trees_y.end(), cmp);

    cin >> P;
    for (int i=0; i<P; i++) {
        int sty, stx, edy,edx;
        cin >> stx >> sty >> edx >> edy;
        auto count_1 = upper_bound(trees_x.begin(), trees_x.end(), make_pair(stx, edy)) - lower_bound(trees_x.begin(), trees_x.end(), make_pair(stx, sty));
        auto count_2 = upper_bound(trees_x.begin(), trees_x.end(), make_pair(edx, edy)) - lower_bound(trees_x.begin(), trees_x.end(), make_pair(edx, sty));
        auto count_3 = lower_bound(trees_y.begin(), trees_y.end(), make_pair(edx, sty), cmp) - upper_bound(trees_y.begin(), trees_y.end(), make_pair(stx, sty), cmp);
        auto count_4 = lower_bound(trees_y.begin(), trees_y.end(), make_pair(edx, edy), cmp) - upper_bound(trees_y.begin(), trees_y.end(), make_pair(stx, edy), cmp);
        cout << count_1 + count_2 + count_3 + count_4 << '\n';
    }



    return 0;
}