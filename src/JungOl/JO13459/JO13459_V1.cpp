#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> arr;
void swap_row_col() {
    for (int row = 1; row <= n; row++) {
        for (int col = row + 1; col <= n; col++) {
            swap(arr[row][col], arr[col][row]);
        }
    }
}
void exch() {
    vector<vector<int>> tmp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            tmp[i / 2] = arr[i];
        } else {
            tmp[n / 2 + (i + 1) / 2] = arr[i];
        }
    }

    arr = tmp;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true) {
        cin >> n;
        if (n==0) return 0;
        arr.assign(n + 1, vector<int>(n + 1));

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cin >> arr[i][j];
            }
        }

        exch();
        swap_row_col();
        exch();
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << arr[j][i];
                if (j != n) cout << ' ';
            }
            cout << '\n';
        }
    }


    return 0;
}