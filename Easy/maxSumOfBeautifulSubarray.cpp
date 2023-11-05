#include <bits/stdc++.h>

using namespace std;

long long maxSumOfBeautifulSubarray(std::vector<int> arr)
{
    int lenArray = arr.size();
    for (int i = 0; i < lenArray; i++) {
        int x = arr.at(i);
        arr.push_back(x);
    }

    int sum = 0;
    int best = INT_MIN;
    for (int i = 0; i < lenArray; i++) {
        sum = arr[i];
        //cout << "sum: " << sum << endl;
        for (int j = i + 1; j < lenArray + i; j++) {
            sum = max(arr[j], arr[j] + sum);
            //cout << "sum = " << sum << endl;
            if (sum%9 == 0) {
            best = max(best, sum);
            }
        }  
    }

    
    return best;
}

int main() {
    vector<int> arr;
    arr = {-3,5,-4,7};
    //arr = {1,2,3,4,5,6,7,8,9};
    //arr = {4,-5,-8,10};
    arr = {6,12,6,14,6};
    cout << maxSumOfBeautifulSubarray(arr) << endl;
    return 0;
}