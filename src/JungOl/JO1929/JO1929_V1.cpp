#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    while(N--) {
        long long num;
        cin >> num;
        pq.push(num);
    }

    long long ret = 0;
    while(true) {
        if (pq.size() == 1) break;
        long long t1, t2;
        t1 = pq.top();
        pq.pop();
        t2 = pq.top();
        pq.pop();
        ret += (t1 + t2);
        pq.push(t1 + t2);
    }

    cout << ret;

    return 0;
}