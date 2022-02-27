#include <bits/stdc++.h>

using namespace std;

vector<int> edge;
bool ans = true;
void caculateEdge(vector<int> x, vector<int> y) {
    for(int i = 0; i < 4; i++) {
        int xi = x[i];
        int yi = y[i];
        for (int j = i + 1; j < 4; j++) {
            int xj = x[j];
            int yj = y[j];
            int a = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
            edge.push_back(a);
        }
    }
}

void isSquare(vector<int> x, vector<int> y) {
    sort(edge.begin(), edge.end());
    int length = edge.size();
    if (edge[0] >= edge[length - 1]) {
        ans = false;
    }
    else {
        int countEqualEdge = 0;
        int countDiagonal = 0;
        for (int i = 0; i < length - 3; i++) {
            if (edge[i] == edge[i+1]) {
                countEqualEdge++;
            }
            else {
                ans = false; 
                break;
            }
        }

        if (edge[4] == edge[5]) {
            countDiagonal = 1;
        }
        else {
            ans = false;
        }
    }
}
int main() {
    vector<int> x, y;
    //x = {-4, -5, -4, -2}, y = {1, 2, 4, -2};
    //x = {-1, -1, 3, 3}, y = {0, 4, 0, 4};
    //x = {-1, 1, 3, 1}, y = {2, 0, 2, 4};
    //x = {-3, 4, -1, 2}, y = {-2, 1, 3, -4};
    //x = {0, 0, 0, 0}, y = {0, 1, 2, 3};
    x = {-4, -5, -4, -2}, y ={1, 2, 4, -2};
    caculateEdge(x, y);
    isSquare(x, y);
    for (int i = 0; i < 6; i++) {
        cout << edge[i] << " ";
    }
    cout << ans << endl;
    return 0;
}