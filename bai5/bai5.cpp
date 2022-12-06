#include<iostream>
using namespace std;
//Struct Fraction co cac thuoc tinh numerator, splash, denominator va phuong thuc fraction
struct Fraction {
	int numerator, denominator;
	char slash;
	//Tinh gia tri thap phan cua phan so
	double fraction() {
		return (double) numerator / denominator;
	}
};
//Khai bao mang f gom 1e7 phan tu co kieu du lieu Fraction
Fraction f[(int)1e7];
//Ham nhap phan so
	void input(Fraction f[],int i) {
		cout << "Fraction [" << i << "]: ";
		cin >> f[i].numerator >> f[i].slash >> f[i].denominator;
		//Neu mau so=0 thi nhap lai phan so
		while (f[i].denominator == 0) {
			cout << "Enter a valid fraction!\n";
			cout << "Enter fraction [" << i << "] again: ";
			cin >> f[i].numerator >> f[i].slash >> f[i].denominator;
		}
	}
//Ham sap xep phan so 
	void order(Fraction f[], int i) {
		for (int j = 1; j <= i; j++)
		{
			for (int k = j + 1; k <= i; k++)
			{
				//Neu gia tri thap phan cua f[k]<f[j] thi swap f[k] va f[j]
				if (f[k].fraction() < f[j].fraction())
					swap(f[k], f[j]);
			}
		}
	}
	//Ham xuat day phan so 
	void output(Fraction f[], int i) {
		for (int j = 1; j <= i; j++) {
			cout << f[j].numerator << "/" << f[j].denominator << " ";
		}
	}
	//Ham tinh UCLN
	int GCD(int a, int b) {
		if (b == 0) return a;
		return GCD(b, a % b);
	}
	//Ham tinh BCNN
	int LCM(int  a,int b) {
		return a / GCD(abs(a), abs(b)) * b;
	}
	//Ham tinh tong cac phan tu phan so trong mang
	double sum(Fraction f[], int i,int count, int& numerator,int& denominator) {
		for (int j = i; j <= count; j++)
		{
			//Tinh mau so chung cua tat ca phan tu trong mang
			denominator = LCM(denominator, f[j].denominator);
		}
		for (int j = i; j <= count; j++)
		{
			//Tinh tong tu cua tat ca phan tu trong mang
			numerator += ((f[j].numerator) * (denominator / f[j].denominator));
		}
		return (double)numerator/denominator;
	}
	//Ham xuat phan so 
	void printfraction(int numerator, int denominator) {
		cout << numerator << "/" << denominator;
	}
	//Ham tinh trung vi
	void median(Fraction f[], int count,int& numerator,int& denominator) {
		//Neu so phan tu cua mang la so chan thi tinh trung binh cong cua hai phan tu o giua mang
		if (count % 2 == 0) {
			numerator = 0;
			denominator = f[count / 2].denominator;
			sum(f,count / 2, count / 2 + 1, numerator, denominator);
			denominator *= 2;
			int gcd = GCD(numerator, denominator);
			numerator /= gcd;
			denominator /= gcd;
			printfraction(numerator, denominator);
		}	
		//Neu so phan tu cua mang la so le thi lay phan tu o chinh giua mang
		else printfraction(f[count / 2 + 1].numerator, f[count / 2 + 1].denominator);
	}
	//Ham tinh trung binh cong cua cac phan tu trong mang
	double Arithmetic_Mean(int i, int count, int& numerator, int& denominator) {
		numerator = 0;
		denominator = 1;
		sum(f,1,count, numerator, denominator);
		//Lay tong cac phan tu phan so trong mang chia cho so luong phan tu trong mang
		denominator *= count;
		//Tinh UCLN tu va mau cua phan so trung binh cong
		int gcd=GCD(numerator, denominator);
		//Lam dep phan so trung binh cong
		numerator /= gcd;
		denominator /= gcd;
		return (double)numerator / denominator;
	}
	
int main() {
	int count = 0, numerator=0,denominator=1;
	for (int i = 1;; i++)
	{
		//Nhap phan so
		input(f,i);
		//Neu tu so = 0 dung nhap va tinh toan yeu cau de bai
		if (f[i].numerator == 0) {
			//Tinh trung vi cua mang
			cout << "The median of the fraction array: ";
			median(f,count, numerator, denominator);
			cout << "\nThe arithmetic mean of then fraction array: ";
			//Tinh trung binh cong cua cac phan tu trong mang
			Arithmetic_Mean(1,count, numerator, denominator);
			printfraction(numerator,denominator);
			break;
		}
		//Dem so phan tu trong mang
		count++;
		//Sap xep phan tu cua mang ngay sau khi nhap phan tu moi
		order(f,i);
		cout << "Fraction array after sorting in ascending order: ";
		//Xuat mang sau khi sap xep cac phan tu theo thu tu tang dan
		output(f,i);
		cout << endl;
	}
	return 0;
}
