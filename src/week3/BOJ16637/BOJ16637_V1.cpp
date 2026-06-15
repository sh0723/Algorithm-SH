    #include <bits/stdc++.h>
    using namespace std;
    int N;
    string inp_string;
    vector<char> operators;
    vector<int> num;
    int max_num = INT_MIN;
    int calculate(char op, int a, int b) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return a - b;
        } else {
            return a * b;
        }
    }

    void solve(int idx, int cur_num) {
        if (idx == num.size()-1) {
            max_num = max(max_num, cur_num);
            return;
        }

        solve(idx+1, calculate(operators[idx], cur_num, num[idx+1]));
        if (idx + 2 <= num.size()-1) {
            int temp = calculate(operators[idx+1], num[idx+1], num[idx+2]);
            solve(idx+2, calculate(operators[idx], cur_num, temp));
        }
        return;
    }

    int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> N;
        cin >> inp_string;

        for (int i = 0; i < N; i++) {
            if (i%2 == 0) {
                num.push_back(inp_string[i] - '0');
            } else {
                operators.push_back(inp_string[i]);
            }
        }

        solve(0,num[0]);

        cout << max_num << '\n';


        return 0;
    }