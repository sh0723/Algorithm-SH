#include <bits/stdc++.h>
using namespace std;
vector<int> ret(5);
int ret_bit =0;
vector<vector<int>> inp;
int m[4];
int n;
bool check_valid(vector<int> temp) {
    for (int i = 0; i < 4; i++) {
        if (temp[i] < m[i])
            return false;
    }

    return true;
}
bool bitcmp(int a, int b) {
    for (int i=0; i<n; i++) {
        if (a & (1 << i) && !(b & (1 << i)))
            return true;
        else if (!(a & (1 << i)) && b & (1 << i))
            return false;
    }
    return true;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ret[4] = INT_MAX;
    cin >> n;
    for (int i=0; i<4; i++) {
        cin >> m[i];

    }

    for (int i=0; i<n; i++) {
        inp.push_back(vector<int>());
        for (int j=0; j<5; j++) {
            int tmp;
            cin >> tmp;
            inp[i].push_back(tmp);
        }
    }

    for (int i=0; i<(1 << n); i++) {
        vector<int> tmp(5,0);
        for (int j=0; j<n; j++) {
            if (i & (1 << j)) {
                for (int k=0; k<5; k++)
                    tmp[k] += inp[j][k];
            }
        }
        if (check_valid(tmp)) {
            if (ret[4] > tmp[4]) {
                ret = tmp;
                ret_bit = i;
            } else if (ret[4] == tmp[4] && bitcmp(i, ret_bit)) {
                ret = tmp;
                ret_bit = i;
            }
        }

    }

    if (ret[4] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ret[4] << '\n';
        for (int i=0; i<n; i++) {
            if (ret_bit & (1 << i))
                cout << i + 1 << ' ';
        }
    }


    return 0;
}