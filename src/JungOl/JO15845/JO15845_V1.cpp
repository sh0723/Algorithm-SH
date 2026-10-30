#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string org,aft;

    cin >> org >> aft;

    if (org == aft) {
        cout << 0;
        return 0;
    }
    if (org.find(aft) != string::npos) {
        cout << 0;
        return 0;
    }
    if (aft.find(org) != string :: npos) {
        cout << aft.size() - org.size();
        return 0;
    }
    
    int org_len = org.size();
    int aft_len = aft.size();
    int diff_first=0, diff_last=aft_len-1;

    int org_idx=0, aft_idx=0;
    while(true){
        if (org_idx >= org_len || aft_idx >= aft_len) {
            diff_first = aft_idx-1;
            break;
        }

        if (org[org_idx] != aft[aft_idx]) {
            diff_first = aft_idx;
            break;
        }

        org_idx++;
        aft_idx++;
    }

    org_idx = org_len-1;
    aft_idx = aft_len-1;
    while(true){
        if (org_idx < 0 || aft_idx < 0) {
            diff_last = aft_idx+1;
            break;
        }

        if (org[org_idx] != aft[aft_idx]) {
            diff_last = aft_idx;
            break;
        }

        org_idx--;
        aft_idx--;
    }


    if (diff_last < diff_first) cout << 0;
    else cout << diff_last - diff_first + 1;


    return 0;
}