#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
struct SVstr
{
	string MaHang, TenHang, DonViTinh, dd, mm, yy, SoLuong;
	int DonGia;
	long int ThanhTien;
	SVstr() {}
};
SVstr C[100];

struct SV
{
	string MaHang, TenHang, DonViTinh;
	int dd, mm, yy, SoLuong, DonGia;
	long int ThanhTien;
	SV() {}
};
SV A[100];

void docdulieuSV(ifstream& myFile, SVstr C[], int i) {
	getline(myFile, C[i].MaHang, ',');
	myFile.ignore(1);
	getline(myFile, C[i].TenHang, ',');
	myFile.ignore(1);
	getline(myFile, C[i].DonViTinh, ',');
	myFile.ignore(1);
	getline(myFile, C[i].dd, '/');
	myFile.ignore(1);
	getline(myFile, C[i].mm, '/');
	myFile.ignore(1);
	getline(myFile, C[i].yy, ',');
	myFile.ignore(1);
	getline(myFile, C[i].SoLuong, ',');
	myFile.ignore(1);
	myFile >> C[i].DonGia;
	myFile.ignore(1);

}

void doiIntt(SVstr C[], SV A[], int i)
{
	stringstream str2num(C[i].dd);
	str2num >> A[i].dd;
	stringstream str3num(C[i].mm);
	str3num >> A[i].mm;
	stringstream str4num(C[i].yy);
	str4num >> A[i].yy;
	stringstream str5num(C[i].SoLuong);
	str5num >> A[i].SoLuong;
	A[i].MaHang = C[i].MaHang;
	A[i].TenHang = C[i].TenHang;
	A[i].DonViTinh = C[i].DonViTinh;
	A[i].DonGia = C[i].DonGia;
}
string thousandSeparator(long int n)
{
	string ans = "";

	// Convert the given integer
	// to equivalent string
	string num = to_string(n);

	// Initialise count
	int count = 0;

	// Traverse the string in reverse
	for (int i = num.size() - 1;
		i >= 0; i--) {
		count++;
		ans.push_back(num[i]);

		// If three characters
		// are traversed
		if (count == 3) {
			ans.push_back(',');
			count = 0;
		}
	}

	// Reverse the string to get
	// the desired output
	reverse(ans.begin(), ans.end());

	// If the given string is
	// less than 1000
	if (ans.size() % 4 == 0) {

		// Remove ','
		ans.erase(ans.begin());
	}

	return ans;
}
void xuat(SV A[], int i)
{
	string dStr, mStr, yStr;
	const char separator = ' ';
	const int nameWidth = 10;
	const int numWidth = 12;
	ostringstream dConvert, mConvert, yConvert;
	dConvert << A[i].dd;
	mConvert << A[i].mm;
	yConvert << A[i].yy;

	dStr = dConvert.str();
	yStr = yConvert.str();
	mStr = mConvert.str();

	string date = dStr + "/" + mStr + "/" + yStr;
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------"
		<< "|" << endl;
	if (i == 1)
	{
		cout << "|" << left << setw(8) << setfill(separator) << "Stt";
		cout << "|" << left << setw(8) << setfill(separator) << "MaHang";
		cout << "|" << left << setw(15) << setfill(separator) << "TenHang";
		cout << "|" << left << setw(15) << setfill(separator) << "DonViTinh";
		cout << "|" << left << setw(15) << setfill(separator) << "Ngay";
		cout << "|" << left << setw(8) << setfill(separator) << "SoLuong";
		cout << "|" << left << setw(8) << setfill(separator) << "DonGia";
		cout << "|" << left << setw(15) << setfill(separator) << "ThanhTien"
			<< "|" << endl;

		cout << "+" << left << setw(8) << setfill(separator) << "--------";
		cout << "+" << left << setw(8) << setfill(separator) << "--------";
		cout << "+" << left << setw(15) << setfill(separator) << "---------------";
		cout << "+" << left << setw(15) << setfill(separator) << "---------------";
		cout << "+" << left << setw(15) << setfill(separator) << "---------------";
		cout << "+" << left << setw(8) << setfill(separator) << "--------";
		cout << "+" << left << setw(8) << setfill(separator) << "--------";
		cout << "+" << left << setw(15) << setfill(separator) << "---------------"
			<< "|" << endl;
	}
	cout << "|" << left << setw(8) << setfill(separator) << i;
	cout << "|" << left << setw(8) << setfill(separator) << A[i].MaHang;
	cout << "|" << left << setw(15) << setfill(separator) << A[i].TenHang;
	cout << "|" << left << setw(15) << setfill(separator) << A[i].DonViTinh;
	cout << "|" << left << setw(15) << setfill(separator) << date;
	cout << "|" << left << setw(8) << setfill(separator) << A[i].SoLuong;
	cout << "|" << left << setw(8) << setfill(separator) << thousandSeparator(A[i].DonGia);
	cout << "|" << left << setw(15) << setfill(separator) << thousandSeparator(A[i].ThanhTien) << "|" << endl;


	// cout << left << setw(nameWidth) << setfill(separator) << "Bob";

	// cout << A[i].MaHang << " " << A[i].TenHang << " " << A[i].DonViTinh << " " << A[i].dd << " " << A[i].mm << " " << A[i].yy << " " << A[i].SoLuong << " " << A[i].DonGia << " " << A[i].ThanhTien << " " << endl;
}
void xuatXoa(SV A[], int i)
{
	string dStr, mStr, yStr;
	const char separator = ' ';
	const int nameWidth = 10;
	const int numWidth = 12;
	ostringstream dConvert, mConvert, yConvert;
	dConvert << A[i].dd;
	mConvert << A[i].mm;
	yConvert << A[i].yy;

	dStr = dConvert.str();
	yStr = yConvert.str();
	mStr = mConvert.str();

	string date = dStr + "/" + mStr + "/" + yStr;


	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------" << "|" << endl;



	cout << "|" << left << setw(8) << setfill(separator) << A[i].MaHang;
	cout << "|" << left << setw(15) << setfill(separator) << A[i].TenHang;
	cout << "|" << left << setw(15) << setfill(separator) << A[i].DonViTinh;
	cout << "|" << left << setw(15) << setfill(separator) << date;
	cout << "|" << left << setw(8) << setfill(separator) << A[i].SoLuong;
	cout << "|" << left << setw(8) << setfill(separator) << A[i].DonGia;
	cout << "|" << left << setw(15) << setfill(separator) << A[i].ThanhTien << "|" << endl;

	// cout << left << setw(nameWidth) << setfill(separator) << "Bob";

	// cout << A[i].MaHang << " " << A[i].TenHang << " " << A[i].DonViTinh << " " << A[i].dd << " " << A[i].mm << " " << A[i].yy << " " << A[i].SoLuong << " " << A[i].DonGia << " " << A[i].ThanhTien << " " << endl;
}
long int ThanhTienFunc(SV A[], int i)
{
	if (A[i].SoLuong > 100)
	{
		A[i].ThanhTien = A[i].SoLuong * A[i].DonGia;
		return A[i].ThanhTien - A[i].ThanhTien * 0.15;
	}
	if (A[i].SoLuong > 50 && A[i].SoLuong <= 100)
	{
		A[i].ThanhTien = A[i].SoLuong * A[i].DonGia;
		return A[i].ThanhTien -= A[i].ThanhTien * 0.1;
	}
	if (A[i].SoLuong <= 50)
	{
		return A[i].ThanhTien = A[i].SoLuong * A[i].DonGia;
	}
}

