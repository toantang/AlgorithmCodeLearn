#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
};

vector<int> findUoc(int n, int a, int m) {
    int x = sqrt(n);
    int ucln = gcd(a, m);
    vector<int> v = {};
    v.push_back(n);
    for (int i = 2; i <= x; i++) {
        if (n%i == 0) {
            if (i > ucln) {
                v.push_back(i);
            }
            if (n/i > ucln) {
                v.push_back(n/i);
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
    return v;
};

int addGcd(int a, int m)
{
    int ans = 0;
    vector<int> v = findUoc(m, a, m);
    
    int ucln = gcd(a, m);
    //cout << "ucln: " << ucln << endl;
    int limit = m/ucln;
    int previoutValue = a;
    
    for (int i = 1; i <= limit; i++) {
        int value = previoutValue;
        previoutValue = previoutValue + ucln;
        int newUcln = gcd(value, m);
        bool isValid = true;
        cout << "x: " << ucln*i << endl;
        cout << "newUcln: " << newUcln << endl;
        for (int j = 0; j < v.size(); j++) {
            int uoc = v[j];
            if (value%uoc == 0 && uoc > ucln) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            //cout << "x: " << ucln*i << endl;
            //cout << "newUcln: " << newUcln << endl;
            ans++;
        }
    }
    return ans;
};

int main() {
    //int a = 5, m = 10;
    //int a = 4, m = 9;
    //int a = 37, m = 102;
    int a = 78, m = 103;
    //int a = 20, m = 52;
    cout << addGcd(a, m) << endl;
    return 0;

}