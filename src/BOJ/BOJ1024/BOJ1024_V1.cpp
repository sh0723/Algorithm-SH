#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tar_sum, min_cnt;
    cin >> tar_sum >> min_cnt;

    int sum_arr[101] = {0};

    for (int i=2; i<=100; i++) {
        sum_arr[i] = sum_arr[i-1] + i-1;
    }

    int num_cnt = min_cnt;
    int ret = -1;
    while(num_cnt <= 100) {
        int tmp_tar = tar_sum;
        tmp_tar -= sum_arr[num_cnt];
        if (tmp_tar >= 0 && tmp_tar % num_cnt == 0) {
            ret = tmp_tar / num_cnt;
            break;
        } else {
            num_cnt++;
        }
    }

    if (ret == -1) cout << ret;
    else {
        for (int i=0; i<num_cnt; i++) {
            cout << ret + i << ' ';
        }
    }

    return 0;
}