#include <bits/stdc++.h>

using namespace std;

string f = "";
vector<int> ans;

int convertStringToNum(char x) {
    return x - '0';
}

bool checkPrime(int value) {
    
    if (value == 2 || value == 3 || value == 5 || value == 7 || value == 1) {
        return true;
    }
    if (value%2 == 0 || value%3 == 0 || value%5 == 0 || value%7 == 0) {
        return false;
    }

    int val = sqrt(value);
    for (int i = 2; i <= val; i++) {
        if (value%i == 0) {
            return false;
        }
    }
    return true;
}
void TRY(int k, int n, int len, string x) {
    for (int i = 0; i < len; i++) {
        //cout << "i: " << i << ", x[" << i << "] = " << x[i] << endl;
        f += x[i];
        //cout << "   f = " << f << endl;
        k++;
        int value = atoi(f.c_str());
        if (k == n) {
            if (checkPrime(value)) {
                int size = ans.size();
                if (size == 0) {
                    ans.push_back(value);
                }
                else {
                    if (ans[size-1] != value) {
                        ans.push_back(value);
                    }
                }
            }
        }
        else {
            TRY(k, n, len, x);
        }
        f.erase(f.size() - 1, 1);
        k--;
    }
}
std::vector<int> countPrime(std::vector<string> s)
{
    vector<int> v;
    int size = s.size();
    if (size == 0) {
        return v;
    }
    
    
    for (int i = 0; i < size; i++) {
        string a = s[i];
        int len = a.size();

        ans.clear();

        for (int j = 1; j <= len; j++) {
            //cout << "j: " << j << endl;
            TRY(0, j, len, a);
        }

        int countAns = 0;
        int sizeAns = ans.size();
        sort(ans.begin(), ans.end());
        cout << "mang ans: "  << endl;
        for (int i = 0; i < sizeAns; i++) {
            cout << ans[i] << endl;
        }
        
        if (sizeAns != 0) {
            countAns++;
        }
        for (int i = 1; i < sizeAns; i++) {
            if (ans[i] != ans[i-1]) {
                cout << "(" << ans[i] << ", " << ans[i-1] << ")" << endl;
                countAns++;
                //v.push_back(ans[i]);
            }
        }

        v.push_back(countAns);
    }

    return v;
}


int main() {
    vector<string> s;
    s = {"32","373"};
    /*
    TRY(0, 1, 2, s[0]);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }*/
    vector<int> v = countPrime(s);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    return 0;
}