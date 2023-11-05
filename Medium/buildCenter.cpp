#include "bits/stdc++.h"

using namespace std;

struct Company {
    int l;
    int r;
    int c;
    int p;
    
    void toString() {
        cout << "Company{l: " << l << ", r: " << r << ", c: " << c << ", p: " << p  << "}, ";
    };
};

struct less_than_p {
    inline bool operator() (Company com1, Company com2) {
        return com1.p <= com2.p;
    }
};

vector<vector<Company>> work = {};

void makeWork(std::vector<std::vector<int>> hire) {
    for (int i = 1; i <= 1000000; i++) {
        vector<Company> v = {};
        work.push_back(v);
    }
    for (int i = 0; i < hire.size(); i++) {
        Company com;
        com.l = hire[i][0];
        com.r = hire[i][1];
        com.c = hire[i][2];
        com.p = hire[i][3];
        for (int k = com.l; k <= com.r; k++) {
            work[k].push_back(com);
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        vector<Company> coms = work[i];
        sort(coms.begin(), coms.end(), less_than_p());
        work[i] = coms;
    }

    for (int i = 1; i <= 1000000; i++) {
        vector<Company> v = work[i];
        if (v.size() > 0) {  
            cout << "day " << i << ": {";      
            for (int k = 0; k < v.size(); k++) {
                v[k].toString();
            }
            cout << "}" << endl;
        }
        
    }
}
long long findMin(int day, int k) {
    vector<Company> v = work[day];
    long long minCurrentDay = 0;
    for (int i = 0; i < v.size(); i++) {
        Company com = v[i];
        if (k == 0) break;
        //cout << "k: " << k << "com.c: " << com.c << endl; 
        if (k < com.c) {
            minCurrentDay += k * com.p;
            k = 0;
        }
        else {
            minCurrentDay += com.c * com.p;
            k = k - com.c;
        }
        
    }
    cout << "min day " << day << ": " << minCurrentDay << endl;;
    return minCurrentDay;
};

long long building(std::vector<std::vector<int>> hire, int n, int k)
{
    makeWork(hire);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += findMin(i, k);
        //ans = ans + min_ngay_thu_i;
    }
    return ans;
};

int main() {
    vector<vector<int>> hire = {};
    // vector<vector<int>> hire = {{2,5,3,1},{1,4,5,3},{1,1,5,1},{3,4,5,6}}; ok
    // int n = 5; 
    // int k = 5;
    
    // hire = {{3,3,1,10},{7,9,8,11},{7,8,5,25},{2,7,7,29},{2,5,8,37},{2,3,6,45},{2,4,7,56},{8,8,10,63},{9,10,10,68},{5,10,1,80}}; ok
    // int n = 10, k = 20;

    // hire = {{7,8,2,2},{7,8,1,4},{7,8,4,28},{1,5,1,52},{5,5,2,53},{2,9,1,67},{6,10,1,80},{5,8,5,80},{8,10,5,92},{6,7,9,99}}; ok
    // int n = 10, k = 20;

    hire = {{6,9,3,20},{10,10,7,25},{4,7,4,28},{6,6,8,59},{3,8,4,62},{5,9,9,64},{4,10,9,80},{3,3,1,92},{7,7,2,95},{7,7,8,100}};
    int n = 10, k = 20;
    cout << building(hire, n, k) << endl;
    return 0;
}