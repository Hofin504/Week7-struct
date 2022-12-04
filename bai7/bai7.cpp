#include <iostream>
#include <cmath>
const int MAX = 100;
using namespace std;
struct DaThuc
{
    int bac;
    double heSo[MAX];
    double giatri = 0;
};

DaThuc a[100];

void xaydung_dathuc(DaThuc a[], int &n)
{
    cout << "Nhap so da thuc: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap bac cua da thuc " << i << ": ";
        ;
        cin >> a[i].bac;
        for (int j = a[i].bac; j >= 0; j--)
        {
            cout << "Nhap he so x^" << j << ": ";
            cin >> a[i].heSo[j];
        }
    }
}
void nhan_x0(int &x0)
{
    cout << "Nhap x0: ";
    cin >> x0;
}
void nhan_giatri(DaThuc a[], int n, int x0)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i].bac; j >= 0; j--)
        {
            a[i].giatri += a[i].heSo[j] * pow(x0, j);
        }
    }
}
void xuat_giatri(DaThuc a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Gia tri da thuc " << i << ": " << a[i].giatri << endl;
    }
}
void tim(DaThuc a[], int n, double &max)
{
    max = a[1].giatri;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].giatri > max)
            max = a[i].giatri;
    }
}
void xuat_dathuc(DaThuc a[], int n, int max)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i].giatri == max)
        {
            for (int j = a[i].bac; j > 0; j--)
            {
                cout << a[i].heSo[j] << "x^" << j << " + ";
            }
            cout << a[i].heSo[0] << endl;
        }
    }
}

int main()
{
    int n;
    int x0;
    double max;
    xaydung_dathuc(a, n);
    nhan_x0(x0);
    nhan_giatri(a, n, x0);
    xuat_giatri(a, n);
    tim(a, n, max);
    xuat_dathuc(a, n, max);
    return 0;
}
