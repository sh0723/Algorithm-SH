#include <bits/stdc++.h>
using namespace std;
int main() {

    string str, bomb;
    cin >> str >> bomb;

    int bomb_size = bomb.size();
    string ret = "";
    for (int i=0; i<str.size(); i++) {
        ret.push_back(str[i]);
        if (ret.size() >= bomb_size) {
            bool flag = true;

            for (int j=0; j<bomb_size; j++) {
                if (ret[ret.size()-bomb_size+j] != bomb[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                for (int j=0; j<bomb_size; j++) {
                    ret.pop_back();
                }
            }
        }
    }

    if (ret == "") cout << "FRULA\n";
    else cout << ret << '\n';

    return 0;
}