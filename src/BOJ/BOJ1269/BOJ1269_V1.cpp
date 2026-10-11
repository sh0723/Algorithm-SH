#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<int, int> m;
    int a,b;
    cin >> a >> b;
    for (int i=0; i<a; i++) {
        int num;
        cin >> num;
        m[num] = 1;
    }
    for (int i=0; i<b; i++) {
        int num;
        cin >> num;
        if (m[num]) {
            m.erase(num);
        } else {
            m[num] = 1;
        }
    }

    cout << m.size() << '\n';





    return 0;
}