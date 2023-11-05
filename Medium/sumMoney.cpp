#include <bits/stdc++.h>

using namespace std;

const int c = 1000000007;
int sumMoney(long long n)
{
   long long x, y, z;
    x = n;
    y = n + 1;
    z = n + 2;
    int val = 0;
    if (x%3 == 0) {
        x = x/3;
        if (y%2 == 0) {
            y = y/2;
            val = ((x%c) * (y%c))%c;
            return ((val%c) * (z%c))%c;
        }
        else {
             
            if (z%2 == 0) {
                z = z/2;
                val = ((x%c) * (y%c))%c;
                return ((val%c) * (z%c))%c;
            }
            else {
                val = (y+0.0)/2 * z;
                return ((val%c) * (x%c))%c;
            }
        }
    }

    else if (y%3 == 0) {
        y = y/3;
        if (x%2 == 0) {
            x = x/2;
            val = ((x%c) * (y%c))%c;
            return ((val%c) * (z%c))%c;
        }
        else {
            if (z%2 == 0) {
                z = z/2;
                val = ((x%c) * (y%c))%c;
                return ((val%c) * (z%c))%c;
            }
            else {
                val = (x+0.0)/2 * y;
                return ((val%c) * (z%c))%c;
            }
        }
    }
    else {
        z = z/3;
        if (x%2 == 0) {
            x = x/2;
            val = ((x%c) * (y%c))%c;
            return ((val%c) * (z%c))%c;
        }
        else {
            if (y%2 == 0) {
                y = y/2;
                val = ((x%c) * (y%c))%c;
                return ((val%c) * (z%c))%c;
            }
            else {
                val = (x+0.0) * y;
                return ((val%c) * (z%c))%c; 
            }
        }
    }
}
int main() {
    long long n = pow(10, 18);
    cout << sumMoney(n);
    return 0;
}