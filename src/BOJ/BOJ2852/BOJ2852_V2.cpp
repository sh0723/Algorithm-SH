#include <bits/stdc++.h>
using namespace std;
int N;
int team_1_winning_time;
int team_2_winning_time;
void calculate_winning_time(string st, string ed, int &winning_team) {
    int st_time_minutes = atoi(st.substr(0,2).c_str());
    int ed_time_minutes = atoi(ed.substr(0,2).c_str());
    int st_time_seconds = atoi(st.substr(3,2).c_str());
    int ed_time_seconds = atoi(ed.substr(3,2).c_str());

    st_time_seconds += 60 * st_time_minutes;
    ed_time_seconds += 60 * ed_time_minutes;

    winning_team += (ed_time_seconds - st_time_seconds);
}
string make_time(int seconds){
    int minutes = seconds / 60;
    seconds = seconds % 60;
    string minutes_str = "";
    string seconds_str = "";
    minutes_str = to_string(minutes);
    seconds_str = to_string(seconds);

    if (minutes >= 0 && minutes <= 9) {
        minutes_str = "0" +  to_string(minutes);
    }
    if (seconds >= 0 && seconds <= 9) {
        seconds_str = "0" + to_string(seconds);
    }

    return minutes_str + ":" + seconds_str;
}
int main() {

    cin >> N;
    int score[2] = {0, 0};
    string prev_time;
    for (int i = 0; i < N; i++) {
        int team;
        string time;
        cin >> team >> time;
        if (score[1] > score[0]) {
            calculate_winning_time(prev_time,time, team_2_winning_time);
        }
        if (score[0] > score[1]) {
            calculate_winning_time(prev_time,time, team_1_winning_time);
        }
        score[team-1]++;
        prev_time = time;
    }

    if (score[1] > score[0]) {
        calculate_winning_time(prev_time,"48:00", team_2_winning_time);
    }
    if (score[0] > score[1]) {
        calculate_winning_time(prev_time,"48:00", team_1_winning_time);
    }

    cout << make_time(team_1_winning_time) << "\n" << make_time(team_2_winning_time);

    return 0;
}