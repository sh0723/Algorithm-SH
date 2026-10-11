#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<long long int> inp;
bool check(long long int num) {
    long long int cnt = 0;
    for (int i=0; i<N; i++) {
        cnt += inp[i]/num;
        if (cnt >= M) return true;
    }

    return false;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> M;
    long long int low=1, high=0,mid;
    long long int sum=0;
    for (int i=0; i<N; i++) {
        long long int num;
        cin >> num;
        inp.push_back(num);
        sum += num;
        high = max(high, num);
    }

    long long int ret=0;
    while(low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            ret = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    long long int result = sum - ret * M;
    cout << result << '\n';
    return 0;
}
