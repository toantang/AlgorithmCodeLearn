#include <bits/stdc++.h>

using namespace std;

int minRemovals(std::vector<int> arr, int k)
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

   if (ans == 0) {
       return 1;
   }
   else {
       return ans;
   }
}

int main() {
    vector<int> arr; int k;
    return 0;
}