void sapXepTangDanDonGia(SV a[], int n)
{
	SV Mid;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (a[j + 1].DonGia > a[i + 1].DonGia)
			{
				Mid = a[i + 1];
				a[i + 1] = a[j + 1];
				a[j + 1] = Mid;
			}
		}


	cout << "	1 .DANH SACH DUOC SAP XEP TANG DAN THEO DON GIA:" << endl << endl;
	for (int i = 1; i <= n; i++)
	{
		xuat(a, i);
	}
	system("pause");
}
void sapXepGiamDanDonGia(SV a[], int n)
{
	SV Mid;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (a[j + 1].DonGia < a[i + 1].DonGia)
			{
				Mid = a[i + 1];
				a[i + 1] = a[j + 1];
				a[j + 1] = Mid;
			}
		}


	cout << "	2 .DANH SACH DUOC SAP XEP GIAM DAN THEO DON GIA:" << endl << endl;
	for (int i = 1; i <= n; i++)
	{
		xuat(a, i);
	}
	system("pause");
}

void sapXepTangDanSoLuong(SV a[], int n)
{
	SV Mid;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (a[j + 1].SoLuong > a[i + 1].SoLuong)
			{
				Mid = a[i + 1];
				a[i + 1] = a[j + 1];
				a[j + 1] = Mid;
			}
		}


	cout << "	3 .DANH SACH DUOC SAP XEP TANG DAN THEO SO LUONG:" << endl << endl;
	for (int i = 1; i <= n; i++)
	{
		xuat(a, i);
	}
	system("pause");
}
void sapXepGiamDanSoLuong(SV a[], int n)
{
	SV Mid;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (a[j + 1].SoLuong < a[i + 1].SoLuong)
			{
				Mid = a[i + 1];
				a[i + 1] = a[j + 1];
				a[j + 1] = Mid;
			}
		}


	cout << "	4 .DANH SACH DUOC SAP XEP GIAM DAN THEO SO LUONG:" << endl << endl;
	for (int i = 1; i <= n; i++)
	{
		xuat(a, i);
	}
	system("pause");
}

