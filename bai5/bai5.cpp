#include<iostream>
using namespace std;
struct Fraction {
	int numerator=1, denominator=1;
	char slash='/';
	double fraction() {
		return (double) numerator / denominator;
	}
};
Fraction f[(int)1e7];
	void input(Fraction f[],int i) {
		cout << "Fraction [" << i << "]: ";
		cin >> f[i].numerator >> f[i].slash >> f[i].denominator;
		while (f[i].denominator == 0) {
			cout << "Enter a valid fraction!\n";
			cout << "Enter fraction [" << i << "] again: ";
			cin >> f[i].numerator >> f[i].slash >> f[i].denominator;
		}
	}
	void order(Fraction f[], int i) {
		for (int j = 1; j <= i; j++)
		{
			for (int k = j + 1; k <= i; k++)
			{
				if (f[k].fraction() < f[j].fraction())
					swap(f[k], f[j]);
			}
		}
	}
	void output(Fraction f[], int i) {
		for (int j = 1; j <= i; j++) {
			cout << f[j].numerator << "/" << f[j].denominator << " ";
		}
	}
	int GCD(int a, int b) {
		if (b == 0) return a;
		return GCD(b, a % b);
	}
	int LCM(int  a,int b) {
		return a / GCD(abs(a), abs(b)) * b;
	}
	double sum(Fraction f[], int i,int count, int& numerator,int& denominator) {
		for (int j = i; j <= count; j++)
		{
			denominator = LCM(denominator, f[j].denominator);
		}
		for (int j = i; j <= count; j++)
		{
			numerator += ((f[j].numerator) * (denominator / f[j].denominator));
		}
		return (double)numerator/denominator;
	}
	void printfraction(int numerator, int denominator) {
		cout << numerator << "/" << denominator;
	}
	void median(Fraction f[], int count,int& numerator,int& denominator) {
		if (count % 2 == 0) {
			numerator = 0;
			denominator = f[count / 2].denominator;
			sum(f,count / 2, count / 2 + 1, numerator, denominator);
			denominator *= 2;
			printfraction(numerator, denominator);
		}	
		else printfraction(f[count / 2 + 1].numerator, f[count / 2 + 1].denominator);
	}
	double Arithmetic_Mean(int i, int count, int& numerator, int& denominator) {
		numerator = 0;
		denominator = 1;
		sum(f,1,count, numerator, denominator);
		denominator *= count;
		int gcd=GCD(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		return (double)numerator / denominator;
	}
	
int main() {
	int count = 0, numerator=0,denominator=1;
	for (int i = 1;; i++)
	{
		input(f,i);
		if (f[i].numerator == 0) {
			cout << "The median of the fraction array: ";
			median(f,count, numerator, denominator);
			cout << "\nThe arithmetic mean of then fraction array: ";
			Arithmetic_Mean(1,count, numerator, denominator);
			printfraction(numerator,denominator);
			break;
		}
		count++;
		order(f,i);
		cout << "Fraction array after sorting in ascending order: ";
		output(f,i);
		cout << endl;
	}
	return 0;
}
