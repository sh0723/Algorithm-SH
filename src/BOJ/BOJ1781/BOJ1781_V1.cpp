#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> inp;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int d,c;
        cin >> d >> c;
        inp.push_back({d,c});
    }

    sort(inp.begin(), inp.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [d,p] : inp) {
        pq.push(p);
        if (pq.size() > d) {
            pq.pop();
        }
    }

    int ret=0;
    while(!pq.empty()) {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << '\n';


    return 0;
}