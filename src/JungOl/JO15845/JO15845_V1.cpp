#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string org, aft;
    cin >> org >> aft;

    int org_len = org.size();
    int aft_len = aft.size();

    int diff_first = 0;
    while (diff_first < org_len && diff_first < aft_len &&org[diff_first] == aft[diff_first]) {
        diff_first++;
    }

    int org_idx = org_len - 1;
    int aft_idx = aft_len - 1;

    while (org_idx >= diff_first && aft_idx >= diff_first && org[org_idx] == aft[aft_idx]) {
        org_idx--;
        aft_idx--;
    }

    cout << aft_idx - diff_first + 1;

    return 0;
}