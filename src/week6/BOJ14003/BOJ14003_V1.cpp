#include <bits/stdc++.h>
using namespace std;
int N;
int lis[1000000];
pair<int, int> res[1000000];
stack<int> stk;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(lis, lis + 1000000, INT_MAX);
    int len = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        auto lower_pos = lower_bound(lis, lis + len, num); // 위치
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis); // index 번호

        if (*lower_pos == INT_MAX) len++;
        *lower_pos = num;

        res[i].first = _pos;
        res[i].second = num;
    }

    cout << len << '\n';
    for (int i=N-1; i>=0; i--) {
        if (res[i].first == len-1) {
            stk.push(res[i].second);
            len--;
        }
    }

    while(!stk.empty()) {
        cout << stk.top() << " ";

        stk.pop();
    }


    return 0;
}