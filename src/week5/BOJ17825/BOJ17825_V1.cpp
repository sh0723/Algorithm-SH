#include <bits/stdc++.h>
using namespace std;
struct horse{
    int index = 0;
    int sum = 0;
};
int dice_turn[10];
horse ret[4];
int max_val = INT_MIN;
int int_map[33] = {
    0,2,4,6,8,10,
    12,14,16,18,20,
    13,16,19,
    22,24,
    22,24,26,28,30,
    28,27,26,25,
    30,35,
    32,34,36,38,40,
    0
};
vector<vector<int>> link(33, vector<int>());
void initialization() {
    for (int i=0; i<5; i++) {
        link[i].push_back(i+1);
    }
    link[5].push_back(6);
    link[5].push_back(11);
    for (int i=6; i<10; i++) {
        link[i].push_back(i+1);
    }
    link[11].push_back(12);
    link[12].push_back(13);
    link[13].push_back(24);
    link[10].push_back(16);
    link[14].push_back(15);
    link[15].push_back(24);
    link[10].push_back(14);
    for (int i=16; i<20; i++) {
        link[i].push_back(i+1);
    }
    for (int i=21; i<24; i++) {
        link[i].push_back(i+1);
    }
    link[24].push_back(25);
    link[25].push_back(26);
    link[26].push_back(31);

    link[20].push_back(27);
    link[20].push_back(21);

    for (int i=27; i<=31; i++) {
        link[i].push_back(i+1);
    }
}

bool can_go(int horse_index, int cnt) {
    int st = ret[horse_index].index;
    int curr = st;
    if (st == 5 || st == 10 || st == 20) {
        curr = link[curr][1];
        for (int i=1; i<cnt; i++) {
            if (curr == 32) break;
            curr = link[curr][0];
        }
    } else if (st == 32) {
        return false;
    } else {
        for (int i=0; i<cnt; i++) {
            if (curr == 32) break;
            curr = link[curr][0];
        }
    }

    for (int i=0; i<4; i++) {
        if (curr != 32 && ret[i].index == curr) {
            return false;
        }
    }
    return true;
}

void go(int horse_index, int cnt) {
    int st = ret[horse_index].index;
    int curr = st;
    if (st == 5 || st == 10 || st == 20) {
        curr = link[curr][1];
        for (int i=1; i<cnt; i++) {
            if (curr == 32) break;
            curr = link[curr][0];
        }
    } else {
        for (int i=0; i<cnt; i++) {
            if (curr == 32) break;
            curr = link[curr][0];
        }
    }
    ret[horse_index].index = curr;
    ret[horse_index].sum += int_map[curr];
}

void solve(int horse_index, int turn) {
    int curr_index = ret[horse_index].index;
    int curr_sum = ret[horse_index].sum;

    go(horse_index, dice_turn[turn]);
    if (turn == 9) {
        int sum = 0;
        for (int i=0; i<4; i++) {
            sum += ret[i].sum;
        }
        max_val = max(max_val, sum);
        ret[horse_index].index = curr_index;
        ret[horse_index].sum = curr_sum;
        return;
    }
    for (int i=0; i<4; i++) {
        if (!can_go(i,dice_turn[turn+1])) continue;
        solve(i, turn+1);
    }
    ret[horse_index].index = curr_index;
    ret[horse_index].sum = curr_sum;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i=0; i<10; i++)
        cin >> dice_turn[i];
    initialization();
    solve(0,0);

    cout << max_val;


    return 0;
}