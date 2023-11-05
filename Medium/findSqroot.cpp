#include <bits/stdc++.h>

using namespace std;

void makeTwoStringEqualLength(string &a, string &b) // lam 2 xau co do dai bang nhau
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

int convertStringToNum(char x) {
    return x - '0';
}

char convertNumToString(int num) {
    return num + '0';
}

string sum(string a, string b)  // tong 2 so
{
    string s = "";
    makeTwoStringEqualLength(a,b);      // chuan hoa
    int l = a.length();
     
    int temp = 0;
    for (int i=l-1; i>=0; i--)   // duyet va cong
    {
        temp = convertStringToNum(a[i]) + convertStringToNum(b[i]) + temp;    // tinh tong tung doi mot
        s.insert(0,1,convertNumToString(temp%10));         // gan phan don vi vao
        temp = temp/10;     // lay lai phan hang chuc
    }
    if (temp>0)  // neu hang chuc > 0 thi them vao KQ
    {
        s.insert(0,1,convertNumToString(temp));
    } 
    return s;
}

string multipleWithANum(string a, char x) {
    int num = convertStringToNum(x);
    int sizeA = a.size();
    int sign = 0;

    string s;

    for (int i = sizeA - 1; i >= 0; i--) {
        int ai = convertStringToNum(a[i]);
        int kq = ai * num;
        kq += sign;

        if (kq >= 10) {
           sign = kq/10;
        }
        else {
            sign = 0;
        }

        s = convertNumToString(kq%10) + s;
    }
    if (sign != 0) {
        s = convertNumToString(sign) + s;
    }
    return s;
}

string multipleNum(string a, string b) {
    int sizeA = a.size();
    int sizeB = b.size();

}
string findSqroot(string n) {
    int len = n.size();
    int maxLen = len + 1;
    
}
int main() {
    cout << multipleWithANum("656495", '9') << endl;
    cout << sum("154854", "41854") << endl;
    return 0;
}