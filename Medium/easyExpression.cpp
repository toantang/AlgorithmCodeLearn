#include <bits/stdc++.h>

using namespace std;
 
int check_to_number(string s) //kiem tra la so
{
    int check = 1, l = s.length();
    for (int i = 1; i<l; i++)
        if (!isdigit(s[i]) && s[i] != '.') //duyt tu phan tu thu 2neu khong la so hoac thi check = 0
        {
            check = 0;
            break;
        }
    if (s[0] == '-' && check == 1) return 2; //kiem tra dau xau co la -
    if (s[0] == '/' && check == 1) return 3; //kiem tra  dau xau co la /
    if (isdigit(s[0]) && check == 1) return 1; //dau xau la so
}
 
float convert_to_number(string s)
{
    float number, check = check_to_number(s);
    if (check > 0)
    {
        if (check == 1)  //neu la so binhf thuong
        {
            stringstream ss (s);
            ss >> number;
        }
        if (check > 1)
        {
            stringstream ss (s.substr(1,s.length()-1));
            ss >> number;
            if (check == 2) number = 0 - number; //neu la phep tru
            if (check == 3) number = 1/number; // neu la phep chia
        }
        return number;
    }
}
 
float process(string s, int l, int r)
{
    int li = 0, ri = r;
    if (check_to_number(s))  return convert_to_number(s); //{ cout <<"  "<<convert_to_number(s)<<endl; return convert_to_number(s);}
    else
    {
        int i;
        for (i=li; i<ri; i++) if (s[i] == '+') return process(s.substr(li, i-li), li, i) + process(s.substr(i+1, ri-i), i+1, ri-i);
        for (i=li; i<ri; i++) if (s[i] == '*') return process(s.substr(li, i-li), li, i) * process(s.substr(i+1, ri-i), i+1, ri-i);
    }
    return 0;
}
 

int main() {
    string s = "100*0+1";
    cout << process(s, 0, s.size() - 1);
    return 0;
}