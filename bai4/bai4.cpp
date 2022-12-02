// Bai 4
#include<iostream>
using namespace std;
// cau a
struct ThongTinTrongNam {
	int ngay;
	int thang;
	char dau;
    void NhapNgay_Thang()
    {
        cin >> ngay >> dau >> thang;
    }
};
void SapXepThoiGianA(ThongTinTrongNam ngay_thang[], int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (ngay_thang[j].thang < ngay_thang[i].thang) {
                swap(ngay_thang[i], ngay_thang[j]);
            }
            if (ngay_thang[j].thang == ngay_thang[i].thang) {
                if (ngay_thang[j].ngay < ngay_thang[i].ngay) {
                    swap(ngay_thang[i], ngay_thang[j]);
                }
            }
        }
    }
}
ThongTinTrongNam ngay_thang[(int)2e7];
// cau b
#include<iostream>
using namespace std;
struct ThongTinTrongNgay {
    int gio;
    int phut;
    int giay;
    char dau;
    void NhapGio_Phut_Giay() {
        cin >> gio >> dau >> phut >> dau >> giay;
    }
    int doigiay() {
        return (gio*3600)+(60*phut)+giay;
    }
};
void SapXepThoiGianB(ThongTinTrongNgay gio_giac[] , int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if( gio_giac[j].doigiay() < gio_giac[i].doigiay()) swap(gio_giac[j],gio_giac[i]);
        }
    }
}
ThongTinTrongNgay gio_giac[(int)2e7];
// cau c
struct Thoi_Gian {
	int nam;
	int thang;
	int ngay;
	int gio;
	int phut;
	char dau;
};
Thoi_Gian a[(int)2e7];
void NhapThoiGian(Thoi_Gian a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap Thoi Gian [" << i << "]: ";
		cin >> a[i].ngay >> a[i].dau >> a[i].thang >> a[i].dau >> a[i].nam >> a[i].dau >> a[i].gio >> a[i].dau >> a[i].phut;
	}
}
void XuatThoiGian(Thoi_Gian a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam << " " << a[i].gio<< ":" << a[i].phut << "\n";
	}
}
bool KT_NamNhuan(Thoi_Gian a[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (a[i].nam % 400 == 0 || (a[i].nam % 4 == 0 && a[i].nam % 100 != 0)) {
			return true;
		} //neu la nam nhuan se true
		else {
			return false;
		} //false
	}
}
int DoiThang_SangNgay(Thoi_Gian a[], int n) {
	for (int i = 0; i < n; i++)
	{
		switch (a[i].thang)
		{
		case 1: return 31; break;
		case 2:
			if (KT_NamNhuan(a, n) == true) return 60;
			else return 59;
			break;
		case 3: 
			if (KT_NamNhuan(a, n) == true) return 91;
			else return 90;
			break;
		case 4: 
			if (KT_NamNhuan(a, n) == true) return 121;
			else return 120;
			break;
		case 5:
			if (KT_NamNhuan(a, n) == true) return 152;
			else return 151;
			break;
		case 6: 
			if (KT_NamNhuan(a, n) == true) return 182;
			else return 181;
			break;
		case 7:
			if (KT_NamNhuan(a, n) == true) return 213;
			else return 212;
			break;
		case 8: 
			if (KT_NamNhuan(a, n) == true) return 244 ;
			else return 243;
			break;
		case 9: 
			if (KT_NamNhuan(a, n) == true) return 274;
			else return 273;
			break;
		case 10:
			if (KT_NamNhuan(a, n) == true) return 305;
			else return 304;
			break;
		case 11:
			if (KT_NamNhuan(a, n) == true) return 335;
			else return 334;
			break;
		case 12:
			if (KT_NamNhuan(a, n) == true) return 366;
			else return 365;
			break;
		}
	}
}

int DoiNam_SangNgay(Thoi_Gian a[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (KT_NamNhuan(a, n) == true) return 366;
		else return 365;
	}
}
double DoiGioPhut_SangNgay(Thoi_Gian a[], int n) {
	for (int i = 0; i < n; i++)
	{
		return ((a[i].gio / 24.0) + (a[i].phut / 1440.0));
	}
}
int HamTinhNgay(Thoi_Gian a[],int n) {
	return (DoiGioPhut_SangNgay(a, n) + DoiNam_SangNgay(a, n) + DoiThang_SangNgay(a, n));
}
void SapXepThoiGian(Thoi_Gian a[], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((a[j].ngay+HamTinhNgay(a,n)) < (HamTinhNgay(a,n)+a[i].ngay)) {
				swap(a[j],a[i]);
			}
		}
	}
}
void NhapMang(Thoi_Gian a[], int& n) // ham nhap mang n phan tu
{
	char choice;
	cout << "1. Biet so luong phan tu\n"
		<< "2. Khong biet so luong phan tu\n";
	cin >> choice;
	if (choice == '2')
	{
		char ans;
		n = 0;
		do
		{
			cout << "Nhap Thoi Gian [" << n << "]: ";
			NhapThoiGian(a,n);
			n++;
			cout << "Con khong? (y/n): ";
			cin >> ans;
		} while (ans == 'y' || ans == 'Y');
	}
	else if (choice == '1')
	{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		NhapThoiGian(a, n);
		
	}
}
