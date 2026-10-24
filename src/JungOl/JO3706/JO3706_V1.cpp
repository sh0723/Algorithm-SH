#include <bits/stdc++.h>
using namespace std;
long long int get_possilbe_cnt(int num) {
    long long int cnt = 0;
    for (int i=0; i<num; i++) {
        for (int j=i+1; j<num; j++) {
            cnt++;
        }
    }
    return cnt;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> prefix_sum(N,0);
    cin >> prefix_sum[0];
    for (int i=1; i<N; i++) {
        int num;
        cin >> num;
        prefix_sum[i] = prefix_sum[i-1] + num;
    }

    map<int, int> m;
    for (int i=0; i<N; i++) {
        m[prefix_sum[i]]++;
    }

    long long int ret = 0;
    for (auto[num, num_cnt] : m) {
        if (num_cnt >= 2) {
            ret += get_possilbe_cnt(num_cnt);
        }
        if (num == 0) ret+=num_cnt;
    }

    cout << ret;

    return 0;
}