#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int ret = -1004;
    cin >> n;

    int sum = 0;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        sum += num;
        ret = max(ret, sum);
        if (sum < 0) sum = 0;
    }

    cout << ret;

    return 0;
}