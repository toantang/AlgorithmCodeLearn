#include <math.h>
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    cout << "max_int" << INT_MAX << endl;
    float duration;
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "so n vua nhap: " << n << endl;
    int a = 0;

    clock_t start = clock();
    int val = (n+1) * (n+2)/4;
    a = (n-1) * n * val;
    // for (int i = 1; i <= n; i++)
    // {
    //     a += (i - 1) * i * (i + 1);
    // }
    cout << "result: " << a << endl;
    clock_t finish = clock(); // ghi lại thời gian lúc sau
    duration = (float)(finish - start) / CLOCKS_PER_SEC;
    printf("%2.9f giay\n", duration);
    return 0;
}