#include <bits/stdc++.h>

using namespace std;

//1^3 + 2^3 + 3^3 + ... + (2n)^3 = ((2n*(2n+1)/2))^2
//2^3 + 4^3 + ... + (2n)^3 = 2^3 * (n(n+1)/2)^2
long long sumOfCubesOddNumber(int n) {
    return n*n*(n*n + n*n - 1);
}

int main() {

}