#include <bits/stdc++.h>
using namespace std;
vector<int> lis;
vector<pair<int, int>> inp_arr;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;
        inp_arr.push_back({a,b});
    }

    sort(inp_arr.begin(), inp_arr.end());

    for (int i=0; i<N; i++) {
        int num = inp_arr[i].second;

        auto _pos = lower_bound(lis.begin(), lis.end(), num);

        if (_pos == lis.end()) {
            lis.push_back(num);
        } else {
            *_pos = num;
        }
    }

    cout << N-lis.size() << '\n';

    return 0;
}
