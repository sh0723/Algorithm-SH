#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> inp;
bool check_available(int money) {
    int curr = money;
    int cnt = 1;
    for (int i=0; i<N; i++) {
        curr -= inp[i];
        if (curr < 0) {
            cnt++;
            curr = money-inp[i];
        }

        if (cnt > M) return false;
    }
    return true;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    int low=INT_MIN,high,mid;

    int sum = 0;
    for (int i=0; i<N; i++) {
        int money;
        cin >> money;
        inp.push_back(money);
        low = max(low,money);
        sum += money;
    }
    high = sum;

    int ret = high;
    while(low <= high) {
        mid = (low + high) / 2;

        if (check_available(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << ret << '\n';


    return 0;
}