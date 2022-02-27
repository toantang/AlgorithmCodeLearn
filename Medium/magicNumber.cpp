#include <bits/stdc++.h>

using namespace std;

int maxDivide(int a, int b)
{while (a % b == 0)
        a = a / b;
    return a;
}
 
// Function to check if a number is ugly or not
int isUgly(int no)
{
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
    no = maxDivide(no, 7);
 
    return (no == 1) ? 1 : 0;
}
    
 
// Function to get the nth ugly number
int getNthUglyNo(int n)
{
    
    int i = 1;
     
    // ugly number count
    int count = 1;
 
    // Check for all integers untill ugly count
    //  becomes n
    while (n > count) {
        i = i + 2;
        //cout << "i = " << i << endl;
        if (isUgly(i)) {
            count++;
            //cout << "count = " << count << endl;
        }
    }
    return i;
}
 
// Driver Code
int main()
{
    // Function call
    unsigned no = getNthUglyNo(500);
    cout << no << endl;
    getchar();
    return 0;
}