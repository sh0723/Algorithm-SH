#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string org, aft;
    cin >> org >> aft;

    int org_len = org.size();
    int aft_len = aft.size();

    // 앞에서부터 일치하는 구간을 제외
    int diff_first = 0;
    while (diff_first < org_len &&
           diff_first < aft_len &&
           org[diff_first] == aft[diff_first]) {
        diff_first++;
           }

    int org_idx = org_len - 1;
    int aft_idx = aft_len - 1;

    // 앞에서 제외한 구간과 겹치지 않는 범위에서 뒤쪽 비교
    while (org_idx >= diff_first &&
           aft_idx >= diff_first &&
           org[org_idx] == aft[aft_idx]) {
        org_idx--;
        aft_idx--;
           }

    // 감염 후 문자열에서 남은 가운데 구간의 길이
    cout << aft_idx - diff_first + 1;

    return 0;
}