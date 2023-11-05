#include <bits/stdc++.h>

using namespace std;


bool checkNumber(string a, string b) {
    int lenA = a.size();
    int lenB = b.size();
    if (lenA > lenB) {
        return true;
    }
    else if (lenA < lenB) {
        return false;
    }
    else {
        for (int i = 0; i < lenA; i++) {
            int xa = a[i] - '0';
            int xb = b[i] - '0';
            if (xa > xb) {
                return true;
            }
            else if (xa < xb) {
                return false;
            }
            else {
                continue;
            }
        }
    }
    return true;
}

int stringToNum(char c)     // chuyen char sang so
{
    return c - '0';
}
 
char numToString(int n)     // chuyen so sang char
{
    return (char)(n+48);
}
 
void convertLengthOfNum(string &a, string &b) // lam 2 xau co do dai bang nhau
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');    // chen vao dau cua b cac ky tu '0'
    }
    else
    {
        a.insert(0, l2-l1, '0');    // chen vao dau cua a cac ky tu '0'
    }
}

string deleteZeroFirst(string s) {
    int len = s.size();
    int k = 0;
    while(s[k] == '0') {
        k++;
    }
    if (k == len) {
        return "0";
    }
    string ans = "";
    for (int i = k; i < len; i++) {
        ans += s[i];
    }
    return ans;
}
string subNumber(string a, string b) {
    string s = "";
    convertLengthOfNum(a, b);
    int l = a.size();
    int lendNum = 0;

    for (int i = l - 1; i >= 0; i--) {
        //cout << "i: " << i << endl;
        int xa = stringToNum(a[i]);
        int xb = stringToNum(b[i]);
        string num = "";
        if (xa >= xb + lendNum) {
            num = numToString(xa - xb - lendNum);
            lendNum = 0;
        }
        else {
            xa += 10;
            num = numToString(xa - xb - lendNum);
            lendNum = 1;
        }
        s = num + s;
        //cout << "   num = " << num << endl;
    }
    
    string ans = deleteZeroFirst(s);
    return ans;
}

string caculateSubNum(string a, string b) {
    if (checkNumber(a, b)) {
        return subNumber(a, b);
    }
    else {
        return subNumber(b, a);
    }
}

bool checkAns(vector<string> a) {
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
        return true;
    }
    return false;
}
void printArray(vector<string> a) {
    for (int i = 0; i < 4; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void arrayZero(vector<string> a) {
    int ans = 0;
    if (checkAns(a)) {
        if (deleteZeroFirst(a[0]) == deleteZeroFirst(a[1]) && 
            deleteZeroFirst(a[1]) == deleteZeroFirst(a[2]) && 
            deleteZeroFirst(a[2]) == deleteZeroFirst(a[3]))
            {
                ans = 0;
            }
    }
    while(checkAns(a) == false) {
        string a0, a1, a2, a3;
        a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
        a[0] = caculateSubNum(a0, a1);
        a[1] = caculateSubNum(a1, a2);
        a[2] = caculateSubNum(a2, a3);
        a[3] = caculateSubNum(a3, a0);
        printArray(a);
        ans++;
    }
    ans++;
    cout << ans << endl;
}
int main() {
    vector<string> a;
    a = {"27","12","2000","1234"};
    //cout << caculateSubNum("27", "1234");
    arrayZero(a);
    return 0;
}