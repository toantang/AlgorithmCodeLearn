
#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int findMax(vector<int> a) {
    int len = a.size();
    sort(a.begin(), a.end());
    if (len == 0) {
        return 0;
    }
    else if (len == 1) {
        return a[len-1];
    }
    else if (a[0] < 0) {
        return a[0]/a[len-1];
    }
    else {
        return a[len-1]/a[0];
    }
}

void maxDiv(vector<int> a) {
    vector<int> positive;
    int n1;
    vector<int> negative;
    int n2;
    vector<int> zero;
    int n3;
    
    int len = a.size();
    for (int i = 0; i < len; i++) {
        if (a[i] > 0) {
            positive.push_back(a[i]);
            n1++;
        }
        else if (a[i] < 0) {
            negative.push_back(a[i]);
            n2++;
        }
        else {
            zero.push_back(0);
            n3++;
        }
    }

    if (n1 == 0) {
        if (n2 <= 1) {
            ans = 0;
        }
        else {
            ans = findMax(negative);
        }
    }
    else if (n1 == 1) {
        if (n3 == 0) {
            if (n2 == 1) {
                
            }
            else {
                
            }
        }
    }
    else {

    }
}
int main() {
    vector<int> a;
    //a = {4,8,3,1}; //true
    a = {6,9,6,7}; //true
    //a = {7,6,10,5}; //true
    //a = {8,2,7,5,5}; //true
    //a = {-2,-1,5,7,-3}; //true
    //a = {-3,-1,-2,2,1,-7}; //true
    //a = {-2,-2,-3,-8,-1,-1,-3}; //true
    //a = {-4,2,8,5,-5,5,-17,-10,-11,6}; //true
    //a = {19,-21,-18,-22,-1,6,-3,5,-1,-25,15,10,13,20,-7,6,-17,-8,19,23};
    maxDiv(a);
    cout << ans << endl;
    return 0;
}