//done

#include <iostream>
#include <ostream>

using namespace std;

vector<int> buildArray(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans;
    for (int i = 0; i < len; i++) {
        ans.push_back(nums[nums[i]]);
    }
    return ans;
}

int main() {
    return 0;
}