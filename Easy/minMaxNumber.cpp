#include <bits/stdc++.h>

using namespace std;

int minMax(int n)
{   
    int i,k=0,h=0,s[10];
    string a=to_string(n);
    for(i=0;i<a.size();i++)
    {
        s[i+1]=a[i]-'0';
    }
    sort(s+1,s+a.size()+1);
    for(i=1;i<=a.size();i++)
    {
        h=h*10+s[i];
    }
    for(i=a.size();i>=1;i--)
    {
        k=k*10+s[i];
    }
    return k-h;
}

int main() {
    return 0;
}