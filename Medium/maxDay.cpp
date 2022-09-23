
// vẫn chưa làm được
#include <bits/stdc++.h>
#define MAX 2000005
using namespace std;

int maxValue;
int a[MAX];
vector<int> v;
int ans;

void printArray(vector<int> a, int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void countTypeCake(int n, int m, vector<int> arr) {
    for (int i = 0; i < m; i++) {
        int value = arr[i];
        a[value]++;
        if (value > maxValue) {
            maxValue = value;
        }
    }
    
    for (int i = 0; i <= maxValue; i++) {
        int x = a[i];
        if (x > 0) {
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());
    int length = v.size();

    printArray(v, length);
}

bool check(int n, int start, int end, int mid) {
    int cnt;
    for (int i = start; i <= end; i++) {
        cnt = cnt + v[i]/mid;
        if (cnt >= n) {
            return true;
        }
    }
    
    return false;
}
void maxDay(int n, int m, vector<int> arr) {
    int length = v.size();
    int start = 0, end = length - 1;
    int mid;
    cout << mid << endl;
    while(start != end) {
        cout << "start = " << start << ", mid = " << mid << ", end = " << end << endl;
        mid = (start + end)/2;
        if (check(n, start, end, mid)) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    cout << start << endl;
}

int main() {
    int n, m;
    vector<int> arr;
    n = 4, m = 100;
    arr = {84,99,66,69,86,94,89,96,98,93,93,82,87,93,91,100,69,99,93,81,99,84,75,
            100,86,88,98,100,84,96,44,70,94,91,85,78,86,79,45,88,91,78,98,94,81,
            87,93,72,96,88,96,97,96,62,86,72,94,84,80,98,88,90,93,73,73,98,78,50,
            91,96,97,82,85,90,87,41,97,82,97,77,100,100,92,83,98,81,70,81,74,78,84,
            79,98,98,55,99,97,99,79,98}; //true
    //n = 4, m = 10; arr = {1,5,2,1,1,1,2,5,7,2}; //true
    /*n = 4, m = 19;
    arr = {1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6};*/
    //n = 2, m = 5; arr = {5,4,3,2,1}; //true
    /*n = 6, m = 100, arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
            3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};*/
    //n = 3, m = 9, arr = {42,42,42,42,42,42,42,42,42};
    //n = 4, m = 8, arr = {};
    //n = 5, m = 2, arr = {4, 7};
    countTypeCake(n, m, arr);
    maxDay(n, m, arr);
    /*printArray(arr, size);
    cout << cntPerson << endl;*/
    return 0;
}