#include <bits/stdc++.h>
using namespace std;
long long int N,M;
vector<int> available;
bool check(long long int num) {
    long long int cnt = M;
    for (int i=0; i<M; i++) {
        cnt += (num / available[i]);
    }

    return cnt >= N;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;



    for (int i=0; i<M; i++) {
        int num;
        cin >> num;
        available.push_back(num);
    }

    if (N <= M) {
        cout << N << '\n';
        return 0;
    }
    long long int mid,low=0,high=N*30, time;

    while(low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            time = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    long long finishTime = time;
    long long before = M;

    for (int i = 0; i < M; i++) {
        before += (finishTime - 1) / available[i];
    }

    long long int cnt = N-before;

    for (int i=0; i<M; i++) {
        if (finishTime % available[i] == 0) {
            cnt--;
            if (cnt == 0) {
                cout << i + 1;
                return 0;
            }
        }
    }

    return 0;
}
