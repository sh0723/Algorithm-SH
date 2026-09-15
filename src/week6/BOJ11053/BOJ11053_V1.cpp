#include <bits/stdc++.h>
using namespace std;
vector<int> lis;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        auto _pos = lower_bound(lis.begin(),lis.end(), num);
        if (_pos == lis.end()) {
            lis.push_back(num);
        } else {
            *_pos = num;
        }
    }

    cout << lis.size();


    return 0;
}