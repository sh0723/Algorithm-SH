#include <bits/stdc++.h>
using namespace std;
pair<int, long long> get_num(int n) {
    if (n == 1) return {1, 1};

    int len = 2;
    long long pre_pre = 1, pre = 1;
    long long total = 2;

    while (total < n) {
        long long curr = pre_pre + pre;
        total += curr;
        len++;

        pre_pre = pre;
        pre = curr;
    }

    return {len, n - (total - pre)};
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    auto [len, idx] = get_num(n);




    return 0;
}