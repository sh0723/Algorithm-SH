#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tar, ret=0;
    int m,n;
    vector<int> pizza_a;
    vector<int> pizza_b;

    cin >> tar >> m >> n;

    vector<int> pizza_a_sum(tar+1,0);
    vector<int> pizza_b_sum(tar+1,0);

    for (int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        pizza_a.push_back(temp);
    }

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        pizza_b.push_back(temp);
    }

    pizza_a_sum[0] = 1;
    pizza_b_sum[0] = 1;
    for (int i=0; i<m; i++) {
        int tmp_sum = 0;
        for (int j=0; j<m-1; j++) {
            tmp_sum += pizza_a[(i+j)%m];
            if (tmp_sum > tar) break;
            pizza_a_sum[tmp_sum]++;
        }
    }

    int total_a_sum = 0;
    for (int i=0; i<m; i++) {
        total_a_sum += pizza_a[i];
    }
    if (total_a_sum <= tar) pizza_a_sum[total_a_sum]++;

    for (int i=0; i<n; i++) {
        int tmp_sum = 0;
        for (int j=0; j<n-1; j++) {
            tmp_sum += pizza_b[(i+j)%n];
            if (tmp_sum > tar) break;
            pizza_b_sum[tmp_sum]++;
        }
    }

    int total_b_sum = 0;
    for (int i=0; i<n; i++) {
        total_b_sum += pizza_b[i];
    }
    if (total_b_sum <= tar) pizza_b_sum[total_b_sum]++;

    for (int i=0; i<=tar; i++) {
        ret += ( pizza_a_sum[i] * pizza_b_sum[tar-i] );
    }

    cout << ret;
    return 0;
}