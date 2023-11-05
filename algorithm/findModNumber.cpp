#include <bits/stdc++.h>

using namespace std;

//find n^k mod p
unsigned long long findMod(int n, int k, int p) {
    unsigned long long ret = 1;
    n %= p;
    k %= p - 1;
    while(k > 0) {
        if (k%2 > 0) {
            ret = ret * n%p;
        }
        n = n * n%p;
        k = k/2;
    }
    return ret;
}

//find a/b mod p
unsigned long long findDivisionMod(int a, int b, int p) {
    return ((a%p) * (findMod(b, p - 2, p)))%p;
}