void indanhsach(SV A[], int cnt)
{
	cout << endl;
	for (int i = 1; i <= cnt; i++)
	{
		xuat(A, i);
	}
	system("pause");
}
void sapXepTangDanNgayNhap(SV a[], int cnt)
{
	cout << "	5 .DANH SACH DUOC SAP XEP TANG DAN THEO NGAY NHAP:" << endl << endl;
	SV B[100];
	for (int i = 1; i <= cnt; i++)
		B[i] = A[i];

	//sap xem nam:
	SV temp[10];
	for (int i = 1; i <= cnt - 1; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			if (B[i].yy > B[j].yy)
			{
				temp[1] = B[i];
				B[i] = B[j];
				B[j] = temp[1];
			}
		}
	}
	//sap xep thang:
	for (int i = 1; i <= cnt - 1; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			if (B[i].yy == B[j].yy)
			{
				if (B[i].mm > B[j].mm)
				{
					temp[1] = B[i];
					B[i] = B[j];
					B[j] = temp[1];
				}
			}
		}
	}
	//sap xep ngay:
	for (int i = 1; i <= cnt - 1; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			if (B[i].mm == B[j].mm && B[i].yy == B[j].yy)
			{
				if (B[i].dd > B[j].dd)
				{
					temp[1] = B[i];
					B[i] = B[j];
					B[j] = temp[1];
				}
			}
		}
	}

	indanhsach(B, cnt);
	cout << endl;
}

