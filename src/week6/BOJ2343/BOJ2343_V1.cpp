#include <bits/stdc++.h>
using namespace std;
int N,M;
int inp[100000];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    long long high=0, low=0;
    for (int i=0; i<N; i++) {
        cin >> inp[i];
        if (inp[i] > low)
            low = inp[i];
        high += inp[i];
    }
    low--;
    while(low + 1 < high) {
        long long mid = (high + low) / 2;
        long long temp = 0;
        int cnt = 1;
        for (int i=0; i<N; i++) {
            if (temp + inp[i] <= mid) {
                temp += inp[i];
            } else {
                temp = inp[i];
                cnt++;
            }
        }

        if (cnt <= M) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << high;


    return 0;
}