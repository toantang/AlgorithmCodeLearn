#include <bits/stdc++.h>

using namespace std;

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