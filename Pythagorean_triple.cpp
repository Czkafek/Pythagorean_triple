#include <iostream>
#include <conio.h>
#include <cmath>
#include <math.h>
using namespace std;

int nwd(int a, int b) {
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int main()
{
	setlocale(LC_CTYPE, "Polish");

	int start, stop;

	cout << "Podaj początek przedziału: ";
	cin >> start;
	cout << "Podaj koniec przedziału: ";
	cin >> stop;

	// BRUTEFORCE
	/*
	for (int a = start; a < stop + 1; a++) {
		int aSqr = a * a;
		for (int b = a; b < stop + 1; b++) {
			int sum = aSqr + b * b;
			int c = b;
			do {
				if (++c * c == sum) {
					cout << "W tym przedziale znajduje się trójka pitagorejska:";
					cout << "a= " << a << ", b=" << b << ", c=" << c << endl;
					_getch();
					return 0;
				}
			} while (c * c < sum);
		}
	}
	cout << "W tym przedziale nie znaleziono żadnej trójki pitagorejskiej";
	*/

	for (int m = 2; m <= floor(sqrt(stop + 1)); m++ ) {
		int mSqr = m * m;
		for (int n = 1; n < m; n++) {
			if (nwd(m, n) != 1 || (n + m) % 2 != 1) break;
			int a = mSqr - n * n;
			int b = 2 * m * n;
			if (a > stop || b > stop) break;
			int k = 1;
			while (true) {
				if (k * a > stop || k * b > stop) break;
				if (k * a > start-1 && k * b > start-1) {
					cout << "Znaleziono w tym przedziale trójkę pitagorejską: ";
					cout << "a= " << a*k << ", b=" << b*k << ", c=" << (mSqr + n*n) * k << endl;
					_getch();
					return 0;
				}
				k++;
			}
		}
	} 
	cout << "W tym przedziale nie znaleziono żadnej trójki pitagorejskiej";




	_getch();
}