#pragma once

#define DIMMAX 16

template <typename Atom>
class Stack {
	Atom* vec;			           //vector stocare elemente
	int capacity;		          //marimea actuala a cozii
	int head;		         // pozitii relevante
	int count;      			//spatii ocupate
public:
	Stack(int size = DIMMAX);   //constructor
	~Stack();					//destructor

	//Stack(const Stack& s2);        ??

	void put(Atom n);
	void skip();
	Atom peek();
	int size();
	bool isFull();
	bool isEmpty();
};

//Constructor
template<typename Atom>
inline Stack<Atom>::Stack(int size) {
	vec = new Atom[size];
	capacity = size;
	head = 0;
	count = 0;
}

//Destructor 
template<typename Atom>
inline Stack<Atom>::~Stack() {
	delete[] vec;

}

/*
template<typename Atom>
inline Stack<Atom>::Stack(const Stack& s2)
{
	vec = new Atom[s2.capacity];
	vec = s2.vec;
	capacity = s2.capacity; 
	head = s2.head;
	count = s2.count;
}
*/

//Important
template<typename Atom>

void Stack<Atom>::put(Atom n) {
	// verifica daca mai ai spatiu

	if (isFull()) {
		//Daca nu mai ai, fa mai mult ,exponential
		std::cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	head = (head + 1) % capacity;
	vec[head] = n;
	count++;
}

template<typename Atom>
void Stack<Atom>::skip(){
	// check for queue underflow

	if (isEmpty())
	{
		std::cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	//std::cout << "Removing " << vec[head] << '\n';
	head = (head - 1) % capacity;
	count--;
}


template<typename Atom>
Atom Stack<Atom>::peek(){

	if (isEmpty()){
		std::cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return vec[head];
}

//Utility
template<typename Atom>
inline int Stack<Atom>::size(){
	return count;
}

template<typename Atom>
bool Stack<Atom>::isFull() {
	return capacity == count;
}

template<typename Atom>
bool Stack<Atom>::isEmpty(){
	return (count == 0);
}
