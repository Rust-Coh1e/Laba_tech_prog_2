#pragma once

struct Node
{
	int data = 0;
	Node* prev = nullptr;
};

class Cicle
{
private:
	Node* last = nullptr;
	Node* first = nullptr;
protected:
	int size = 0;
public:
	Cicle();
	explicit Cicle(int a);
	~Cicle();
	Cicle(const Cicle& real_copy);

	Node* get_last();
	int get_size() const;
	//int set_size(int& value);
	void push(int a);
	int pop();
	int del();

	void printCicle();

	bool operator! () const;
	Cicle& operator ++(); //префиксная форма метод добавления в очередь
	friend void operator --(Cicle& C);// извлечение элемента из очереди
	friend void operator++(Cicle& C, int);// Добавление двух 
	Cicle& operator--(int);// удаление двух элементов 

};
