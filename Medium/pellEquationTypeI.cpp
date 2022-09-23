#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> findMinSolution(int d, int n) {

    pair<long long, long long> v;
    long long x = 2;
    while(true) {
        long long caculate = x * x - 1;
        if (caculate%d == 0) {
            long long val = caculate/d;
            long long value = sqrt(val);
            if (value * value == val) {
                v.first = x;
                v.second = value;
                break;
                //return v;
            }
        }

        x++;
    }
    return v;
}


vector<long long> pellEquationTypeI(int d, int n) {
    pair<long long, long long> minSol = findMinSolution(d, n);
    long long x1 = minSol.first;
    long long y1  = minSol.second;

    vector<long long> ans;

    vector<long long> solX;
    vector<long long> solY;
    solX.push_back(x1);
    solY.push_back(y1);
    for (int i = 1; i < n; i++) {
        long long xi = x1 * solX[i-1] + d * y1 * solY[i-1];
        long long yi = x1 * solY[i-1] + y1 * solX[i-1];
        solX.push_back(xi);
        solY.push_back(yi);
    }

    ans.push_back(solX[n-1]);
    ans.push_back(solY[n-1]);
    return ans;
}
int main() {
    int d, n;
    d = 2, n = 2;

    //cout << d << endl;
    pair<long long, long long> v = findMinSolution(d, n);
    cout << v.first << ", " << v.second << endl;
    vector<long long> ans = pellEquationTypeI(d, n);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}