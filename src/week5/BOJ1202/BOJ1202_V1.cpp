#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,K;
    vector<int> bag;
    vector<pair<int, int>> treasure;

    cin >> N >> K;

    for (int i=0; i<N; i++) {
        int w,v;
        cin >> w >> v;
        treasure.push_back({w,v});
    }

    for (int i=0; i<K; i++) {
        int w;
        cin >> w;
        bag.push_back(w);
    }

    sort(bag.begin(), bag.end());
    sort(treasure.begin(), treasure.end());

    priority_queue<int> pq;
    long long int ret = 0;
    int idx = 0;
    for (int next_bag : bag) {
        while (idx < N && treasure[idx].first <= next_bag) {
            pq.push(treasure[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << '\n';

    return 0;
}