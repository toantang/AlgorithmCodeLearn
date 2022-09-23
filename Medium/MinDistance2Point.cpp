#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> X, int n) {
    for (int i = 0; i < n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
}

int findNum(int value, vector<int> B, int n, int i) {
    int start = 0, end = n - 1, mid = 0;
    int ans = INT_MAX;
    while(end >= start) {
        mid = (end + start)/2;
        //cout << "start = " << start << ", end = " << end << ", i = " << i << endl;
        if (end == start) {
            if (B[end] <= value) {
                ans = min(ans, n - (end - i + 1));
            }
            break;
        }
        else if (end == start + 1) {
            if (B[end] <= value) ans = min(ans, n - (end - i + 1));
            else if (B[start] <= value) ans = min(ans, n - (start - i + 1));
            break;
        }
        else {
            if (B[mid] > value) {
                end = mid;
            }
            else {
                if (B[mid + 1] > value) {
                    ans = min(ans, n - (mid - i + 1));
                    break;
                }
                else {
                    start = mid;
                }
            }
        }
    }
    return mid;
}
int minDistance2Point(vector<int> a) {
    int n = a[0];
    vector<int> A, B;
    for (int i = 1; i <= n; i++) {
        A.push_back(a[i]);
        B.push_back(a[i+n]);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (B.size() == 1) {
        if (A.size() == 1) {
            return abs(A[0] - B[0]);
        }
        else {
            int val = INT_MAX;
            for (int i = 0; i < n; i++) {
                val = min(val, abs(A[i] - B[0]));
            } 
            return val;
        }
    }
    
    //cout << "mang A: ";
    printArray(A, n);
    //cout << "mang B: ";
    printArray(B, n);
    int ans = INT_MAX;

    if (A[n-1] < B[0]) {
        return B[0] - A[n-1];
    }
    for (int i = 0; i < n; i++) {
        //int i = 0;
        int value = A[i];
        if (value > B[n-1]) {
            ans = min(ans, value - B[n-1]);
            break;
        }
        cout << "i: " << i << endl;
        int num = findNum(value, B, n, i);
        cout << "   num = " << num << endl;
        if (value >= B[num] && value <= B[num+1]) {
             cout << "   " << A[i] << ", " << B[num] << ", " << B[num+1] << endl;
            int x1 = value - B[num];
            int x2 = B[num+1] - value;
            x1 = min(x1, x2);
            ans = min(x1, ans);
        }
        
    }
    return ans;
}
int main() {
    vector<int> a;
    a = {100,
    920373,365682,732404,582604,157397,23689,738384,824986,438317,652481,506635,235671,206874,963335,652577,50705,583417,842056,114191,393236,707686,225521,312211,
    101358,476735,712303,757673,521196,438177,165296,199374,228250,585961,61151,45248,311814,408308,346794,551291,281596,740383,602751,529404,799562,771334,210122,
    858945,541181,535239,331959,231046,885537,198975,979573,417224,939076,265739,4464,772229,724786,865800,445973,672057,954553,331218,351953,335841,695973,768648,
    58513,422459,942788,289157,435778,999107,388003,161191,124369,441718,439566,357259,10668,113490,803347,936205,371390,626067,343422,134732,602998,892150,117341,
    477219,751743,978169,368892,902064,234248,144664,803113,1143,578655,102304,869651,690393,635927,266529,758069,90282,774696,391450,226850,920589,416455,581969,
    330416,194344,935530,105546,220788,538592,993476,26442,705539,436762,397772,542423,753201,617211,144886,851573,165524,609256,898807,606954,604033,336262,31621,
    702395,634700,113402,630100,574827,18379,583209,233176,842497,68819,450616,524616,733954,67129,276747,891929,892338,3281,509577,194814,262423,952305,731734,
    41518,853749,349038,258262,767837,394641,448988,242736,601152,282353,598929,475719,572236,811417,226914,424450,183223,320271,525987,84676,885812,63704,814186,
    423604,783546,302647,665292,697653,81469,661171,733406,332973,237234,393105,395764,617729,703375,932821,136484};
    //a = {1, 2, 3};
   // a = {4,15,15,6,4,12,11,15,2};
    cout << MinDistance2Point(a);
    return 0;
} 