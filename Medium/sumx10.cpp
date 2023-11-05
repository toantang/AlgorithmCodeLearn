//da xong
#include <bits/stdc++.h>

using namespace std;

string makeNum(int K) {
    string s = "";
    for (int i = 0; i <= K; i++) {
        s += '1';
    }
    return s;
}

void makeNumEqualLength(string &a, string &b) {
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2) {
        b.insert(0, l1-l2, '0');
    }
    else {
        a.insert(0, l2-l1, '0');
    }
}

int stringToNum(char c) {
    return c - '0';
}
 
char numToString(int n) {
    return (char)(n+48);
}

string sumTwoNum(string a, string b) {
    makeNumEqualLength(a, b);
    string s = "";
    int l = a.length();
     
    int temp = 0;
    for (int i = l-1; i >= 0; i--){
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;
        s.insert(0,1,numToString(temp%10));
        temp = temp/10;
    }
    if (temp>0) {
        s.insert(0,1,numToString(temp));
    } 
    return s;
}

void sumx10(int N, int K) {
    string a[105];
    string s = to_string(N);
    a[0] = s.insert(0, K, '0');
    cout << a[0] << endl;
    for (int i = 1; i <= K; i++) {
        a[i] = a[i-1] + '0';
        a[i] = a[i].erase(0, 1);
        cout << a[i] << endl;
    }

    string ans = "000000";
    for (int i = 0; i <= K; i++) {
        ans = sumTwoNum(ans, a[i]);
    }
    cout << "ans = " << ans << endl;
    if (N == 0) {
        ans = "0";
    }
}
int main() {
    int N, K;
    N = 123, K = 3;
    sumx10(N, K);

    return 0;

}