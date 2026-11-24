#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    vector<int> ret(T);
    for (int i=0; i<T; i++) {
        int x_1, x_2, y_1, y_2, r_1, r_2;

        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;

        int r_diff = (r_1 - r_2) * (r_1 - r_2);
        int r_sum = (r_1 + r_2) * (r_1 + r_2);

        int dist = (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);

        if (x_1 == x_2 && y_1 == y_2 && r_1 == r_2) ret[i]= -1;
        else if (dist > r_sum || dist < r_diff) ret[i] = 0;
        else if (dist == r_sum || dist == r_diff) ret[i] = 1;
        else ret[i] = 2;
    }

    for (int i=0; i<T; i++) {
        cout << ret[i] << '\n';
    }

    return 0;
}