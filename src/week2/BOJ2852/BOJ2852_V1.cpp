#include <bits/stdc++.h>
using namespace std;
int N;
int score[2];
string getWinningTime(string st_time, string ed_time){
    int st_time_minutes = atoi(st_time.substr(0,2).c_str());
    int ed_time_minutes = atoi(ed_time.substr(0,2).c_str());
    int st_time_seconds = atoi(st_time.substr(3,2).c_str());
    int ed_time_seconds = atoi(ed_time.substr(3,2).c_str());

    int ret_minutes = ed_time_minutes - st_time_minutes;
    int ret_seconds;
    if (st_time_seconds > ed_time_seconds) {
        ret_minutes -= 1;
        ret_seconds = ed_time_seconds + 60 - st_time_seconds;
    } else {
        ret_seconds = ed_time_seconds - st_time_seconds;
    }

    string ret_minutes_str = to_string(ret_minutes);
    string ret_seconds_str = to_string(ret_seconds);

    if (ret_minutes >= 0 && ret_minutes <= 9)
        ret_minutes_str = "0" + to_string(ret_minutes);
    if (ret_seconds >= 0 && ret_seconds <= 9)
        ret_seconds_str = "0" + to_string(ret_seconds);

    return ret_minutes_str + ":" + ret_seconds_str;
}
void addWinningTime(string &target_winning_time, string time){
    int target_time_minutes = atoi(target_winning_time.substr(0,2).c_str());
    int plus_time_minutes = atoi(time.substr(0,2).c_str());
    int target_time_seconds = atoi(target_winning_time.substr(3,2).c_str());
    int plus_time_seconds = atoi(time.substr(3,2).c_str());

    int ret_minutes = target_time_minutes + plus_time_minutes;
    int ret_seconds = target_time_seconds + plus_time_seconds;
    if (ret_seconds > 60) {
        ret_minutes += 1;
        ret_seconds -= 60;
    }

    string ret_minutes_str = to_string(ret_minutes);
    string ret_seconds_str = to_string(ret_seconds);

    if (ret_minutes >= 0 && ret_minutes <= 9)
        ret_minutes_str = "0" + to_string(ret_minutes);
    if (ret_seconds >= 0 && ret_seconds <= 9)
        ret_seconds_str = "0" + to_string(ret_seconds);

    target_winning_time = ret_minutes_str + ":" + ret_seconds_str;
}
string team1_winning_time = "00:00";
string team2_winning_time = "00:00";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int before_winning_team = -1;
    string before_winning_start_time;
    string current_time;
    string current_winning_time;
    for (int i = 0; i < N; i++) {
        int team;

        cin >> team >> current_time;

        score[team - 1]++;

        if (score[0] == score[1]) {
            if (before_winning_team == 1) {
                current_winning_time = getWinningTime(before_winning_start_time, current_time);
                addWinningTime(team1_winning_time, current_winning_time);
                before_winning_team = -1;
            } else if (before_winning_team == 2) {
                current_winning_time = getWinningTime(before_winning_start_time, current_time);
                addWinningTime(team2_winning_time, current_winning_time);
                before_winning_team = -1;
            }
        } else {
            if (score[0] > score[1] && before_winning_team != 1) {
                before_winning_team = 1;
                before_winning_start_time = current_time;
            } else if (score[0] < score[1] && before_winning_team != 2) {
                before_winning_team = 2;
                before_winning_start_time = current_time;
            }
        }
    }

    if (before_winning_team == 1) {
        current_winning_time = getWinningTime(before_winning_start_time, "48:00");
        addWinningTime(team1_winning_time, current_winning_time);
    } else if (before_winning_team == 2) {
        current_winning_time = getWinningTime(before_winning_start_time, "48:00");
        addWinningTime(team2_winning_time, current_winning_time);
    }

    cout << team1_winning_time << "\n" <<  team2_winning_time;



    return 0;
}