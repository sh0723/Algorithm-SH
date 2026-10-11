#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;


    while (scanf("%d", &n) != EOF) {
        int cnt = 1;
        ll ret = 1;
        while(true) {
            if (ret % n == 0) {
                cout << cnt << "\n";
                break;
            } else {
                ret = (ret * 10) + 1;
                ret %= n;
                cnt++;
            }
        }
    }




    return 0;
}