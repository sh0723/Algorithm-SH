#include <bits/stdc++.h>
using namespace std;
int sum = 0;
vector<int> littleMan;
int liyer[2] = {0};
void getSum(){
    for (int i = 0; i < 9; i++){
        sum += littleMan[i];
    }
}

void Combination(){
    for (int i = 0; i < 9; i++){
        for (int j = i+1; j < 9; j++){
            int temp = sum;
            temp -= littleMan[i];
            temp -= littleMan[j];

            if (temp == 100) {
                liyer[0] = i;
                liyer[1] = j;
            }
        }
    }
}

int main(){
    for (int i = 1; i <= 9; i++){
        int tmp;
        cin >> tmp;
        littleMan.push_back(tmp);
    }

    getSum();
    sort(littleMan.begin(), littleMan.end());
    Combination();

    for (int i = 0; i < 9; i++){
        int flag = 0;
        for (int j=0; j<2; j++) {
            if ( i == liyer[j]){
                flag = 1;
                break;
            }
        }
        if (flag){
            continue;
        }
        cout << littleMan[i] << endl;
    }


    return 0;
}