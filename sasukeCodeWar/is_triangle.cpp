#include <bits/stdc++.h>

using namespace std;

bool isTriangle(vector<vector<int>> points) {
    pair<int, int> ab;
    pair<int, int> ac;
    int xa = points[0][0];
    int ya = points[0][1];
    ab.first = points[1][0] - xa;
    ab.second = points[1][1] - ya;
    ac.first = points[2][0] - xa;
    ac.second = points[2][1] - ya;
    if(ab.first * ac.second == ab.second * ac.first) {
        return false;
    }
    else {
        return true;
    }
}
int main() {
    return 0;
}