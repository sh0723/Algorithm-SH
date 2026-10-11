#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> visited;
int N,M;
int chicken_cnt, house_cnt;
int min_cnt = INT_MAX;



int calculate(int house_idx, int chicken_idx) {
    int y = house[house_idx].first - chicken[chicken_idx].first;
    int x = house[house_idx].second - chicken[chicken_idx].second;

    if (y < 0)
        y *= -1;
    if (x < 0)
        x *= -1;

    return y + x;
}

void dfs(int idx, int distance, vector<int> live_chicken) {
    if (idx > house_cnt-1) {
        min_cnt = min(min_cnt, distance);
        return;
    }

    for (int i=0; i<live_chicken.size(); i++) {
        if (visited[idx][live_chicken[i]] == 1) continue;
        visited[idx][live_chicken[i]] = 1;
        int plus_distance = calculate(idx, live_chicken[i]);
        distance += plus_distance;
        dfs(idx+1, distance, live_chicken);
        distance -= plus_distance;
        visited[idx][live_chicken[i]] = 0;
    }
}

void combi(int start, vector<int> b, int k){
    if(b.size() == k){
        dfs(0, 0, b);
        return;
    }
    for (int i=start+1; i<chicken_cnt; i++){
        b.push_back(i);
        combi(i, b, k);
        b.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                house.push_back(make_pair(i, j));
            } else if (temp == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    chicken_cnt = chicken.size();
    house_cnt = house.size();

    for (int i = 0; i < house_cnt; i++) {
        visited.push_back(vector<int>());
        for (int j = 0; j < chicken_cnt; j++) {
            visited[i].push_back(0);
        }
    }
    vector<int> live_chicken;
    combi(-1, live_chicken, M);

    cout << min_cnt << endl;

    return 0;
}