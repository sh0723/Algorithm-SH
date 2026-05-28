#include <bits/stdc++.h>
using namespace std;
int sky[100][100];
int H, W;
int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> H >> W;

   for (int i = 0; i < H; i++) {
       string temp;
       cin >> temp;
       for (int j = 0; j < W; j++) {
           if (temp[j] == 'c')
               sky[i][j] = 1;
           else
               sky[i][j] = 0;
       }
   }


    int time = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!sky[i][j]) {
                if (time == -1)
                    sky[i][j] = time;
                else {
                    time++;
                    sky[i][j] = time;
                }
            } else {
                time = 0;
                sky[i][j] = time;
            }
        }
        time = -1;
    }

    for (int i=0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << sky[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}