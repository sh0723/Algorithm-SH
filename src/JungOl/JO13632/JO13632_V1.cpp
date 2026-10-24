#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int ret[5001];
    ret[1] = 0;
    int put_num = 1;
    for (int i=2; i<=5000; i++) {
        ret[i] = put_num;
        if (i%2 == 0) put_num *= -1;
        else {
            put_num *= -1;
            put_num++;
        }
    }

    for (int i=1; i<=N; i++) {
        cout << ret[i] << ' ';
    }



    return 0;
}