#include <bits/stdc++.h>

using namespace std;

std::vector<int> takeMaxGold(std::vector<int> a)
{
    int len = a.size();
    vector<int> ans;
    if (len == 0) {
        return ans;
    }

    int best = 0;
    int currentMax = 0;
    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        currentMax += a[i];
        //cout << "currentMax = " << currentMax << ", best = " << best << endl;
        if (best < currentMax) {
            best = currentMax;
            end = i;
        }
        if (currentMax < 0) {
            currentMax = 0;
        }
    }

    if (best == 0) {
        ans.push_back(-1);
        return ans;
    }
    //cout << best << endl;
    for (int j = end; j >= 0; j--) {
        best -= a[j];
        if (best == 0) {
            start = j;
            break;
        }
    }
    ans.push_back(start);
    ans.push_back(end);
    //cout << "start = " << start << ", end = " << end << endl;
    return ans;
}
int main() {
    vector<int> a;
    a = {4,-5,2,3,-4,5,6,-8};
    a = {-1, -5, -2, -8, -9, -7};
    //a = {-12,8,-1,2,451,234,10,-9999,111,9};
    a = {100,200,300,-500,400,900};
    vector<int> ans = takeMaxGold(a);
    for (int i = 0; i < ans.size(); i++) {
        cout << a[i] << " ";
    }
    return 0;
}