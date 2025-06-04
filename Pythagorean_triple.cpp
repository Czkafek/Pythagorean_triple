#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

long long nwd(long long a, long long b) {
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}
/*
class Triple {
public:
	int a, b, c;
	Triple() { a = 0; b = 0; c = 0; }
	Triple(int a, int b, int c) : Triple() {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};
*/

struct Triple {
	long long a, b, c;

	Triple(long long a, long long b, long long c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

int main()
{
	setlocale(LC_CTYPE, "Polish");

	long long start, stop;

	cout << "Podaj początek przedziału: ";
	cin >> start;
	cout << "Podaj koniec przedziału: ";
	cin >> stop;

	// BRUTEFORCE
	/*
	bool isFound = false;

	for (int a = start; a < stop + 1; a++) {
		int aSqr = a * a;
		for (int b = a+1; b < stop + 1; b++) {
			int sum = aSqr + b * b;
			int c = b;
			do {
				c++;
				if (c * c == sum) {
					cout << "a= " << a << ", b=" << b << ", c=" << c << endl;
					isFound = true;
				}
			} while (c * c < sum);
		}
	}
	if (!isFound)
		cout << "W tym przedziale nie znaleziono żadnej trójki pitagorejskiej";
	*/

	// EUKLIDES - ARRAY + CLASS
	/*
	bool isFound = false;
	Triple foundTriples[10000];
	int count = 0;

	for (long long m = 2; m <= floor(sqrt(stop + 1)); m++) {
		long long mSqr = m * m;
		for (long long n = 1; n < m; n++) {
			if (nwd(m, n) != 1 || (n + m) % 2 != 1) continue;
			long long a = mSqr - n * n;
			long long b = 2 * m * n;
			if (a > stop || b > stop) continue;
			long long k = 1;
			while (true) {
				if (k * a > stop || k * b > stop) break;
				if (k * a > start - 1 && k * b > start - 1) {
					//cout << "a= " << a * k << ", b=" << b * k << ", c=" << (mSqr + n * n) * k << endl;
					Triple triple(k*a, k*b, (mSqr + n * n) * k);
					foundTriples[count++] = triple;
					isFound = true;
				}
				k++;
			}
		}
	}
	if (isFound) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count-i-1; j++) {
				if (foundTriples[j].a > foundTriples[j + 1].a) {
					int tmpA = foundTriples[j].a, tmpB = foundTriples[j].b, tmpC = foundTriples[j].c;
					foundTriples[j].a = foundTriples[j + 1].a;
					foundTriples[j].b = foundTriples[j + 1].b;
					foundTriples[j].c = foundTriples[j + 1].c;
					foundTriples[j + 1].a = tmpA;
					foundTriples[j + 1].b = tmpB;
					foundTriples[j + 1].c = tmpC;
				}
				else if (foundTriples[j].a == foundTriples[j + 1].a) {
					if (foundTriples[j].b > foundTriples[j + 1].b) {
						int tmpB = foundTriples[j].b, tmpC = foundTriples[j].c;
						foundTriples[j].b = foundTriples[j + 1].b;
						foundTriples[j].c = foundTriples[j + 1].c;
						foundTriples[j + 1].b = tmpB;
						foundTriples[j + 1].c = tmpC;
					}
				}
			}
		}
		for (int i = 0; i < count; i++) {
			cout << "a= " << foundTriples[i].a << ", b=" << foundTriples[i].b << ", c=" << foundTriples[i].c << endl;
		}
	}
	else
		cout << "W tym przedziale nie znaleziono żadnej trójki pitagorejskiej";
	*/

	// EUKLIDES - STRUCT + VECTOR
	bool isFound = false;
	vector<Triple> foundTriples;

	for (long long m = 2; m <= floor(sqrt(stop + 1)); m++) {
		long long mSqr = m * m;
		for (long long n = 1; n < m; n++) {
			if (nwd(m, n) != 1 || (n + m) % 2 != 1) continue;
			long long a = mSqr - n * n;
			long long b = 2 * m * n;
			if (a > stop || b > stop) continue;
			long long k = 1;
			while (true) {
				if (k * a > stop || k * b > stop) break;
				if (k * a > start - 1 && k * b > start - 1) {	
					foundTriples.push_back({ k * a, k * b, (mSqr + n * n) * k });
					isFound = true;
				}
				k++;
			}
		}
	}
	if (isFound) {
		for (int i = 0; i < foundTriples.size(); i++) {
			for (int j = 0; j < foundTriples.size() - i - 1; j++) {
				if (foundTriples[j].a > foundTriples[j + 1].a) {
					int tmpA = foundTriples[j].a, tmpB = foundTriples[j].b, tmpC = foundTriples[j].c;
					foundTriples[j].a = foundTriples[j + 1].a;
					foundTriples[j].b = foundTriples[j + 1].b;
					foundTriples[j].c = foundTriples[j + 1].c;
					foundTriples[j + 1].a = tmpA;
					foundTriples[j + 1].b = tmpB;
					foundTriples[j + 1].c = tmpC;
				}
				else if (foundTriples[j].a == foundTriples[j + 1].a) {
					if (foundTriples[j].b > foundTriples[j + 1].b) {
						int tmpB = foundTriples[j].b, tmpC = foundTriples[j].c;
						foundTriples[j].b = foundTriples[j + 1].b;
						foundTriples[j].c = foundTriples[j + 1].c;
						foundTriples[j + 1].b = tmpB;
						foundTriples[j + 1].c = tmpC;
					}
				}
			}
		}
		for (int i = 0; i < foundTriples.size(); i++) {
			cout << "a=" << foundTriples[i].a << ", b=" << foundTriples[i].b << ", c=" << foundTriples[i].c << endl;
		}
	}
	else
		cout << "W tym przedziale nie znaleziono żadnej trójki pitagorejskiej";
	
	_getch();
}