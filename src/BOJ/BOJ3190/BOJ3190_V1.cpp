#include <bits/stdc++.h>
using namespace std;
// (0,1), (1,0), (0, -1), (-1,0)
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int N;
int num;
vector<pair<int, int>> apple;
vector<pair<int, char>> direction_change;
deque<pair<int, int>> snake;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    cin >> num;
    for (int i=0; i<num; i++) {
        int y,x;
        cin >> y >> x;
        apple.push_back({y-1,x-1});
    }

    cin >> num;
    for (int i=0; i<num; i++) {
        int t;
        char direction;
        cin >> t >> direction;
        direction_change.push_back({t, direction});
    }

    int t=0;
    int d_index=0;
    snake.push_front({0,0});
    bool break_flag = false;
    bool eat_apple = false;
    while(true) {
        t++;
        auto[y,x] = snake.front();
        int ny = y + dy[d_index];
        int nx = x + dx[d_index];

        if (ny < 0 || nx < 0 || ny > N-1 || nx > N-1) {
            break_flag = true;
        }
        for (auto [ty, tx] : snake) {
            if (ty == ny && tx == nx){
                break_flag = true;
            }
        }
        if (break_flag) break;

        for (auto &[ay, ax] : apple) {
            if (ay == ny && ax == nx) {
                eat_apple = true;
                ay = -1;
                ax = -1;
                break;
            }
        }

        snake.push_front({ny,nx});
        if (!eat_apple) {
            snake.pop_back();
        } else {
            eat_apple = false;
        }

        for (auto [time,direct] : direction_change) {
            if (time == t) {
                if (direct == 'L') {
                    d_index = (d_index + 3) % 4;
                }
                if (direct == 'D') {
                    d_index = (d_index + 1) % 4;
                }
            }
        }

    }

    cout << t;
    return 0;
}