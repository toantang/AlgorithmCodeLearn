#include <bits/stdc++.h>

using namespace std;

int minRemovals(vector<int> arr, int k)
{
    int ans = INT_MAX;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n == 0 || n == 1) {
        return 1;
    }
    int start;
    int mid;
    int end;
    for (int i = 0; i < n; i++) {
        start = i;       
        end = n - 1;
        int value = arr[i] + k;
        while(end >= start) {
            mid = (end + start)/2;
            //cout << "start = " << start << ", end = " << end << ", i = " << i << endl;
            if (end == start) {
                if (arr[end] <= value) {
                    ans = min(ans, n - (end - i + 1));
                }
                break;
            }
            else if (end == start + 1) {
                if (arr[end] <= value) ans = min(ans, n - (end - i + 1));
                else if (arr[start] <= value) ans = min(ans, n - (start - i + 1));
                break;
            }
            else {
                if (arr[mid] > value) {
                   end = mid;
                }
                else {
                    if (arr[mid + 1] > value) {
                        ans = min(ans, n - (mid - i + 1));
                        break;
                    }
                    else {
                        start = mid;
                    }
                }
            }
        }
    }

   if (ans == INT_MAX) {
       return 1;
   }
   else {
       return ans;
   }
}


int main() {
    vector<int> arr;
    int k;
    //arr = {1, 5, 6, 2, 8}; k = 2;
    //arr = {1,7,14,0,9}; k = 3;
    //arr = {1,7,14,0,9,4,18,18,2,4}; k = 4;
    
    /*arr = {41,67,34,0,69,24,78,58,62,64,5,45,81,27,61,91,95,42,27,36,91,4,2,53,92,
        82,21,16,18,95,47,26,71,38,69,12,67,99,35,94,3,11,22,33,73,64,41,11,53,68}; k = 10;*/
    arr = {41,67,34,0,69,24,78,58,62,64,5,45,81,27,61,91,95,42,27,36,91,4,2,53,92,
        82,21,16,18,95,47,26,71,38,69,12,67,99,35,94,3,11,22,33,73,64,41,11,53,68,
        47,44,62,57,37,59,23,41,29,78,16,35,90,42,88,6,40,42,64,48,46,5,90,29,70,
        50,6,1,93,48,29,23,84,54,56,40,66,76,31,8,44,39,26,23,37,38,18,82,29,41}; k = 40;
    //cout << minRemovals(arr, k);
    cout << minRemovals(arr, k) << endl;
    return 0;
}