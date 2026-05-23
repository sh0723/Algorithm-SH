#include<bits/stdc++.h>
using namespace std;
vector<int> A;
vector<int> B;
int count_A;
int count_B;
vector<string> input_str;
int result_cnt;
void clear_input() {
    count_A = 0;
    count_B = 0;
    A.clear();
    B.clear();
}

int check(const vector<int>& vec) {
    for (int j=0; j<vec.size()/2; j++) {
        int dist = vec[2*j+1] - vec[2*j];
        if (dist % 2 == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        input_str.push_back(temp);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<input_str[i].size(); j++) {
            if (input_str[i][j] == 'A') {
                A.push_back(j);
                count_A++;
            }
            if (input_str[i][j] == 'B') {
                B.push_back(j);
                count_B++;
            }
        }
        if (count_A %2 == 1 || count_B %2 == 1) {
            clear_input();
            continue;
        }

        int flag_A = check(A);
        int flag_B = check(B);


        if (flag_A && flag_B)
            result_cnt++;

        clear_input();
    }

    cout<< result_cnt << "\n";


}