#include <bits/stdc++.h>
using namespace std;
int N;
int num[11];
int op[4];
int max_val = INT_MIN;
int min_val = INT_MAX;
int calculate(int a, int b, int oper) {
    if (oper == 0) {
        return a + b;
    } else if (oper == 1) {
        return a - b;
    } else if (oper == 2) {
        return a * b;
    } else {
        return a / b;
    }

    return 0;
}
void dfs(int oper, int index, int ret_num) {

    ret_num = calculate(ret_num, num[index], oper);
    op[oper]--;
    for (int i=0; i<4; i++) {
        if (op[i] == 0) continue;
        dfs(i, index+1, ret_num);
    }
    op[oper]++;

    if (index == N-1) {
        max_val = max(ret_num, max_val);
        min_val = min(ret_num, min_val);
        return;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }

    for (int i=0; i<4; i++) {
        cin >> op[i];
    }

    for (int i=0; i<4; i++) {
        if (op[i] == 0) continue;
        dfs(i, 1, num[0]);
    }

    cout << max_val << '\n' << min_val;

    return 0;
}