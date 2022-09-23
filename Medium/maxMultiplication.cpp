#include <bits/stdc++.h>

using namespace std;

int maxMultiplication(std::vector<int> a)
{
    int len = a.size();
    if (len < 2) {
        return 0;
    }
    int ans = 0;
    vector<int> positive; // mang chua so duong
    vector<int> negative; //mang chua so am 
    for (int i = 0; i < len; i++) {
        if (a[i] < 0) {
            negative.push_back(a[i]);
        }
        else if (a[i] > 0) {
            positive.push_back(a[i]);
        }
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    int lenPositive = positive.size();
    int lenNegative = negative.size();
    if (lenPositive == 0) {
        if (lenNegative == 0) {
            ans = 0;
        }
        else {
            ans = negative[0] * negative[1];
        }
    }
    else if (lenPositive == 1) {
        if (lenNegative == 0) {
            ans = 0;
        }
        else if (lenNegative == 1) {
            ans = positive[0];
        }
        else {
            ans = max(positive[0], negative[0] * negative[1]);
        }
    }
    else {
        if (lenNegative <= 1) {
            ans = positive[lenPositive - 1] * positive[lenPositive - 2];
        }
        else {
            ans = max(positive[lenPositive - 1] * positive[lenPositive - 2], negative[0] * negative[1]);
        }
    }

    if (ans <= 0) {
        return 0;
    }
    else {
        return ans;
    }
}

int main() {
    vector<int> a;
    a = {-2, 5, 0};
    cout << maxMultiplication(a);
    return 0;
}