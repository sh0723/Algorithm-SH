#include <bits/stdc++.h>
using namespace std;
pair<char, int> rome_num[7] = {
    {'M', 1000},{'D',500},{'C',100},{'L',50},{'X', 10},{'V', 5},{'I', 1}
};

pair<string, int> rome_num_str[13] = {
    {"M", 1000},{"CM", 900},{"D",500},{"CD",400},{"C",100},{"XC", 90},{"L",50},{"XL",40},{"X", 10},{"IX", 9},{"V", 5},{"IV", 4},{"I", 1}
};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string inp[2];
    for (int i=0; i<2; i++) {
        cin >> inp[i];
    }

    int inp_num[2] = {0,0};

    for (int i=0; i<2; i++) {
        int len = inp[i].size();
        int cur = 0, next = 0;
        for (int j=0; j<len-1; j++) {
            for (int k=0; k<7; k++) {
                if (inp[i][j] == rome_num[k].first) {
                    cur = k;
                }
                if (inp[i][j+1] == rome_num[k].first) {
                    next = k;
                }
            }
            if (cur > next) {
                inp_num[i] -= rome_num[cur].second;
            } else {
                inp_num[i] += rome_num[cur].second;
            }
        }
        inp_num[i] += rome_num[next].second;
    }

    int ret = inp_num[0] + inp_num[1];
    int temp_ret = ret;
    string ret_string = "";
    for (int i=0; i<13; i++) {
        int it_num = temp_ret / rome_num_str[i].second;
        if ( it_num != 0) {
            for (int j=0; j<it_num; j++) {
                ret_string += rome_num_str[i].first;
            }
            temp_ret %= rome_num_str[i].second;
        }
    }

    cout << ret << '\n' << ret_string;
    return 0;
}