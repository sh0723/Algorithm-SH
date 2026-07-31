#include <bits/stdc++.h>
using namespace std;
int T;
bool used[1000];
vector<string> inp;
vector<pair<int, int>> inp_act;
void act_rotate(int num, bool vec) {
    string tmp;
    tmp.resize(8);

    if(vec) {
        for (int i=0; i<8; i++) {
            tmp[(i+1) % 8] = inp[num][i];
        }
    } else {
        for (int i=0; i<8; i++) {
            tmp[(i+7) % 8] = inp[num][i];
        }
    }
    inp[num] = tmp;
}
void rotate_topni(int num, bool vec) {
    if (T == 1) {
        act_rotate(num,vec);
        return;
    }
    if (num == 0) {
        if (!used[num+1] && (inp[num][2] != inp[num+1][6])) {
            used[num+1] = true;
            rotate_topni(num+1, !vec);
        }
    } else if (num == T-1) {
        if (!used[num-1] && (inp[num-1][2] != inp[num][6])) {
            used[num-1] = true;
            rotate_topni(num-1, !vec);
        }
    } else {
        if (!used[num+1] && (inp[num][2] != inp[num+1][6])) {
            used[num+1] = true;
            rotate_topni(num+1, !vec);
        }

        if (!used[num-1] && (inp[num-1][2] != inp[num][6])) {
            used[num-1] = true;
            rotate_topni(num-1, !vec);
        }
    }
    act_rotate(num,vec);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int i=0; i<T; i++) {
        string tmp;
        cin >> tmp;
        inp.push_back(tmp);
    }
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int num, vec;
        cin >> num >> vec;
        inp_act.push_back({num-1, vec});
    }

    for (pair<int, int> act : inp_act) {
        memset(used, false, sizeof(used));
        used[act.first] = true;
        rotate_topni(act.first, act.second==1);
    }

    int ret = 0;
    for (int i=0; i<T; i++) {
        if (inp[i][0] == '1') ret++;
    }

    cout << ret;
    return 0;
}
