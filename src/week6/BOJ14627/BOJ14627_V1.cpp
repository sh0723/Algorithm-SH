#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<long long int> inp;
bool check(int num) {
    int cnt = 0, ret = 0;
    for (int i=0; i<N; i++) {
        cnt += inp[i]/num;
    }

    return cnt >= M;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> M;
    long long int low=1, high=LONG_MAX,mid;
    long long int sum=0;
    for (int i=0; i<N; i++) {
        long long int num;
        cin >> num;
        inp.push_back(num);
        sum += num;
        high = min(high, num);
    }

    int ret=1;
    while(low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            ret = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    int result = sum - ret * M;
    cout << result << '\n';
    return 0;
}