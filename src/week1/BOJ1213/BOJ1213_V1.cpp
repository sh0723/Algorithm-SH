#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt[26] = {0};
    string input;
    int alphabet_count = 0;
    int check_odd_or_even = 0;
    int odd_num = -1;
    cin >> input;

// 1. 입력값에 들어있는 알파벳이 몇종류? + 2. 알파벳의 각종류가 몇개씩 갖고있음?
    for (int i=0; i<input.length(); i++) {
        if (cnt[input[i] - 'A'] == 0) {
            alphabet_count++;
            if (check_odd_or_even == 0)
                check_odd_or_even = 1;
            else
                check_odd_or_even = 0;
        }

        cnt[input[i] - 'A']++;
    }

// 3. 1이 만약 홀수라면 , 1이 만약 짝수라면
    if (check_odd_or_even == 1 || (check_odd_or_even == 0 && alphabet_count == 2)) {
        for (int i=0; i<26; i++) {
            if ((odd_num != -1 && cnt[i] % 2 == 1) ) {
                cout << "I'm Sorry Hansoo" << "\n";
                return 0;
            }
            if (cnt[i] % 2 == 1 && odd_num == -1) {
                odd_num = i;
            }
        }
    } else if (check_odd_or_even == 0 && alphabet_count != 2) {
        for (int i=0; i<26; i++) {
            if (cnt[i] % 2 == 1) {
                cout << "I'm Sorry Hansoo" << "\n";
                return 0;
            }
        }
    }


// 4. 1이 홀수라면 -> 홀수인것 제외하고 나머지를 순서대로 개수/2 해서 result string에 더하고 하나는 reverse 시킨후 홀수인 스트링 중간에 더해서 만듬
    string result_front = "" , result_middle = "", result_back = "";
    if (alphabet_count == 2 && odd_num != -1) {
        for (int i=0; i<26; i++) {
            if (cnt[i] != 0) {
                for (int j=0; j<(cnt[i]/2); j++) {
                    result_front += (char)('A' + i);
                    result_back += (char)('A' + i);
                }
            }

        }
        result_middle += (char)('A'+ odd_num);
        result_front += result_middle;
        reverse(result_back.begin(), result_back.end());
        result_front += result_back;

        cout << result_front << "\n";
        return 0;
    }

    if (check_odd_or_even == 1) {
        for (int i=0; i<26; i++) {
            if (i == odd_num) {
                result_middle += (char)('A' + odd_num);
                continue;
            }
            if (cnt[i] != 0) {
                for (int j=0; j<(cnt[i]/2); j++) {
                    result_front += (char)('A' + i);
                    result_back += (char)('A' + i);
                }
            }
        }
    } else {
        for (int i=0; i<26; i++) {
            if (cnt[i] != 0) {
                for (int j=0; j<(cnt[i]/2); j++) {
                    result_front += (char)('A' + i);
                    result_back += (char)('A' + i);
                }
            }
        }
    }

    result_front += result_middle;
    reverse(result_back.begin(), result_back.end());
    result_front += result_back;

    cout << result_front << "\n";

}