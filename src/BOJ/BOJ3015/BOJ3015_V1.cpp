#include <bits/stdc++.h>
using namespace std;
int n;
long long int ret, temp;
stack<pair<long long int, long long int>> s;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        int cnt = 1;
        while (s.size() && s.top().first <= temp) {
            ret += s.top().second;
            if (s.top().first == temp) {
                cnt = s.top().second + 1;
            } else {
                cnt = 1;
            }
            s.pop();
        }

        if (s.size()) ret++;
        s.push({temp,cnt});
    }

    cout << ret << '\n';
    return 0;
}