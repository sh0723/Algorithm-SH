#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;
    vector<long long> ret;
    for (int i=0; i<Q; i++) {
        long long int a,b;
        cin >> a >> b;

        if (b % a != 0 || a == b) {
            ret.push_back(0);
        } else {
            ret.push_back(1);
        }

    }

    for (int i=0; i<Q; i++) 
        cout << ret[i] << '\n';

    return 0;
}
