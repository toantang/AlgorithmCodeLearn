#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
    Point create(int x, int y) {
        Point p;
        p.x = x;
        p.y = y;
        return p;
    }
    string toString() {
        string xx = to_string(x);
        string yy = to_string(y);
        return "(" + xx + ", " + yy + ")";
        //return "Point{x: " + xx + ", y: " + yy + "}";
    }
};

int flag[21][21];
Point endingSquare;
vector<Point> stoneSquares = {};
Point startingSquare;
vector<Point> ans = {};
int cnt = 0;

void printAns() {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].toString() << ", ";
    }
    cout << endl;
}
void createDefault() {    
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            flag[i][j] = -1;
        }
    }
    int len = stoneSquares.size();
    if (len > 0) {
        for (int i = 0; i < len; i++) {
            Point stoneSquare = stoneSquares[i];
            flag[stoneSquare.x][stoneSquare.y] = 1;
        }
    }
}

bool isCanGoNext(int x, int y) {
    int len = stoneSquares.size();
    if (len > 0) {
        for (int i = 0; i < len; i++) {
            Point stoneSquare = stoneSquares[i];
            if (x == stoneSquare.x && y == stoneSquare.y) return false;
        }
    }
    return true;
}

bool isEndingPoint(int m, int n, vector<vector<int>>& grid) {
    Point endPoint = ans[ans.size() - 1];
    if (endPoint.x != endingSquare.x || endPoint.y != endingSquare.y) return false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (flag[i][j] < 0) {
                return false;
            }
        }
    }
    return true;
}

void TRY(int x, int y, int m, int n, vector<vector<int>>& grid) {
    flag[x][y] = 1;
    Point p;
    p.x = x;
    p.y = y;
    //cout << "========================" << endl;
    ans.push_back(p);
    //printAns();
    //cout << "========================" << endl;

    if (x - 1 >= 0 && y >= 0 && flag[x-1][y] < 0 && isCanGoNext(x-1, y)) {
        TRY(x-1, y, m, n, grid);
    }

    if (x + 1 < m && y >= 0 && flag[x+1][y] < 0 && isCanGoNext(x+1, y)) {
        TRY(x+1, y, m, n, grid);
    }
    
    if (x >= 0 && y - 1 >= 0 && flag[x][y-1] < 0 && isCanGoNext(x, y-1)) {
        TRY(x, y-1, m, n, grid);
    }

    if (x >= 0 && y + 1 < n && flag[x][y+1] < 0 && isCanGoNext(x, y+1)) {
        TRY(x, y+1, m, n, grid);
    }

    if (isEndingPoint(m, n, grid)) {
        printAns();
        cnt++;
    }

    ans.pop_back();
    flag[x][y] = -1;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int m, n;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j];
            if (val == 1) {
                startingSquare.x = i;
                startingSquare.y = j;
            }
            else if (val == 2) {
                endingSquare.x = i;
                endingSquare.y = j;
            }
            else if (val == -1) {
                Point stoneSquare;
                stoneSquare.x = i;
                stoneSquare.y = j;
                stoneSquares.push_back(stoneSquare);
            }
        }
    }
    createDefault();
    TRY(startingSquare.x, startingSquare.y, m, n, grid);   
    return cnt;
}

int main() {
    vector<vector<int>> grid;
    //grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    //grid = {{0, 1}, {2, 0}};
    grid = {{0,0,0,0,0},{0,-1,-1,0,1},{0,0,-1,0,2}};
    cout << uniquePathsIII(grid);
    return 0;
}