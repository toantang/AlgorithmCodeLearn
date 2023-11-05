#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
int ans = -1;

void binarySearch(int value) {
    
    int start = 0;
    int end = n - 1;
    int mid;
    while(end >= start) {
        mid = (start + end)/2;
        cout << "start = " << start << ", end = " << end << ", mid = " << mid << endl;
        if (end == start + 1) {
            if (a[end] == value) {
                ans = end;
            }
            else if (a[start] == value) {
                ans = start;
            }
            break;
        }
        else {
            if (a[mid] > value) {
                end = mid - 1;
            }
            else if (a[mid] < value) {
                start = mid + 1;
            }
            else {
                ans = mid;
                break;
            }
        }
    }
}

void binarySearchNotEqual(int value) {
    int start = 0;
    int end = n - 1;
    int mid;

    while(end >= start) {
        mid = (start + end)/2;
        cout << "start = " << start << ", end = " << end << endl;
        if (start == end) {
            if (a[end] <= value) {
                ans = end;
            }
            break;
        }
        else if (end == start + 1) {
            if(a[end] <= value) {
                ans = end;
            }
            else if (a[start] <= value) {
                ans = start;
            }
            break;
        }
        else {
            if (a[mid] > value) {
                end = mid;
            }
            else {
                if (a[mid + 1] > value) {
                    ans = mid;
                    break;
                }
                else {
                    start = mid;
                }
            }
        }
    }
}
int main() {
    a = {1,7,14,0,9,4,18,18,2,4};
    n = a.size();
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    //binarySearch(15);
    //cout << ans << endl;
    binarySearchNotEqual(6);
    cout << ans << endl;
    return 0;
}