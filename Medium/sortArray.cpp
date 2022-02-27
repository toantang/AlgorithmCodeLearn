#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

bool comp(const int a, const int b){
   return a > b;
}

void sortArray(vector<int> a) {
    int len = a.size();
    int negative[len+1];
    int positive[len+1];
    int n1 = 0, n2 = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] > 0) {
            positive[n1] = a[i];
            n1++;
        }
        else if (a[i] < 0) {
            negative[n2] = a[i];
            n2++;
        }
    }
    sort(positive, positive + n1);
    sort(negative, negative + n2, comp);

    
    int i = 0, j = 0, k = 0;
    while(k < len) {
        if (a[k] > 0) {
            ans.push_back(positive[i]);
            i++;
        }
        else if (a[k] < 0) {
            ans.push_back(negative[j]);
            j++;
        }
        else {
            ans.push_back(0);
        }
        k++;
    }
}

int main() {
    vector<int> a;
    a = {3,-1,2,0,-4,6};
    sortArray(a);
    int len = a.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}