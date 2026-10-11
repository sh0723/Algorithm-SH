#include <bits/stdc++.h>
using namespace std;
int T;
deque<int> split(string s, char delim){
    deque<int> return_vec;
    auto start = 0;
    auto end = s.find(delim);
    while(end != string::npos){
        return_vec.push_back(stoi(s.substr(start, end - start)));
        start = end + 1;
        end = s.find(delim, start);
    }
    return_vec.push_back(stoi(s.substr(start)));
    return return_vec;
}
int main() {

    cin >> T;

    for (int i = 0; i < T; i++) {
        string func, inp_num;
        int inp_num_cnt;
        bool flag = true;
        bool reverse_flag = false;
        cin >> func >> inp_num_cnt >> inp_num;
        inp_num = inp_num.substr(1, inp_num.size() - 2);
        deque<int> ret;
        if (inp_num.size())
            ret = split(inp_num,',');

        for (int j=0; j<func.size(); j++) {
            if (func[j] == 'R' && ret.size()) {
                reverse_flag = !reverse_flag;
            } else {
                if (ret.empty()) {
                    flag= false;
                    break;
                } else {
                    if (reverse_flag) {
                        ret.pop_back();
                    } else {
                        ret.pop_front();
                    }
                }
            }
        }
        if (reverse_flag) reverse(ret.begin(), ret.end());

        if (flag) {
            cout << "[";
            for (int k=0; k<ret.size(); k++) {
                if (k != ret.size() - 1) {
                    cout << ret[k] << ",";
                } else {
                    cout << ret[k];
                }
            }
            cout << "]\n";
        } else cout << "error" << '\n';
    }


    return 0;
}