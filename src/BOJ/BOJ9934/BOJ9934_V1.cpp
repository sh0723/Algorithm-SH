#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ret;
int inp_arr[1024];
int k;
void dfs(int size, int level, int idx) {
    if(size == 0)
        return;

    int next_size = size/2;
    int left = idx-next_size-1;
    int right = idx+next_size+1;
    ret[level+1].push_back(inp_arr[left]);
    ret[level+1].push_back(inp_arr[right]);
    dfs(next_size, level+1, left);
    dfs(next_size, level+1, right);

}
int main() {

    cin >> k;
    int size = 1 << k;
    size -=  1;
    for (int i=0; i<size; i++) {
        cin >> inp_arr[i];
    }

    ret.resize(k, vector<int>());
    ret[0].push_back(inp_arr[size/2]);
    dfs(size/2, 0, size/2);

    for (int i=0; i<k; i++) {
        size = ret[i].size();
        for (int j=0; j<size; j++) {
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}