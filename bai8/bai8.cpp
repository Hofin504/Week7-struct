#include <iostream>
#include <string>
using namespace std;
struct HocSinh
{
    string maSV;         // ma so sinh vien la chuoi co 8 ky tu
    string hoTen;        // ho ten la chuoi toi da 30 ky tu
    double diemLyThuyet; // diem thuoc [0,10]
    double diemThucHanh; // diem thuoc [0,10]
    double diemQuaTrinh; // diem thuoc [0,10]
    double diemTongKet;  // diem thuoc [0,10]
    void nhan_maSV()
    {
        cout << "Nhap Ma SV: ";
        cin >> maSV;
        while (maSV.size() != 8)
        {
            cout << "Ma SV phai co 8 ky tu, nhap lai Ma SV: ";
            cin >> maSV;
        }
    }
    void nhan_thongtin()
    {
        cin.ignore(); // them vao de xoa bo nho dem, tranh bi troi lenh
        cout << "Nhap Ho Ten: ";
        getline(cin, hoTen);
        while (hoTen.size() > 30)
        {
            cout << "Ho Ten co toi da 30 ky tu, nhap lai Ho Ten: ";
            cin >> hoTen;
        }
        cout << "Nhap diem Thuc Hanh: ";
        cin >> diemThucHanh;
        while (diemThucHanh < 0 || diemThucHanh > 10)
        {
            cout << "Diem phai lon hon hoac bang 0 va nho hon hoac bang 10, nhap diem Thuc Hanh: ";
            cin >> diemThucHanh;
        }
        cout << "Nhap diem Qua Trinh: ";
        cin >> diemQuaTrinh;
        while (diemQuaTrinh < 0 || diemQuaTrinh > 10)
        {
            cout << "Diem phai lon hon hoac bang 0 va nho hon hoac bang 10, nhap diem Qua Trinh: ";
            cin >> diemQuaTrinh;
        }
    }
    void nhan_diemLyThuyet() // nhan diem ly thuyet cua sinh vien
    {
        cin >> diemLyThuyet;    
        while (diemLyThuyet < 0 || diemLyThuyet > 10)
        {
            cout << "Diem phai lon hon hoac bang 0 va nho hon hoac bang 10, nhap diem Ly Thuyet: ";
            cin >> diemLyThuyet;
        }
        diemTongKet = (diemLyThuyet * 0.6) + (diemThucHanh * 0.3) + (diemQuaTrinh * 0.1); // cap nhat diem tong ket sau khi co diem ly thuyet
    }
    void xuat_thongtin() // in cac thong tin cua sinh vien
    {
        cout << "\nMa SV: " << maSV << endl;
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Diem Ly Thuyet: " << diemLyThuyet << endl;
        cout << "Diem Thuc Hanh: " << diemThucHanh << endl;
        cout << "Diem Qua Trinh: " << diemQuaTrinh << endl;
        cout << "Diem Tong Ket: " << diemTongKet << endl;
    }
};

HocSinh s[100];
void tao_dsSV(HocSinh s[], int &n) // tao danh sach sinh vien theo 2 cach, biet truoc so luong sv hoac chua biet
{
    char luachon;
    cout << "1. Da biet so luong SV \n";
    cout << "2. Chua biet so luong SV\n";
    cin >> luachon;
    while (luachon != '1' && luachon != '2')
    {
        cout << "Nhap lai lua chon\n";
        cout << "1. Da biet so luong SV \n";
        cout << "2. Chua biet so luong SV\n";
        cin >> luachon;
    }
    if (luachon == '1')
    {
        cout << "Nhap so SV can quan li: ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << "\nSinh vien[" << i << "]\n";
            s[i].nhan_maSV();
            for (int j = 1; j < i; j++)
            {
                if (s[i].maSV == s[j].maSV)
                    do
                    {
                        cout << "Ma SV nay da ton tai!, nhap Ma SV khac: ";
                        cin >> s[i].maSV;
                        while (s[i].maSV.size() != 8)
                        {
                            cout << "Ma SV phai co 8 ky tu, nhap lai Ma SV: ";
                            cin >> s[i].maSV;
                        }

                    } while (s[i].maSV == s[j].maSV);
            }
            s[i].nhan_thongtin();
        }
    }
    else
    {
        n = 1;
        char ans;
        do
        {
            cout << "\nSinh vien[" << n << "]\n";
            s[n].nhan_thongtin();
            cout << "Nhap thong tin sinh vien khac khong?(y/n) ";
            cin >> ans;
            if (ans == 'y')
                n++;
        } while (ans == 'y');
    }
}
void nhap_diemLyThuyet(HocSinh s[], int n) // nhap diem ly thuyet cua sinh vien
{
    for (int i = 1; i <= n; i++)
    {
        cout << "\nNhap diem Ly Thuyet cua " << s[i].hoTen << ": ";
        s[i].nhan_diemLyThuyet();
    }
}
void in_thongtin(HocSinh s[], int n) // in cac thong tin cua sinh vien
{
    for (int i = 1; i <= n; i++)
    {
        s[i].xuat_thongtin();
    }
}
void sapxep_diemTongKet(HocSinh s[], int n) // sap xep danh sach sinh vien theo thu tu diem tong ket giam dan
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (s[j].diemTongKet > s[i].diemTongKet)
                swap(s[i], s[j]);
        }
    }
}
void in_ds_diemTongKet(HocSinh s[], int n) // in danh sach sinh vien sau khi sap xep
{
    for (int i = 1; i <= n; i++)
    {
        cout << "\nSTT: " << i << endl;
        cout << "Ma SV: " << s[i].maSV << endl;
        cout << "Ho Ten: " << s[i].hoTen << endl;
        cout << "Diem Ly Thuyet: " << s[i].diemLyThuyet << endl;
        cout << "Diem Thuc Hanh: " << s[i].diemThucHanh << endl;
        cout << "Diem Qua Trinh: " << s[i].diemQuaTrinh << endl;
        cout << "Diem Tong Ket: " << s[i].diemTongKet << endl;
    }
}
int main()
{
    int n;
    tao_dsSV(s, n);
    nhap_diemLyThuyet(s, n);
    in_thongtin(s, n);
    sapxep_diemTongKet(s, n);
    in_ds_diemTongKet(s, n);
    return 0;
}
