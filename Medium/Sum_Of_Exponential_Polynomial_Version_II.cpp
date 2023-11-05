#include <bits/stdc++.h>

using namespace std;

long long const C = 1000000007;

struct PhanSo{
	int tuSo;
	int mauSo;
    void toString() {
        cout << tuSo << "/" << mauSo << " ";
    }
};


PhanSo rutGon(PhanSo ps){
	// Tim USCLN
	int a = ps.tuSo;
	int b = ps.mauSo;

	a = abs(a);
	b = abs(b);
	
	int USCLN =1;
	// TH1
	if(a==0 || b==0){
		USCLN = (a+b);
	}else{
	//TH2
		while(a!=b){
			if(a>b){
				a = a-b;
			}else{
				b = b-a;
			}
		}
		USCLN = a;	
	}
	ps.tuSo/=USCLN;
	ps.mauSo/=USCLN;
    return ps;
}

PhanSo congHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*d + c*b)/(b*d)
	ketQua.tuSo = ps1.tuSo*ps2.mauSo + ps2.tuSo*ps1.mauSo;
	ketQua.mauSo = ps1.mauSo*ps2.mauSo;
    ketQua = rutGon(ketQua);
	return ketQua;
}

PhanSo truHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*d - c*b)/(b*d)
	ketQua.tuSo = ps1.tuSo*ps2.mauSo - ps2.tuSo*ps1.mauSo;
	ketQua.mauSo = ps1.mauSo*ps2.mauSo;
    ketQua = rutGon(ketQua);
	return ketQua;
}

PhanSo nhanHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*c)/(b*d)
	ketQua.tuSo = ps1.tuSo*ps2.tuSo;
	ketQua.mauSo = ps1.mauSo*ps2.mauSo;
    ketQua = rutGon(ketQua);
	return ketQua;
}

PhanSo chiaHaiPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	// a/b + c/d => (a*d)/(b*c)
	ketQua.tuSo = ps1.tuSo*ps2.mauSo;
	ketQua.mauSo = ps1.mauSo*ps2.tuSo;
    ketQua = rutGon(ketQua);
	return ketQua;
}


PhanSo a[101][101];

void createTamGiacTrung(int n, int k) {
    PhanSo ps_default;
    ps_default.tuSo = 1;
    ps_default.mauSo = 1;
    a[0][1] = ps_default;
    for (int i = 1; i <= k; i++) {
        PhanSo sum;
        sum.tuSo = 0;
        sum.mauSo = 1;
        for (int j = 2; j <= i+1; j++) {
            PhanSo ps;
            ps.tuSo = i;
            ps.mauSo = j;
            a[i][j] = nhanHaiPhanSo(ps, a[i-1][j-1]);        
            sum = congHaiPhanSo(sum, a[i][j]);
        }
        a[i][1] = truHaiPhanSo(ps_default, sum);
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= k+1; j++) {
            a[i][j].toString();
        }
        cout << endl;
    }
}

//find n^k mod p
unsigned long long findMod(int n, int k, int p) {
    unsigned long long ret = 1;
    n %= p;
    k %= p - 1;
    while(k > 0) {
        if (k%2 > 0) {
            ret = ret * n%p;
        }
        n = n * n%p;
        k = k/2;
    }
    return ret;
}

//find a/b mod p
unsigned long long findDivisionMod(int a, int b, int p) {
    return ((a%p) * (findMod(b, p - 2, p)))%p;
}
int soep(long long n, long long k)
{
    long long ans = 0;
    for (int j = 1; j <= k + 1; j++) {
        PhanSo ps = a[k][j];
        unsigned long long x = findDivisionMod(ps.tuSo, ps.mauSo, C);
        cout << "x: " << x << endl;
        unsigned long long y = findMod(n, k, C);
        ans = (ans%C + (x*y)%C)%C;
    }
    // for (int i = 1; i <= n; i++) {
    //     long long modNum = findMod(i, k, C);
    //     if (modNum < 0) {
    //         cout << "i: " << i << ", ";
    //         cout << "modNum: " << modNum << endl;
    //         break;
    //     }
    //     ans = (ans%C+ modNum%C)%C;
    //     //cout << "ans: " << ans << endl;
    // }
    return (int)ans;
};

int main() {
    long long n = 4, k = 2;
    //long long n = 10, k = 9;
    //long long n = pow(10, 18), k = 100;
    // long long n = 3, k = 100;
    // unsigned long long modNum = findMod(3, 11, 13);
    createTamGiacTrung(123, k);
    cout << soep(n, k) << endl;
    findDivisionMod(1, 6, C);
    return 0;
}