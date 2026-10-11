#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A, B, ret;
    cin >> A >> B;
    int carr = 0;
    bool A_large;
    int cnt, aidx = A.size()-1, bidx = B.size()-1;
    if (A.size() > B.size()) {
        A_large = true;
        cnt = B.size();
    } else {
        A_large = false;
        cnt = A.size();
    }

    while(cnt--) {
        int a, b;
        a = A[aidx--] - '0';
        b = B[bidx--] - '0';
        if (a+b+carr >= 10) {
            ret = to_string((a + b + carr - 10)) + ret;
            carr = 1;
        } else {
            ret = to_string(a + b + carr) + ret;
            carr = 0;
        }
    }

    if (A_large) {
        while(true){
            if (aidx == -1) break;
            int a = A[aidx--] - '0';
            if (a+carr >= 10) {
                ret = to_string((a + carr - 10)) + ret;
                carr = 1;
            } else {
                ret = to_string(a + carr) + ret;
                carr = 0;
            }
        }
    } else {
        while(true){
            if (bidx == -1) break;
            int b = B[bidx--] - '0';
            if (b+carr >= 10) {
                ret = to_string((b + carr - 10)) + ret;
                carr = 1;
            } else {
                ret = to_string(b + carr) + ret;
                carr = 0;
            }
        }
    }
    if (carr) {
        ret = to_string(carr) + ret;
    }

    cout << ret << '\n';
    return 0;
}