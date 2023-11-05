#include <bits/stdc++.h>

using namespace std;

void seeEachOther(vector<vector<int>> a) {
    pair<int, int> huyen(a[0][0], a[0][1]);
    pair<int, int> hai(a[1][0], a[1][1]);
    pair<int, int> A(a[2][0],a[2][1]);
    pair<int, int> B(a[3][0],a[3][1]);

    //int minX = min(huyen.first, hai.first);
    //minX = min(A.first, minX);
    //minX = min(minX, B.first);

    //int maxX = max(huyen.first, hai.first);
    //maxX = max(maxX, A.first);
    //maxX = max(maxX, B.first);

    cout << "huyen: " << "(" << huyen.first << ", " << huyen.second << ")" << endl;
    cout << "hai: " << "(" << hai.first << ", " << hai.second << ")" << endl;
    cout << "A: " << "(" << A.first << ", " << A.second << ")" << endl;
    cout << "B: " << "(" << B.first << ", " << B.second << ")" << endl;

    pair<int, int> nAB(A.second - B.second, B.first - A.first);
    pair<int, int> nHH(huyen.second - hai.second, hai.first - huyen.first);//n cua huyen hai

    vector<int> pt1;
    pt1 = {nAB.first, nAB.second, nAB.first * A.first + nAB.second * A.second};
    vector<int> pt2;
    pt2 = {nHH.first, nHH.second, nHH.first * huyen.first + nHH.second * huyen.second};

    cout << "pt1: ";
    for (int i = 0; i < 3; i++) {
        cout << pt1[i] << " ";
    }
    cout << endl;
    cout << "pt2: ";
    for (int i = 0; i < 3; i++) {
        cout << pt2[i] << " ";
    }
    cout << endl;
    int D = pt1[0] * pt2[1] - pt2[0] * pt1[1];
    float Dx = - (pt1[1] * pt2[2] - pt2[1] * pt1[2]);
    float Dy = pt1[0] * pt2[2] - pt2[0] * pt1[2];
    cout << "D = " << D << ", Dx = " << Dx << ", Dy = " << Dy << endl;

    float x = Dx/D;
    float y = Dy/D;
    cout << "(" << x << ", " << y << ")" << endl;
}
int main() {
    vector<vector<int>> a;
    a = {{5,2},{2,1},{2,3},{6,7}};
    a = {{5,2},{2,6},{2,3},{6,7}};
    a = {{1, 2}, {2, 2}, {2, 1}, {1, 1}};
    a = {{1, 1}, {2, 3}, {3, 3}, {4, 1}};
    a = {{1, 1}, {1, 1}, {1, 1}, {1, 1}};
    seeEachOther(a);
    return 0;
}