void chen(SV A[], int& cnt)
{
	int chen;
	cout << "\n|--- CHEN PHAN TU ------------------|";
	cout << "\n| 1. Chen theo So luong             |";
	cout << "\n| 2. chen theo don gia              |";
	cout << "\n|-----------------------------------|";
	cout << "\n Chon: ";
	cin >> chen;
	if (chen == 1)
		goto chenSoLuong;
	else if (chen == 2)
		goto chenDonGia;



chenSoLuong:
	{
		sapXepTangDanSoLuong(A, cnt);
		cnt++;
		cout << endl << "*Nhap thong tin don nhap hang can chen: " << endl;
		cout << "nhap ma hang: ";
		cin.ignore();
		fflush(stdin);
		getline(cin, A[cnt].MaHang);
		cout << "nhap ten hang: ";
		fflush(stdin);
		getline(cin, A[cnt].TenHang);
		cout << "nhap don vi tinh: ";
		fflush(stdin);
		getline(cin, A[cnt].DonViTinh);
		cout << "nhap ngay nhap hang: ";
		cin >> A[cnt].dd;
		cin >> A[cnt].mm;
		cin >> A[cnt].yy;
		cout << "nhap so luong: ";
		cin >> A[cnt].SoLuong;
		cout << "nhap don gia: ";
		cin >> A[cnt].DonGia;
		ThanhTienFunc(A, cnt);
		SV Mid;
		for (int i = 0; i < cnt; i++)

		{
			if (A[i].SoLuong > A[cnt].SoLuong)
			{
				Mid = A[i];
				A[i] = A[cnt];
				A[cnt] = Mid;
			}
		}
		cout << endl << "	Danh sach sau khi chen: ";
		indanhsach(A, cnt);
	}
chenDonGia:
	{
		sapXepTangDanDonGia(A, cnt);
		cnt++;
		cout << endl << "*Nhap thong tin don nhap hang can chen: " << endl;
		cout << "nhap ma hang: ";
		cin.ignore();
		fflush(stdin);
		getline(cin, A[cnt].MaHang);
		cout << "nhap ten hang: ";
		fflush(stdin);
		getline(cin, A[cnt].TenHang);
		cout << "nhap don vi tinh: ";
		fflush(stdin);
		getline(cin, A[cnt].DonViTinh);
		cout << "nhap ngay nhap hang: ";
		cin >> A[cnt].dd;
		cin >> A[cnt].mm;
		cin >> A[cnt].yy;
		cout << "nhap so luong: ";
		cin >> A[cnt].SoLuong;
		cout << "nhap don gia: ";
		cin >> A[cnt].DonGia;
		ThanhTienFunc(A, cnt);
		SV Mid2;
		for (int i = 0; i < cnt; i++)

		{
			if (A[i].DonGia > A[cnt].DonGia)
			{
				Mid2 = A[i];
				A[i] = A[cnt];
				A[cnt] = Mid2;
			}
		}
		cout << endl << "	Danh sach sau khi chen: ";
		indanhsach(A, cnt);
	}
}

