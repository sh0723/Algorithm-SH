#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int num = 665;
    int cnt=0;

    while(true) {
        num++;
        if (to_string(num).find("666") != string::npos) {
            cnt++;
        }
        if (N == cnt) {
            cout << num;
            break;
        }
    }

    return 0;
}