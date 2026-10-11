#include <bits/stdc++.h>
using namespace std;
vector<long long> ret;
int N;
int T;
int get_num_cnt(long long target_num, long long num) {
    while(num <target_num)
        num *= num;

    long long cnt = 0;
    while(num != 1) {
        cnt += (target_num / num);
        num /= 5;
    }

    return cnt;
}
int main() {


    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        long long cnt_5 = get_num_cnt(N, 5);
        ret.push_back(cnt_5);
    }

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << "\n";
    }

    return 0;
}