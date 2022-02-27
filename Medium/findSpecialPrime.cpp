#include <bits/stdc++.h> 
#define MAX 10000009

using namespace std;
int isPrime[MAX];
vector<int> prime;

void printArray() {
    int len = prime.size();
    for (int i = 0; i < len; i++) {
        cout << prime[i] << ", ";
    }
    cout << endl;
}

bool checkPrime(int x) {
    if (x%2 == 0 || x%3 == 0 || x%5 == 0 || x%7 == 0) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x%i == 0) {
            return false;
        }
    }
    return true;
}

void findSpecialPrime(int n) {
    int a[] = {1, 2, 3, 5, 7, 9};
    if (n >= 10) {
        prime.push_back(2);
        prime.push_back(3);
        prime.push_back(5);
        prime.push_back(7);
    }
    else {
        for (int i = 1; i <= 4; i++) {
            if (a[i] <= n) prime.push_back(a[i]);
        }
    }
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;
    vector<int> v6;
    vector<int> v7;

    for (int i = 0; i < 6; i++) {
        if (i == 0 || i == 5) continue;
        else {
            for (int j = 0; j < 6; j++) {
                int num = 10*a[i] + a[j];
                if (checkPrime(num) && num <= n) {
                    v2.push_back(num);
                    prime.push_back(num);
                }
            }
        }
    }
    
    if (n >= 100) {
        for (int i = 0; i < v2.size(); i++) {
            for (int j = 0; j < 6; j++) {
                int num = v2[i]*10 + a[j];
                if (checkPrime(num) && num <= n) {
                    prime.push_back(num);
                    v3.push_back(num);
                }
            }
        }
    }
    if (n >= 1000) {
        for (int i = 0; i < v3.size(); i++) {
            for (int j = 0; j < 6; j++) {
                int num = v3[i]*10 + a[j];
                if (checkPrime(num) && num <= n) {
                    prime.push_back(num);
                    v4.push_back(num);
                }
            }
        }
    }

    if (n >= 10000) {
        for (int i = 0; i < v4.size(); i++) {
            for (int j = 0; j < 6; j++) {
                int num = v4[i]*10 + a[j];
                if (checkPrime(num) && num <= n) {
                    prime.push_back(num);
                    v5.push_back(num);
                }
            }
        }
    }

    if (n >= 100000) {
        for (int i = 0; i < v5.size(); i++) {
            for (int j = 0; j < 6; j++) {
                int num = v5[i]*10 + a[j];
                if (checkPrime(num) && num <= n) {
                    prime.push_back(num);
                    v6.push_back(num);
                }
            }
        }
    }

    if (n >= 1000000) {
        for (int i = 0; i < v6.size(); i++) {
            for (int j = 0; j < 6; j++) {
                int num = v6[i]*10 + a[j];
                if (checkPrime(num) && num <= n) {
                    prime.push_back(num);
                    v7.push_back(num);
                }
            }
        }
    }

    if (n >= 10000000) {
        for (int i = 0; i < v7.size(); i++) {
            for (int j = 0; j < 6; j++) {
                int num = v7[i]*10 + a[j];
                if (checkPrime(num) && num <= n) {
                    prime.push_back(num);
                }
            }
        }
    }
} 

int main() {
    findSpecialPrime(1);
    printArray();
    return 0;
}