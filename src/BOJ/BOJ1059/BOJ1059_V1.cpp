#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L,n;
    cin >> L;
    vector<int> arr(L);
    for (int i=0; i<L; i++) {
        cin >> arr[i];
    }
    cin >> n;
    sort(arr.begin(), arr.end());

    int high_val=-1, low_val=1;

    for (int i=0; i<L; i++) {
        if (arr[i] > n) {
            high_val = arr[i]-1;
            if (i != 0) {
                low_val = arr[i-1]+1;
            }
            break;
        } else if (arr[i] == n) {
            cout << 0;
            return 0;
        }
    }

    if (high_val == -1) {
        cout << n - arr[L-1] -1;
        return 0;
    }
    int ret = (high_val-n);
    ret += (high_val-n+1)*(n-low_val);

    cout << ret;

    return 0;
}