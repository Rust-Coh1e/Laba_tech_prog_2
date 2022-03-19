#include <iostream>
#include "Cicle.h"

using namespace std;

Cicle::Cicle()
{
	size = 0;
	last = nullptr;
	first = nullptr;
}

Cicle::Cicle(int a)
{
	Node* new_unit = new Node;
	new_unit->data = a;
	new_unit->prev = last;
	first = new_unit;
	last = nullptr;
	size=1;
}

Cicle::~Cicle()
{
	while (size > 0)
	{
		Node* temp = last;
		last = temp->prev;
		delete temp;
		size--;
	}
}

Cicle::Cicle(const Cicle& Cicle_copy) : size(Cicle_copy.size)
{
	int* buff = new int[Cicle_copy.size]; //вводим буферный массив, в котором будем хранить наши числа новой очереди
	Node* el_queue = Cicle_copy.last; //новая переменная

	for (int i = 0; i <= Cicle_copy.size - 1; i++)
	{	
		buff[i] = el_queue->data; 
		el_queue = el_queue->prev; 
	}

	for (int i = 0; i < Cicle_copy.size; i++)
		this->push(buff[i]);
	delete[] buff; 
}


Node* Cicle::get_last()
{
	return last;
}

void Cicle::printCicle()
{
	if (size == 1 ) { cout << first->data << endl; return; }

	Node* tmp = last;
	
	while (tmp->prev != first)
	{
		cout << tmp->data << " -> ";
		tmp = tmp->prev;
	}
	cout << tmp->data << " -> ";
	cout << first->data << endl;
}

bool Cicle::operator! () const
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Cicle::push(int a)
{
	
	Node* new_unit = new Node;
	if (size == 1)
	{
		new_unit->data=a;
		new_unit->prev = first;
		last = new_unit;
		size++;
		return;
	}
	new_unit->prev = last;
	last = new_unit;
	last->data = a;
	first->prev = last;
	size++;
}

Cicle& Cicle::operator ++()
{
	int tmp;
	cout << "Enter value" << endl;
	cin >> tmp;
	push(tmp);
	return *this;
}

int Cicle::pop()
{
	
	int res;
	Node* tmp = first;
	res = tmp->data;
	if (size == 1)
	{
		last == nullptr;
		first == nullptr;
		size = 0;
		return res;
	}
	tmp = last;
	while (tmp->prev != first)
	{
		tmp = tmp->prev;
	}

	delete tmp->prev;
	tmp->prev = last;
	first = tmp;
	push(res);
	size--;
	return res;
}

int Cicle::del()
{
	int res;
	Node* tmp = first;
	res = tmp->data;
	if (size == 1)
	{
		last == nullptr;
		first == nullptr;
		size = 0;
		return res;
	}
	tmp = last;
	while (tmp->prev != first)
	{
		tmp = tmp->prev;
	}

	delete tmp->prev;
	tmp->prev = last;
	first = tmp;
	size--;
	return res;
}

void operator-- (Cicle& C)
{
	if (C.size == 0)
	{
		cout << "queue is empty" << endl;
	}
	cout << C.pop() << endl;
}

Cicle& Cicle::operator--(int)
{
	if (size == 0)
	{
		cout << "queue is empty" << endl;
	}
	cout << del() << " -> " << del() << endl;
	return *this;

}

void operator++ (Cicle& C, int)
{
	int a, b;
	cout << "Enter values\n";
	cin >> a >> b;
	C.printCicle();
	C.push(a);
	C.push(b);
	C.printCicle();
}

