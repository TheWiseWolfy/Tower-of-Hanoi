#pragma once
#include "Queue.h"

/*
class turn {
public:
	Stack<int> inel;
	void populeaza(int);
	void impinge(int);
	int trage(void);
};
*/

void mutaUnInel(Stack<int> *tur, int, int);
void afiseazaTurnuri(Stack<int> &tur);
void afiseaza(int, int);
void mutaGramezi(Stack<int>* tur, int, int, int, int);
