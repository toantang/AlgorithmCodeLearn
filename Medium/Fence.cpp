#include <bits/stdc++.h>

using namespace std;

int findMax(vector<int> v) {
    int len = v.size();
    int ans = 0;
    int i = 0, j = len - 1;
    while(i < j) {
        int x = v[i];
        int y = v[j];
        if (x < y) {
            ans = max(ans, (j-i)*x);
            i++;
        }
        else if (x > y) {
            ans = max(ans, (j-i)*y);
            j--;
        }
        else {
            ans = max(ans, (j-i)*x);
            i++;
            j--;
        }
    }

    return ans;
}

bool check(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}
void fence(vector<int> a) {
    int len = a.size();
    vector<vector<int>> u;
    vector<pair<int, int>> index;

    int ans = 0;

    while(true) {

        index.clear();
        u.clear();
        if (check(a)) {
            break;
        }
        int size = a.size();
        int start = 0, end = 0;
        for (int i = 0; i < size; i++) {
            if (a[i] == 0) {
                end = i - 1;
                pair<int, int> c;
                c.first = start;
                c.second = end;
                index.push_back(c);
                start = i+1;
            }
        }

        int sizeIndex = index.size();
        for (int i = 0; i < sizeIndex; i++) {
            pair<int, int> c;
            vector<int> k;
            for (int j = c.first; j <= c.second; j++) {
                k.push_back(a[j]);
            }
            if (findMax(k) != 0) {
                ans++;
            }
        }
    }
}
int main() {
    vector<int> a;
    a = {1,8,6,2,5,4,8,3,7};
    a = {5, 4, 3,2 ,3 ,2};
    fence(a);
    return 0;
}