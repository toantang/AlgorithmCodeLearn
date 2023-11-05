#include <bits/stdc++.h>

using namespace std;

int multiplitedVector(pair<int, int> a, pair<int, int> b) {
    return a.first*b.first + a.second*b.second;
}

void findPoint(int x, int y, int x1, int y1, int x2, int y2) {
    float xd, yd;
    
    vector<int> pt1;
    vector<int> pt2;
    pt1.push_back(x);
    pt1.push_back(y);
    pt1.push_back(x*x1 + y*y1);
    pt2.push_back(y);
    pt2.push_back(-x);
    pt2.push_back(y*x2 - x*y2);

    for (int i = 0; i < 3; i++) {
        cout << pt1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << pt2[i] << " ";
    }
    cout << endl;
    int D = pt1[0]*pt2[1] - pt1[1]*pt2[0];
    int Dx = pt1[2]*pt2[1] - pt1[1]*pt2[2];
    int Dy = pt1[0]*pt2[2] - pt1[2]*pt2[0];
    cout << D << ", " << Dx << ", " << Dy << endl;
    xd =  Dx/D;
    yd = Dy/D;
    cout << xd << ", " << yd << endl;
}

void createRectangle(vector<vector<int>> points) {
    int xa = points[0][0], ya = points[0][1];
    int xb = points[1][0], yb = points[1][1];
    int xc = points[2][0], yc = points[2][1];

    pair<int, int> ab (xb - xa, yb - ya);
    pair<int, int> bc (xc - xb, yc - yb);
    pair<int, int> ac (xc - xa, yc - ya);
    cout << "C = " << xc << ", " << yc << endl;
    cout << "(" << ab.first << ", " << ab.second << ")" << endl;
    cout << "(" << bc.first << ", " << bc.second << ")" << endl;
    cout << "(" << ac.first << ", " << ac.second << ")" << endl;

    cout << multiplitedVector(ab, bc) << endl;
    if (multiplitedVector(ab, bc) == 0) {
        cout << "vao ham 1" << endl;
        findPoint(bc.first, bc.second, xc, yc, xa, ya);
    }
    else if (multiplitedVector(bc, ac) == 0) {
        cout << "vao ham 2" << endl;
        findPoint(ac.first, ac.second, xc, yc, xb, yb);
    }
    else {
        cout << "vao hm 3" << endl;
        findPoint(ab.first, ab.second, xb, yb, xc, yc);
    }
}
int main() {
    vector<vector<int>> points;
    points = {{2, 8}, {2, 3}, {13, 3}};
    //points = {{2, 5}, {2, 2}, {5, 5}};
    points = {{40, 5}, {25, 5}, {40, -10}};
    //points = {{-22, 16}, {-14, 6}, {-4, 14}};
    createRectangle(points);
    return 0;
}