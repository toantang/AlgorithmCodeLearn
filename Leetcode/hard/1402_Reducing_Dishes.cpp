#include <bits/stdc++.h>

using namespace std;

int calculateSum(stack<int> S) {
    int i = 1;
    int sum = 0;
    while(!S.empty()) {
        sum += S.top() * i;
        S.pop();
        i++;
    }
    cout << "currentSum: " << sum << endl;
    return sum;
}

int maxSatisfaction(vector<int>& satisfaction) {
     sort(satisfaction.begin(), satisfaction.end());
     for (int i = 0; i < satisfaction.size(); i++) {
        cout << satisfaction[i] << ", ";
     }
     cout << endl;
     stack<int> S;
    int sum = -99;
     for (int i = satisfaction.size() - 1; i >= 0; i--) {
        S.push(satisfaction[i]);
        int newSum = calculateSum(S);
        if (newSum < sum) break;
        else sum = newSum;
     }
     return sum;
};

int main() {
    vector<int> satisfaction;
    satisfaction = {-1,-8,0,5,-9};
    cout << maxSatisfaction(satisfaction) << endl;
    return 0;
}