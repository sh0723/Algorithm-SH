#include <bits/stdc++.h>
using namespace std;
struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b){
        if (a.first != b.first)
            return a.first > b.first;

        return a.second > b.second;
    }
};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i=0; i<n; i++) {
        int arrive, how;
        cin >> arrive >> how;
        pq.push({arrive, how});
    }



    int t=1;
    while(!pq.empty()) {
        if (pq.top().first <= t) {
            t += pq.top().second;
            pq.pop();
        } else {
            t = pq.top().first + pq.top().second;
            pq.pop();
        }
    }

    cout << t;

    return 0;
}