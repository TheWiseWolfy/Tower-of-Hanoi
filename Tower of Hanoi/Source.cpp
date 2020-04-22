#include <iostream>

#include "Header.h"
#include "Queue.h"

using namespace std;

int main()
{
	Stack<int> tur[3];

	int numarInele = 6;

	for (int f1 = 0; f1 < numarInele; ++f1) {
		tur[0].put(numarInele - f1);

	}
	cout << "Turnul 0 devine\n";
	afiseazaTurnuri(tur[0]);
	cout << "Turnul 1 devine\n";
	afiseazaTurnuri(tur[1]);
	cout << "Turnul 2 devine\n";
	afiseazaTurnuri(tur[2]);
	cout<< "\n\n\n";

	mutaGramezi(tur, 0, 1, 2, numarInele);

	cout << "Turnul 0 devine\n";
	afiseazaTurnuri(tur[0]);
	cout << "Turnul 1 devine\n";
	afiseazaTurnuri(tur[1]);
	cout << "Turnul 2 devine\n";
	afiseazaTurnuri(tur[2]);

	return 0;
}
