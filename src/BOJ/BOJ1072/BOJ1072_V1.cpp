#include <bits/stdc++.h>
using namespace std;
long long int X,Y,Z, ret=-1;
bool check(long long int num){
    return ((100 * (Y + num)) / (X+num)) != Z;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> X >> Y;
    Z = (100 * Y) / X;
    int high = X, low = 1, mid;

    while(low <= high) {
        mid = (high + low) / 2;
        if (check(mid)) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ret << '\n';


    return 0;
}