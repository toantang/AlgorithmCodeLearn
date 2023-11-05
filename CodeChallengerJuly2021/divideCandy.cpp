#include <bits/stdc++.h>

using namespace std;

bool divideCandy(vector<int> bags) {
    int v[5];
    v[1] = 0;
    v[2] = 0;
    int len = bags.size();
    for (int i = 0; i < len; i++) {
        int x = bags[i];
        v[x] = v[x] + 1;
    }
    cout << v[1] << ", " << v[2] << endl;
    if (v[1]%2 == 0) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    vector<int> bags;
    bags = {1, 2, 1, 2};
    //bags = {1, 1, 2, 1, 1, 1, 1, 2, 2, 1};
    cout << divideCandy(bags) << endl;
    return 0;
}