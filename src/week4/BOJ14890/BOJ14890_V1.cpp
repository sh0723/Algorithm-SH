#include <bits/stdc++.h>
using namespace std;
int n,m;
int ret;
void calculate(int arr[101][101]) {
    for (int i=0; i<n; i++) {
        int cnt = 1;
        int j;
        for (j=0; j<n-1; j++) {
            if (arr[i][j] == arr[i][j+1]) cnt++;
            else if (arr[i][j] + 1 == arr[i][j+1] && cnt >= m) cnt = 1;
            else if (arr[i][j] - 1 == arr[i][j+1] && cnt >= 0) cnt = -(m-1);
            else break;
        }
        if (j == n-1 && cnt >= 0) ret++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int a[101][101], b[101][101];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    calculate(a);
    calculate(b);

    cout << ret << '\n';

    return 0;
}