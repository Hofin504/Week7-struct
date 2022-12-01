#include <iostream>

using namespace std;

struct ConTrau {
	int TrauDung{},TrauNam{},TrauGia{};
	ConTrau(){}
	ConTrau(int TrauDung, int TrauNam, int TrauGia) {
		this->TrauGia = TrauGia;
		this->TrauDung = TrauDung;
		this->TrauNam = TrauNam;
	}
};

ConTrau Nghiem_TramTrau_TramCo(const int& CTrau, const int& CCo,const int &DIni,const int &GIni) { // tim kiem nghiem tiep theo 
	for (int D = DIni; D <= CTrau; D++) {
		for (int G = GIni; G <= CTrau - D; G++) {
			int N = CTrau - D - G;
			if (D * 15 + 9 * N + G == 3 * CCo) return ConTrau(D, N, G);
		}
	}
	return ConTrau(0, 0, 0);
}

int n = 1; // so luong nghiem cua phuong trinh

void Find_nghiem(ConTrau *Nghiem, const int &Cnt_Trau,const int &Cnt_Co) {
	Nghiem[1] = Nghiem_TramTrau_TramCo(Cnt_Trau, Cnt_Co, 1, 1);
	while (Nghiem[n].TrauNam && Nghiem[n].TrauDung && Nghiem[n].TrauGia) {
		++n;
		Nghiem[n] = Nghiem_TramTrau_TramCo(Cnt_Trau, Cnt_Co, Nghiem[n - 1].TrauDung + 1, Nghiem[n - 1].TrauGia + 1);
	}
	n--;
}

void Input(int &CTrau,int &CCo) {
	cout << "Nhap So Luong Con Trau : "; cin >> CTrau;
	cout << "Nhap So Luong Co : "; cin >> CCo;
}

void Output(ConTrau *Nghiem) {
	if (n == 0) {
		cout << "Khong Ton Tai Nghiem";
		return;
	}
	cout << "Nghiem Cua Phuong Trinh (Lan luot la trau dung, trau nam, trau gia) : \n";
	for (int i = 1; i <= n; i++) {
		cout << Nghiem[i].TrauDung << " " << Nghiem[i].TrauNam << " " << Nghiem[i].TrauGia << '\n';
	}
}

ConTrau Nghiem[(int)1e4]; // nghiem cua phuong trinh 

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int Cnt_Trau, Cnt_Co;
	Input(Cnt_Trau, Cnt_Co);
	Find_nghiem(Nghiem, Cnt_Trau, Cnt_Co);
	Output(Nghiem);
}
