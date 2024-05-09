#include <iostream>

using namespace std;

void groupThePeople(vector<int>& groupSizes) {
    int n = groupSizes.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back({});
    }
    for (int i = 0; i < n; i++) {
        int size = groupSizes[i];
        ans[size].push_back(i);
        // ans[i].push_back(groupSizes[i]);
    }
    for (int i= 0; i < n; i++) {
        vector<int> ansi = ans[i];
        cout << i << ": ";
        for (int j = 0; j < ansi.size(); j++) {
            cout << ansi[j] << ", ";
        }
        cout << endl;
    }
}

int main() {
    cout << "hello world" << endl;
    vector<int> groupSizes;
    groupSizes = {2,1,3,3,3,2};
    groupThePeople(groupSizes);
    return 0;
}
