#include <bits/stdc++.h>

using namespace std;

int currentMin = INT_MAX;

vector<vector<int>> ans;

void solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();

    for (int i = len-1; i > 0; i--) {
        int distance = arr[i] - arr[i-1];
        vector<int> sol;
        if (distance == currentMin) {         
            sol.push_back(arr[i-1]);
            sol.push_back(arr[i]);
            ans.push_back(sol);
        }
        else if (distance < currentMin) {
            currentMin = distance;
            sol.push_back(arr[i-1]);
            sol.push_back(arr[i]);
            ans.clear();
            ans.push_back(sol);
        }
    }
}

void minimumAbsolute(vector<int> arr) {

}

int main() {
    vector<int> arr;
    //arr = {4,2,1,3};
    //arr = {1,10,0,5,7,2,4,9,8,6};
    //arr = {9,11,0,18,14,4,1,12,10,5,8,13,20,16,3};
    /*arr = {90,195,101,35,29,134,75,16,24,140,11,120,191,69,149,132,22,57,77,126,59,199,157,44,113,74,147,32,
            47,152,194,33,82,53,170,15,139,61,106,64,98,50,31,188,97,169,8,81,93,2};*/
    arr = {40,109,136,78,189,86,97,151,51,191,0,95,122,21,101,142,116,49,52,67,130,44,45,18,28,73,187,82,171,
            68,10,33,106,172,182,29,190,100,159,14,20,42,126,132,193,164,74,16,61,84,181,162,87,154,54,98,72,108,99,
            60,170,64,134,173,115,147,186,92,139,41,91,169,200,79,107,155,62,194,165,148,17,23,71,128,30,195,111,180,
            90,188,105,110,93,24,168,63,143,178,103,158,133,102,57,34,77,119,75,11,81,66,15,114,167,48,179,80,56,26,
            199,6,124,153,55,120,1,141,12,39,146,22,46,160,104,149,144,174,32,140,152,129,156,65,13,43,7,3,69,175,177,
            138};
    solution(arr);
    int len = ans.size();
    reverse(arr.end(), arr.begin());
    for (int i = 0; i < len; i++) {
        vector<int> x = ans[i];
        cout << "[" << x[0] << ", " << x[1] << "]" << endl;
    }
    
    return 0;

}