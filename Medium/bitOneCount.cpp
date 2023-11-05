#include <bits/stdc++.h>
#define MAX 100
using namespace std;

unsigned long long c[29] = {
    1, 3, 8, 20, 48, 112, 256, 576, 1280, 2816, 6144, 13312, 28672, 61440, 131072, 
        278528, 589824, 1245184, 2621440, 5505024, 11534336, 24117248, 50331648, 
        104857600, 218103808, 452984832, 939524096, 1946157056
};
int ans;
unsigned BitsSetTable256[256];

void initialize()
{
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
    }
}
 
int countSetBits(int n)
{
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}

unsigned long long findBitOne(int a, bool sign) {
    unsigned long long sum = 0;

    unsigned long long value = 1;
    int cnt = 0;
    while(value < a) {
        value = value<<1;
        
        cnt++;
    }

    //cout << "value = " << value << endl;
    value = value>>1;
    cnt--;
    for (int i = 0; i < cnt; i++) {
        sum = sum + c[i];
    }
    //cout << "sum = " << sum << endl;
    if (sign == true) {
        for (int i = value; i <= a; i++) {
            //cout << countSetBits(i) << endl;
            sum = sum + countSetBits(i);
        }
    }
    else {
        for (int i = value; i < a; i++) {
            //cout << countSetBits(i) << endl;
            sum = sum + countSetBits(i);
        }
    }

    return sum;
}
long long bitOneCount(int a, int b) {
    return findBitOne(b, true) - findBitOne(a, false);
}
int main() {
    initialize();
    int a, b;
    a = 0, b = 1000000000;
    //cout << findBitOne(b) << endl;
    //cout << findBitOne(a) << endl;
    cout << bitOneCount(a, b);
    return 0;
}