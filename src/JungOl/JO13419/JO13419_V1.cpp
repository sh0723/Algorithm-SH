#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true) {
        int num;
        cin >> num;
        if (num == 0) return 0;
        int st_floor=num,k;
        for (k=44720; k>1; k--) {
            long long temp = num - k*(k-1)/2;
            if (temp > 0 && temp % k == 0) {
                st_floor = (num - k*(k-1)/2) / k;
                break;
            }
        }

        cout << st_floor << " " << k << '\n';
    }



    return 0;
}