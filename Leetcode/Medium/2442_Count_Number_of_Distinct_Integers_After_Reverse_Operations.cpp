#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int reverseNumber(int n) {
    int reversed_number = 0, remainder;
    while(n != 0) {
        remainder = n % 10;
        reversed_number = reversed_number * 10 + remainder;
        n /= 10;
    }
    return reversed_number;
}

int countDistinctIntegers(vector<int>& nums) {
    set<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        int value = reverseNumber(nums[i]);
        ans.insert(value);
        ans.insert(nums[i]);
    }
    return ans.size();
}

int main() {
    vector<int> nums;
    nums = {1,13,10,12,31};
    int ans = countDistinctIntegers(nums);
    cout << ans << endl;
    return 0;
}