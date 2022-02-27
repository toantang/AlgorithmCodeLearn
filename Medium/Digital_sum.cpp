#include <bits/stdc++.h>

using namespace std;

int ans;
void digitalSum(int number) {
    if (number < 10) {
        ans = number;
    }
    while (true) {
        if (number < 10) {
            ans = ans + number;
            if (ans >= 10) {
                number = ans;
                ans = 0;
            }
            else {
                break;
            }
        }
        else {
            ans = ans + number%10;
            number = number/10;
        }
    }
}
int main() {
    int number = 123432;
    digitalSum(number);
    cout << ans << endl;
    return 0;
}