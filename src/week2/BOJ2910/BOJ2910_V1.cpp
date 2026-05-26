#include <bits/stdc++.h>
using namespace std;
bool sorting_algorithm(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<1>(a) != get<1>(b)) {
        return get<1>(a) > get<1>(b);
    }
    return get<2>(a) < get<2>(b);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,C;
    cin >> N >> C;

    //입력 숫자, 입력 숫자 개수, 입력 숫자의 입력순서
    map<int, tuple<int, int, int> > m;
    vector<tuple<int, int, int> > ret;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (m.find(temp) != m.end()) {
            get<1>(m[temp])++;
        } else {
            m[temp] = {temp, 1, i};
        }
    }

    for (auto it : m) {
        ret.push_back(it.second);
    }

    sort(ret.begin(), ret.end(), sorting_algorithm);

    for (auto it : ret) {
        for (int i=0; i<get<1>(it); i++) {
            cout << get<0>(it) << " ";
        }
    }


    return 0;
}