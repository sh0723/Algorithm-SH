#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string left, right;
    cin >> left;


    cin >> N;
    for (int i=0; i<N; i++) {
        char c;
        cin >> c;

        if (c == 'P') {
            char p_c;
            cin >> p_c;
            left.push_back(p_c);
        } else if (c == 'B') {
            if (left.size())
                left.pop_back();
        } else if (c == 'L') {
            if (left.size()) {
                right.push_back(left.back());
                left.pop_back();
            }
        } else{
            if (right.size()) {
                left.push_back(right.back());
                right.pop_back();
            }
        }
    }
    reverse(right.begin(), right.end());
    cout << left + right;


    return 0;
}