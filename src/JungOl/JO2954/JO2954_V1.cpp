#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M;
    cin >> N >> M;
    vector<int> exclude(M,0);
    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        exclude[i] += (1 << (a-1)) + (1 << (b-1));
    }

    int cnt = 0;
    for (int i=0 ; i<(1 << N); i++) {
        bool flag = true;
        for (int j=0; j<M; j++) {
            int m = i & exclude[j];
            if (m > 0 && ((m & (m-1)) != 0)) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }

    cout << cnt;



    return 0;
}