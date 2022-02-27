#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int a[1000005];

void pairsOfSong(vector<int> arr, int time) {
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        int val = arr[i]%time;
        a[val]++;
    }

    /*for (int i = 0; i < time; i++) {
        cout << a[i] << " "; 
    }
    cout << endl;*/
    int x = a[0];
    ans = x*(x-1)/2;
    if (time%2 == 0) {
        //cout << time << endl;
        for (int i = 1; i < time/2; i++) {
            ans = ans + a[i] * a[time - i];
            //cout << ans << endl;
        }
        int y = a[time/2];
        ans = ans + y*(y-1)/2; 
    }
    else {
        for (int i = 1; i <= time/2; i++) {
            ans = ans + a[i] * a[time - i];
        }
    }
}
int main() {
    vector<int> arr; 
    int time;
    arr = {57,73,35,92,1,60,88,52,96,98}, time = 50;
    pairsOfSong(arr, time);
    cout << ans << endl;
    return 0;
}