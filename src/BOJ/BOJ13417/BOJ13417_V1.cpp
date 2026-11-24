#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    vector<string> ret(T);
    for (int i=0; i<T; i++) {
        int len;
        cin >> len;

        char first;
        cin >> first;

        deque<char> dq;
        dq.push_front(first);
        for (int j=1; j<len; j++) {
            char cur;
            cin >> cur;
            if (dq.front() < cur) {
                dq.push_back(cur);
            } else {
                dq.push_front(cur);
            }
        }

        while(!dq.empty()) {
            ret[i].push_back(dq.front());
            dq.pop_front();
        }
    }

    for (int i=0; i<T; i++) {
        cout << ret[i] << '\n';
    }
    return 0;
}