//void xoa(SV a[], int& n)
//{
//	cout << endl
//		<< endl
//		<< "XOA PHAN TU: ";
//	int pos;
//	cout << "Xoa phan tu thu:";
//	cin >> pos;
//	// Mang rong, khong the xoa.
//	if (n <= 0)
//	{
//		return;
//	}
//	// Neu pos <= 0 => Xoa dau
//	if (pos < 0)
//	{
//		pos = 0;
//	}
//	// Neu pos >= n => Xoa cuoi
//	else if (pos >= n)
//	{
//		pos = n - 1;
//	}
//	// Dich chuyen mang
//	for (int i = pos + 1; i < n; i++)
//	{
//		a[i] = a[i + 1];
//	}
//	// Giam so luong phan tu sau khi xoa.
//	--n;
//	cout << endl;
//
//	cout << "Mang sau khi xoa" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		xuat(a, i);
//	}
//}
void xoa(SV a[], int& n, int pos)
{


	// Mang rong, khong the xoa.
	if (n <= 0)
	{
		return;
	}
	// Neu pos <= 0 => Xoa dau
	if (pos < 0)
	{
		pos = 0;
	}
	// Neu pos >= n => Xoa cuoi


	// Dich chuyen mang
	for (int i = pos; i <= n; i++)
	{
		a[i] = a[i + 1];
	}
	// Giam so luong phan tu sau khi xoa.
	--n;
}
void xoaMH(SV a[], int& n)
{
	cout << endl << "Tien hanh xoa cac don nhap hang: " << endl;
	//in tittle
	const char separator = ' ';
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------";
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(8) << setfill(separator) << "--------";
	cout << "+" << left << setw(15) << setfill(separator) << "---------------"
		<< "|" << endl;

	cout << "|" << left << setw(8) << setfill(separator) << "MaHang";
	cout << "|" << left << setw(15) << setfill(separator) << "TenHang";
	cout << "|" << left << setw(15) << setfill(separator) << "DonViTinh";
	cout << "|" << left << setw(15) << setfill(separator) << "Ngay";
	cout << "|" << left << setw(8) << setfill(separator) << "SoLuong";
	cout << "|" << left << setw(8) << setfill(separator) << "DonGia";
	cout << "|" << left << setw(15) << setfill(separator) << "ThanhTien"
		<< "|" << endl;



	for (int i = 1; i <= n; i++)
	{
		std::string s = a[i].MaHang;
		if (s.rfind("mh1", 0) == 0)
		{
			if (a[i].DonViTinh == "Hop")
			{
				xuatXoa(a, i);
				xoa(a, n, i);
				--i;
			}
		}
	}
	fstream d;
	d.open("hang.txt", ios::out | ios::trunc);
	int i;
	for (i = 1; i < n; i++)
	{
		d << A[i].MaHang << ", " << A[i].TenHang << ", " << A[i].DonViTinh << ", " << A[i].dd << "/ " << A[i].mm << "/ " << A[i].yy << ", " << A[i].SoLuong << ", " << A[i].DonGia << "\n";

	}
	d << A[i].MaHang << ", " << A[i].TenHang << ", " << A[i].DonViTinh << ", " << A[i].dd << "/ " << A[i].mm << "/ " << A[i].yy << ", " << A[i].SoLuong << ", " << A[i].DonGia;

	d.close();
	cout << endl << endl << "Danh sach sau khi xoa: " << endl;
	for (int i = 1; i <= n; i++)
		xuat(a, i);

	system("pause");
}

void bosung(SV A[], int& cnt)
{
	cout << endl
		<< endl
		<< "BO SUNG MOT DON NHAP HANG: " << endl
		<< endl;
	cnt++;
	cout << "nhap ma hang: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, A[cnt].MaHang);
	cout << "nhap ten hang: ";
	fflush(stdin);
	getline(cin, A[cnt].TenHang);
	cout << "nhap don vi tinh: ";
	fflush(stdin);
	getline(cin, A[cnt].DonViTinh);
	cout << "nhap ngay nhap hang: ";
	cin >> A[cnt].dd;
	cin >> A[cnt].mm;
	cin >> A[cnt].yy;
	cout << "nhap so luong: ";
	cin >> A[cnt].SoLuong;
	cout << "nhap don gia: ";
	cin >> A[cnt].DonGia;
	ThanhTienFunc(A, cnt);

	fstream f;
	f.open("hang.txt", ios::out | ios::app);
	f << "\n" << A[cnt].MaHang << ", " << A[cnt].TenHang << ", " << A[cnt].DonViTinh << ", " << A[cnt].dd << "/ " << A[cnt].mm << "/ " << A[cnt].yy << ", " << A[cnt].SoLuong << ", " << A[cnt].DonGia;
	f.close();

	cout << endl
		<< "Danh sach sau khi da bo sung: " << endl;
	for (int i = 1; i <= cnt; i++)
	{
		xuat(A, i);
	}
	//system("cls");
	system("pause");
}

