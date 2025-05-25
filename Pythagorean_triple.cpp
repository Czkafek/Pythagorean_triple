#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Polish");

	int start, stop;

	cout << "Podaj początek przedziału: ";
	cin >> start;
	cout << "Podaj koniec przedziału: ";
	cin >> stop;

	for (int i = start; i < stop + 1; i++) {
		long long int sqrI = 1LL * i * i;
		for (int j = i; j < stop + 1; j++) {
			long long sum = sqrI + 1LL * j * j;
			long long root = (long long)round(sqrt((double)sum));
			if (root * root == sum) {
				cout << i << ", " << j << ", " << root << endl;
				_getch();
				return 0;
			}
		}
	}
	cout << "W tym przedziale nie ma żadnej trójki pitagorejskiej";



	
	_getch();
}