#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int ans;
string x[N];
int d[N]; //mảng lưu trữ trạng thái của biến start

string p[N][N]; // mảng lưu trữ chuỗi p[start][v]
void printArray(string x[], int n) {
    for (int i = 0; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool comparison(string x, string y, int sizeX, int sizeY) {
    if (sizeY > sizeX) {
        return true;
    }
    else if (sizeX == sizeY) {
        for (int i = 0; i < sizeX; i++) {
            int convertX = x[i] - 48;
            int convertY = y[i] - 48;
            if (convertY > convertX) {
                return true;
            }
            else if (convertY < convertX) {
                return false;
            }
            else {
                continue;
            }
        }

        return false;
    }
    else {
        return false;
    }
}

string getString(int start, int v, string str) {
    string s;
    if (start == v) {
        s = str[start];
    }
    else {
        for (int i = start; i <= v; i++) {
            s += str[i];
        }
    }
    return s;
}

bool check(int start, int v, int n, int k, int cnt, string str) {
    int val = v - start + 1;
    if ((cnt + val) > n || x[k-1].size() > val || str[start] == '0') {
        return false;
    }
    return true;
}

void TRY(int start, int n, int k, int cnt, string str) {
    for (int v = start; v < n; v++) {
        if (v == start) {
            p[start][v] = str[v];
        }
        else {
            p[start][v] = p[start][v-1] + str[v];
        }
        //cout << "cnt: " << cnt << endl;
        if (check(start, v, n, k, cnt, str)) {
            cout << "v: " << v << endl;
            
            //string s = getString(start, v, str);
            string s  = p[start][v];
            //cout << "   v: " << v << endl;
            string xx = x[k-1];
            int sizeX = xx.size();
            int sizeY = v - start + 1;
            if (comparison(xx, s, sizeX, sizeY)) {
                cout << "       s = " << s << endl;
                x[k] = s;
                d[k] = start;
                k++;
                cnt += v - start + 1;
                start = v + 1;
                //cout << "       cnt " << cnt << endl;
                if (cnt == n) {
                    cout << "           tap nghiem: ";
                    printArray(x, k);
                    ans++;
                }
                else if (sizeY + cnt <= n) {
                    cout << "   start = " << start << ", k = " << k << ", cnt = " << cnt << endl;
                    TRY(start, n, k, cnt, str);
                }


                x[k] = "";
                p[start][v] = "";
                k--;
                start = d[k];
                                cnt -= v - start + 1;
            }
        }
    }
}
void splString(string str) {

}
int main() {
    string str;
    str = "21023";
    //str = "111";
    //str = "435060";
    //str = "9273865453264918";
    str = "7893386358483654422381792738654532649187893386358483654422381792738654532649189273865453264912548761";
    string s;
    int len = str.size();
    //cout << len << endl;
    for (int i = 0; i < len; i++) {
        s += str[i];
        x[0] = s;
        d[0] = 0;
        int start = i + 1;
        int cnt = s.size();
        p[start][start] = s;
        /*for (int j = 1; j < len; j++) {
            x[j] = "";
        }*/
        if (cnt == len) {
            ans++;
            //printArray(x, cnt);
        }
        //cout << "i : " << i << endl;
        TRY(start, len, 1, cnt, str);
    }
    cout << ans << endl;    
    return 0;
}