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

    int n;
    cin >> n;

    auto [len, idx] = get_num(n);

    vector<long long> ways(len + 1);
    ways[0] = 1;
    ways[1] = 2;

    for (int i = 2; i <= len; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    string answer = "1";

    for (int pos = 1; pos < len; pos++) {
        if (answer.back() == '1') {
            answer += '0';
            continue;
        }

        int remaining = len - pos - 1;
        long long zero_count = ways[remaining];

        if (idx <= zero_count) {
            answer += '0';
        } else {
            answer += '1';
            idx -= zero_count;
        }
    }

    cout << answer << '\n';
    return 0;
}