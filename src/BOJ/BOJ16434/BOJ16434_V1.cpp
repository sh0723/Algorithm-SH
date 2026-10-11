#include <bits/stdc++.h>
using namespace std;
long long int HmaxHP,HcurHP,HATK,N;
struct room_struct{
    int type,atk,hp;
};
vector<room_struct> rooms;
bool check_valid() {
    long long int temp_atk = HATK;
    for (room_struct room : rooms) {
        if (room.type == 1) {
            if(room.hp <= temp_atk) continue;
            else {
                long long hitCount = (room.hp - 1) / temp_atk;
                long long need = hitCount * room.atk;

                if (HcurHP <= need) return false;
                else {
                    HcurHP -= need;
                }
            }
        } else {
            temp_atk += room.atk;
            HcurHP = min(HmaxHP, HcurHP + room.hp);
        }
    }
    return true;
}
long long int ret = LLONG_MAX;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> HATK;

    for (int i=0; i<N; i++) {
        int t,a,h;
        cin >> t >> a >> h;
        rooms.push_back({t,a,h});
    }

    long long int high = 1e18, low = 1;
    while(low <= high) {
        HmaxHP = (high + low) / 2;
        HcurHP = HmaxHP;

        if (check_valid()) {
            ret = min(ret, HmaxHP);
            high = HmaxHP-1;
        } else {
            low = HmaxHP+1;
        }
    }

    cout << ret << '\n';
    return 0;
}