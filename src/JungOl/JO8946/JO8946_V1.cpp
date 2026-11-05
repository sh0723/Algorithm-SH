#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator() (pair<int, int> f, pair<int, int> s) {
        return f.first*s.second < f.second * s.first ;
    }
};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M,K;

    cin >> M >> K;

    priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> pq;

    for (int i=2; i<=M; i++) {
        pq.push({i,1});
    }

    pair<int,int> ret;
    bool cant = false;
    while(K--) {
        if (pq.empty()) {
            cant = true;
            break;
        }

        ret = pq.top();
        pq.pop();
        int ret_m = ret.first;
        int ret_s = ret.second;


        for (int i=ret_s+1; i<ret_m; i++) {
            if (gcd(ret_m,i) == 1) {
                pq.push({ret_m, i});
                break;
            }
        }
    }

    if (cant) cout << -1;
    else cout << ret.second << ' ' << ret.first;

    return 0;
}