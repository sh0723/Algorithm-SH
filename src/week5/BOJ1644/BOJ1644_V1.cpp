#include <bits/stdc++.h>
using namespace std;
bool a[4000001];
int arr[200001];
int p=0;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;
    cin >> n;

    for (int i=2; i<=n; i++) {
        if (a[i]) continue;
        for (int j=2*i; j<=n; j+=i) {
            a[j] = true;
        }
    }

    for (int i=2; i<=n; i++) {
        if (!a[i]) arr[p++] = i;
    }

    int ret = 0;
    int sum = 0;
    int st = 0, ed = 0;
    while(true) {
        if (sum >= n) {
            if (sum == n) ret++;
            sum -= arr[st++];
        } else {
            if (ed == p) break;
            sum += arr[ed++];
        }
    }

    cout << ret << '\n';

    return 0;
}