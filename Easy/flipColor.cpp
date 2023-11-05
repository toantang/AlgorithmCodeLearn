#include <bits/stdc++.h>

using namespace std;

void solution(vector<int> color, vector<int> t) {
    sort(t.begin(), t.end());
    int len = t.size();
    int size = color.size();
    
    int x[size];
    for (int i = 0; i < size; i++) {
        x[i] = 0;
    }
    
    //số lần xuất hiện các phần tử trong vector t
    for (int i = 0; i < len; i++) {
        x[t[i]] = i + 1;
    }
    for (int i = 0; i < size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < size; i++) {
        if (x[i] == 0) {
            x[i] = x[i-1];
        }
    }

    for (int i = 0; i < size; i++) {
        if (x[i]%2 == 1) {
            if (color[i] == 1) {
                color[i] = 0;
            }
            else {
                color[i] = 1;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << color[i] << " ";
    }
}

int main() {
    vector<int> v;
    vector<int> t;   
    //v = {1,0,0,1}, t = {0,1,2,3};
    //v = {1,1,1,1,1}, t = {4,3,0};
    //v = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, t = {0, 3, 8, 5, 4}; //[1, 0, 0, 1, 1, 0, 0, 0, 1, 1]
    //v = {0, 0, 0}, t = {1, 2, 0, 0, 0};
   // v = {0, 1, 1, 1, 0,}, t = {0, 2, 0, 0, 0, 2};
   v = {1}; t = {4, 5, 2, 8, 0};
    solution(v, t);
    
    return 0;
}