#include <bits/stdc++.h>
using namespace std;
int num_arr[10] = {0,1,2,3,4,5,6,7,8,9}, used[10];
int k;
vector<char> sign;
vector<int> ret;
vector<int> max_ret;
vector<int> min_ret;
bool calculate(int level, int first, int second) {
    if (sign[level] == '<')
        return first < second;
    else
        return first > second;
}
void dfs(int level) {
    if (level == k+1) {
        for (int i=0; i<=k; i++) {
            if (ret[i] == max_ret[i])
                continue;
            else {
                if (ret[i] > max_ret[i]) {
                    max_ret = ret;
                }
                break;
            }
        }

        for (int i=0; i<=k; i++) {
            if (ret[i] == min_ret[i])
                continue;
            else {
                if (ret[i] < min_ret[i]) {
                    min_ret = ret;
                }
                break;
            }
        }

        return;
    }

    for (int i=0; i<10; i++) {
        if (used[i] == 1) continue;
        if (level != 0 && !calculate(level-1, ret[level-1], i)) continue;
        else {
            ret.push_back(i);
            used[i] = 1;
            dfs(level+1);
            used[i] = 0;
            ret.pop_back();
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    max_ret.resize(k+1);
    min_ret.resize(k+1);
    fill(max_ret.begin(), max_ret.end(), 0);
    fill(min_ret.begin(), min_ret.end(), 9);

    for (int i=0; i<k; i++) {
        char s;
        cin >> s;
        sign.push_back(s);
    }

    dfs(0);

    for (int i=0; i<=k; i++) {
        cout << max_ret[i];
    }
    cout << '\n';
    for (int i=0; i<=k; i++) {
        cout << min_ret[i];
    }
    cout << '\n';

    return 0;
}