void inthongke(SV A[], int cnt)
{
	SV B[100];
	for (int i = 1; i <= cnt; i++)
		B[i] = A[i];

	//sap xem nam:
	SV temp[10];
	for (int i = 1; i <= cnt - 1; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			if (B[i].yy > B[j].yy)
			{
				temp[1] = B[i];
				B[i] = B[j];
				B[j] = temp[1];
			}
		}
	}
	//sap xep thang:
	//cout << "sap xep thang:";
	for (int i = 1; i <= cnt - 1; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			if (B[i].yy == B[j].yy)
			{
				if (B[i].mm > B[j].mm)
				{
					temp[1] = B[i];
					B[i] = B[j];
					B[j] = temp[1];
				}
			}
		}
	}
	//sap xep ngay:
	//cout << "sap xep ngay:";
	for (int i = 1; i <= cnt - 1; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			if (B[i].mm == B[j].mm && B[i].yy == B[j].yy)
			{
				if (B[i].dd > B[j].dd)
				{
					temp[1] = B[i];
					B[i] = B[j];
					B[j] = temp[1];
				}
			}
		}
	}
	cout << endl
		<< "	Danh sach da sap xep theo Ngay Thang tang dan: " << endl;
	indanhsach(B, cnt);
	cout << endl
		<< "	BANG THONG KE THEO NGAY:" << endl;

	int i = 1, j = 2;
	bool b = true, test = false;
	long int TotalMoneyInaDay[100];
	//TotalMoneyInaDay[1] = ThanhTienFunc(B, 1);
	long int tableFormat = 0;
	do
	{


		if (test == false)
			TotalMoneyInaDay[i] = B[i].ThanhTien;
		//if (test == true) cout << "test = true";
		//cout << "total= " << TotalMoneyInaDay[i];

		if (B[i].dd == B[j].dd && B[i].mm == B[j].mm && B[i].yy == B[j].yy)
		{
			//cout << "bang nhau" << endl;

			//cout << B[i].dd << " " << B[i].mm << " " << B[i].yy << "  ";
			TotalMoneyInaDay[i] = TotalMoneyInaDay[i] + B[j].ThanhTien;
			j++;
			test = true;
		}

		else
		{
			string dStr, mStr, yStr;
			const char separator = ' ';
			const int nameWidth = 10;
			const int numWidth = 12;
			cout << "+" << left << setw(15) << setfill(separator) << "---------------";

			cout << "+" << left << setw(15) << setfill(separator) << "---------------"
				<< "|" << endl;
			if (tableFormat == 0)
			{
				cout << "|" << left << setw(15) << setfill(separator) << "Ngay";
				cout << "|" << left << setw(15) << setfill(separator) << "Tong tien"
					<< "|" << endl;
				cout << "+" << left << setw(15) << setfill(separator) << "---------------";

				cout << "+" << left << setw(15) << setfill(separator) << "---------------"
					<< "|" << endl;
				tableFormat++;
			}

			string dStr2, mStr2, yStr2;

			ostringstream dConvert2, mConvert2, yConvert2;
			dConvert2 << B[i].dd;
			mConvert2 << B[i].mm;
			yConvert2 << B[i].yy;

			dStr2 = dConvert2.str();
			yStr2 = yConvert2.str();
			mStr2 = mConvert2.str();

			string date2 = dStr2 + "/" + mStr2 + "/" + yStr2;

			cout << "|" << left << setw(15) << setfill(separator) << date2;
			cout << "|" << left << setw(15) << setfill(separator) << thousandSeparator(TotalMoneyInaDay[i]) << "|" << endl;



			//cout << "|" << left <<  setfill(separator) << B[i].dd << "/" << B[i].mm << "/" << B[i].yy;
			//cout << "|" << left <<  setfill(separator) << TotalMoneyInaDay[i] << "|" << endl;

			i = j;
			j++;
			test = false;
			//cout << "test = false" << endl;
		}

	} while (j <= cnt + 1);

	system("pause");
}
int timkiem(SV A[], int cnt)
{
	cout << endl;
	int tim;
	cout << "\n|--- TIM KIEM ---------------------------------|";
	cout << "\n| 1. tim theo ma hang.                         |";
	cout << "\n| 2. tim theo ten hang.                        |";
	cout << "\n| 3. tim theo don vi tinh.                     |";
	cout << "\n| 4. tim theo ngay nhap.                       |";
	cout << "\n| 5. tim theo don gia.                         |";
	cout << "\n|----------------------------------------------|";
	cout << "\n Chon: ";
	cin >> tim;
	if (tim == 1)
		goto timkiemmahang;
	else if (tim == 2)
		goto timkiemtenhang;
	else if (tim == 3)
		goto timkiemdvtinh;
	else if (tim == 4)
		goto timkiemngay;
	else if (tim == 5)
		goto timkiemdongia;

timkiemmahang:
	{
		cout << endl
			<< endl
			<< "TIM KIEM THEO MA HANG: ";
		string mahang;
		int yup = 0;
		//fflush(stdin);
		cout << endl
			<< "nhap ma hang can tim: ";
		cin.ignore();
		getline(cin, mahang);
		for (int i = 1; i <= cnt; i++)
		{
			if (mahang == A[i].MaHang)
			{
				xuat(A, i);
				yup++;
			}
		}
		if (!yup)
			cout << endl
			<< "ma hang nay khong ton tai trong danh sach!";
		cout << endl
			<< "--------------------------------" << endl;

		system("pause");
		return 0;
	}
timkiemtenhang:
	{
		cout << endl
			<< endl
			<< "TIM KIEM THEO TEN HANG: ";
		string tenhang;
		int yup = 0;
		cin.ignore();
		cout << endl
			<< "nhap ten hang can tim: ";
		getline(cin, tenhang);
		for (int i = 1; i <= cnt; i++)
		{
			if (tenhang == A[i].TenHang)
			{
				xuat(A, i);
				yup++;
			}
		}
		if (!yup)
			cout << endl
			<< "ten hang nay khong ton tai trong danh sach!";
		cout << endl
			<< "--------------------------------" << endl;
		system("pause");
		return 0;
	}
timkiemdvtinh:
	{
		cout << endl
			<< endl
			<< "TIM KIEM THEO DON VI TINH ";
		string dvtinh;
		int yup = 0;
		cin.ignore();
		cout << endl
			<< "nhap don vi tinh cua loai hang can tim: ";
		getline(cin, dvtinh);
		for (int i = 1; i <= cnt; i++)
		{
			if (dvtinh == A[i].DonViTinh)
			{
				xuat(A, i);
				yup++;
			}
		}
		if (!yup)
			cout << endl
			<< "khong ton tai loai hang co don vi tinh nay trong danh sach!";
		cout << endl
			<< "--------------------------------" << endl;
		system("pause");
		return 0;
	}
timkiemngay:
	{
		cout << endl
			<< endl
			<< "TIM KIEM THEO NGAY NHAP HANG: ";
		int finddate = cnt + 10, yup = 0;
		cin.ignore();
		cout << endl
			<< "nhap ngay nhap kho cua loai hang can tim: ";
		cin >> A[finddate].dd;
		cin >> A[finddate].mm;
		cin >> A[finddate].yy;
		for (int i = 1; i <= cnt; i++)
		{
			if (A[finddate].dd == A[i].dd && A[finddate].mm == A[i].mm && A[finddate].yy == A[i].yy)
			{
				xuat(A, i);
				yup++;
			}
		}
		if (!yup)
			cout << endl
			<< "khong ton tai mat hang co ngay nhap nay trong danh sach!" << endl;
		cout << "--------------------------------" << endl;
		system("pause");
		return 0;
	}
timkiemdongia:
	{
		cout << endl
			<< endl
			<< "TIM KIEM THEO DON GIA";
		int dongia;
		int yup = 0;
		cin.ignore();
		cout << endl
			<< "nhap don gia cua loai hang can tim: ";
		cin >> dongia;
		for (int i = 1; i <= cnt; i++)
		{
			if (dongia == A[i].DonGia)
			{
				xuat(A, i);
				yup++;
			}
		}
		if (!yup)
			cout << endl
			<< "khong ton tai mat hang co don gia nay trong danh sach!" << endl;

		system("pause");
		return 0;
	}
	system("pause");
}

