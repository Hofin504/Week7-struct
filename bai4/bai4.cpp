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
