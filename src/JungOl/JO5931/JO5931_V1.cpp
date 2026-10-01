#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<n; j++) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}