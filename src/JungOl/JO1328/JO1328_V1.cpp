#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> inp;
    stack<pair<int,int>> stk;
    vector<int> ret(N,0);
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        inp.push_back(num);
    }

    for (int i=0; i<N; i++) {
        if (stk.empty()) {
            stk.push({inp[i],i});
        } else {
            if (stk.top().first >= inp[i]) {
                stk.push({inp[i], i});
            } else {
                int curr_val = inp[i];
                while(true) {
                    if (!stk.empty() && stk.top().first < curr_val) {
                        ret[stk.top().second] = i+1;
                        stk.pop();
                    } else break;
                }
                stk.push({inp[i],i});
            }
        }
    }

    while(!stk.empty()) {
        ret[stk.top().second] = 0;
        stk.pop();
    }

    for (int i=0; i<N; i++) cout << ret[i] << '\n';


    return 0;
}