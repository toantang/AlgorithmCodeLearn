#include <bits/stdc++.h>

using namespace std;

int findSpecialNumber(int n)
{
    vector<int>a;
    a.push_back(1);
    int temp=1;
    int count=1;
    while (temp<n)
    {
        for (int i=1;i<=a[temp-1];i++)
        {
            a.push_back(temp);
            count++;
            if (count==n)
                return temp;
        }
        temp++;
    }
    return a[n-1];
}
int main() {
    int n = 5;
    cout << findSpecialNumber(n) << endl;
    return 0;
}