int main()
{

	ifstream myFile("hang.txt");
	int cnt = 0;
	string myText;
	while (getline(myFile, myText))
		cnt++;
	myFile.close();
	myFile.open("hang.txt");

	for (int i = 1; i <= cnt; i++)
	{
		docdulieuSV(myFile, C, i);

	}
	for (int i = 1; i <= cnt; i++)
		doiIntt(C, A, i);
	for (int i = 1; i <= cnt; i++)
	{
		ThanhTienFunc(A, i);

	}





	//MENU:
	int task;
	do
	{
		system("cls");
		cout << "\n|--------------------------------------------|";
		cout << "\n| DO AN MON HOC GIAI THUAT & LAP TRINH       |";
		cout << "\n| GVHD: Do Thi Tuyet Hoa                     |";
		cout << "\n| SVTH:                                      |";
		cout << "\n|      1. Nguyen Dang Hoang Y                |";
		cout << "\n|      2. Mai Tan Sang                       |";
		cout << "\n|--------------------------------------------|";
		cout << "\n\n";
		cout << "\n		|--- MENU -----------------------------------------------------------------------------------|";
		cout << "\n		| 1. In danh sach ta ca don nhap hang                                                        |";
		cout << "\n		| 2. Bo sung mot don nhap hang                                                               |";
		cout << "\n		| 3. Tim kiem don nhap hang                                                                  |";
		cout << "\n		| 4. In bang thong ke cac ngay trong thang                                                   |";
		cout << "\n		| 5. Sap xep danh sach don nhap hang                                                         |";
		cout << "\n		| 6. Xoa mot don nhap hang                                                                   |";
		cout << "\n		| 0. Thoat                                                                                   |";
		cout << "\n		|--------------------------------------------------------------------------------------------|";
		cout << "\n\t   Chon: ";
		cin >> task;
		if (task == 1)
			indanhsach(A, cnt);
		else if (task == 2)
		{
			bosung(A, cnt);
		}
		else if (task == 3)
			timkiem(A, cnt);
		else if (task == 4)
			inthongke(A, cnt);
		else if (task == 5)
		{
			int sort;
			cout << "\n|--- SAP XEP ----------------------------------|";
			cout << "\n| 1. Tang dan theo Don Gia                     |";
			cout << "\n| 2. Giam dan theo Don Gia                     |";
			cout << "\n| 3. Tang dan theo So Luong                    |";
			cout << "\n| 4. Giam dan theo So Luong                    |";
			cout << "\n| 5. Tang dan theo Ngay Nhap                   |";
			cout << "\n|----------------------------------------------|";
			cout << "\n Chon: ";
			cin >> sort;
			cout << endl;
			if (sort == 1) sapXepTangDanDonGia(A, cnt);
			else if (sort == 2) sapXepGiamDanDonGia(A, cnt);
			else if (sort == 3) sapXepTangDanSoLuong(A, cnt);
			else if (sort == 4) sapXepGiamDanSoLuong(A, cnt);
			else if (sort == 5) sapXepTangDanNgayNhap(A, cnt);

		}

		else if (task == 6)
		{

			indanhsach(A, cnt);
			cout << endl << "Ban muon xoa don nhap hang thu: ";
			int pos;
			cin >> pos;
			xoa(A, cnt, pos);
			cout << endl << "Danh sach sau khi xoa don nhap hang thu " << pos << ":";
			indanhsach(A, cnt);
		}


		else if (task == 7)
			xoaMH(A, cnt);
		else if (task == 8)
			chen(A, cnt);
		else if (task == 0)
			break;
	} while (task);



	return 0;
}