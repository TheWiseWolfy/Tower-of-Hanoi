#include <iostream>

#include "Header.h"
#include "Queue.h"

using namespace std;
///Muta un grup de inel de pe un turn pe altul

void mutaGramezi(Stack<int>* tur ,int sursa, int auxiliar, int destinatie, int nrInele) {

	if (nrInele == 1) {
		mutaUnInel(tur,sursa, destinatie);
	}
	else {
		mutaGramezi(tur,sursa, destinatie, auxiliar, nrInele - 1);
		mutaUnInel(tur,sursa, destinatie);
		mutaGramezi(tur,auxiliar, sursa, destinatie, nrInele - 1);
	}
}

///Muta un inel de pe un turn pe altul

void mutaUnInel(Stack<int> *tur,int sursa, int destinatie) {
	int a = tur[sursa].peek();
	tur[sursa].skip();
	tur[destinatie].put(a);

	cout << "In aceasta iteratie.\nTurnul 0 devine\n";
	afiseazaTurnuri(tur[0]);
	cout << "Turnul 1 devine\n";
	afiseazaTurnuri(tur[1]);
	cout << "Turnul 2 devine\n";
	afiseazaTurnuri(tur[2]);
	cout << "\n\n\n";
}

///Afiseaza starea inelelor si turnurilor

void afiseazaTurnuri(Stack<int> &tur) {
	int a = 0, numarInele, size;

	//Stack<int> tur(source);
	Stack<int> temp(tur.size() +1 );
 
	if (!tur.isEmpty()) {
		numarInele = tur.size();

		for (int f1 = 0; f1 < numarInele ; ++f1) {

			a = tur.peek();
			temp.put(a);
			tur.skip();

			afiseaza(' ', 13 - a);
			afiseaza('=', a * 2);
			afiseaza(' ', 13 - a);

			cout << endl;
		}
		cout << endl;
	}
	size= temp.size();
	for (int f1 = 0; f1 < size; ++f1) {
		tur.put(temp.peek());
		temp.skip();


	}


//	cin.get();
}

///Afiseaza o linie

void afiseaza(int simbol, int inel) {
	for (int f1 = 0; f1<inel; ++f1) {
		cout << (char)simbol;
	}
}