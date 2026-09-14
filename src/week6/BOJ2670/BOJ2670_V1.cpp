#include <bits/stdc++.h>
using namespace std;
double arr[10000];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    double ret = arr[0];
    double cur = arr[0];
    for (int i=1; i<N; i++) {
        if (cur * arr[i] < arr[i]) {
            cur = arr[i];
        } else {
            cur *= arr[i];
        }
        ret = max(cur, ret);
    }

//    printf("%.3lf", ret + 0.00001);
    cout << fixed << setprecision(3) << ret << '\n';
    return 0;
}