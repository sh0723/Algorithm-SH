#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ret = 0, curr = 0;
    for (int i=0; i<4; i++) {
        int in,out;
        cin >> out >> in;
        curr += (in - out);
        ret = max(ret, curr);
    }

    cout << ret;

    return 0;
}