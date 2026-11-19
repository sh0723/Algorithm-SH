#include <bits/stdc++.h>
using namespace std;

vector<long long int> inp;
vector<long long> p_sum;
long long int N,M;

bool can(int n) {
    for (int i=0; i<= N-n; i++) {
        long before,sum;

        if (i == 0)
            before = 0;
        else
            before = p_sum[i - 1];

        sum = p_sum[i + n - 1] - before;

        if (sum >= M) return true;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    inp.resize(N);
    p_sum.resize(N);

    for (int i=0;i<N;i++) {
        cin >> inp[i];
    }

    p_sum[0] = inp[0];
    if (p_sum[0] >= M) {
        cout << 1;
        return 0;
    }

    for (int i=1; i<N; i++) {
        p_sum[i] = p_sum[i - 1] + inp[i];
    }

    if (p_sum[N-1] < M) {
        cout << "VIVIZ SAD";
        return 0;
    }

    int low = 1, high = N;
    while (low < high) {
        int mid = (low + high) / 2;
        if (can(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low;

    return 0;
}