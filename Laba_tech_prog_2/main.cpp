#include <iostream>
#include "Cicle.h"
#include "int.h"

using namespace std;
int main()
{

	int cicle_size = 0, value = 0; //переменные размера стека и вводимых данных
	int flag = 1, c;

	///////////////////////////////////////////////////////ЗАДАНИЕ №1

	
	cout << "First task\nEnter size\n";
	cin >> cicle_size;

	
	cout << "Enter values: " << endl;
	cin >> value;
	Cicle st(value);
	for (int i = 0; i < cicle_size-1; i++)
	{
		cin >> value;
		st.push(value);
	}
	value = 0;

	while (flag == 1)
	{
		cout << "Select a cyclic queue operation:" << endl;
		cout << "1 - Add new element"<< endl;
		cout << "2 - Pop" << endl;
		cout << "3 - Print" << endl;
		cout << "4 - Prefix operator ++ (push)" << endl;
		cout << "5 - Postfix operator ++ (push x2)" << endl;
		cout << "6 - Prefix operator -- (pop)" << endl;
		cout << "7 - Postfix operator -- (delete 2 nodes)" << endl;
		cout << "8 - Delete 1 node" << endl;
		cout << "0 - Second task" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: 
			system("cls");
			cout << "Enter value: " << endl;
			cin >> value;
			st.push(value);
			cicle_size++;
			cout << "Value added\n " << endl;
			break;
		case 2: 
			if (!st)
			{
				cout << "Queue is Empty\n ";
				break;
			}
			else
			{
				system("cls");
				value = st.pop();
				cout << "Extracted element: " << value << endl;
			}
			break;
		case 3: 
			if (!st)
			{
				cout << "Queue is Empty\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st.printCicle();
				cout << "\n";
			}
			break;
		case 4: 
			if (!st)
			{
				cout << "Queue is Empty\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cicle_size++;
				++st;
				cout << "The operation was successful! The resulting queue: " << endl;
				st.printCicle();
				cout << "\n";
			}
			break;
		case 5: 
			if (!st)
			{
				cout << "Queue is Empty\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st++;
				cicle_size+=2;
				cout << "The operation was successful! The resulting queue: " << endl;
				st.printCicle();
				cout << "\n";
			}
			break;
		case 6: 
			if (!st)
			{
				cout << "Queue is Empty\n" << endl;
				break;
			}
			else
			{
				system("cls");
				--st;
				cicle_size--;
				cout << "The operation was successful! The resulting queue: " << endl;
				st.printCicle();
				cout << "\n";
			}
			break;
		case 7: 
			if (!st)
			{
				cout << "Queue is Empty\n" << endl;
				break;
			}
			else
			{
				system("cls");
				if (cicle_size == 1)
				{
					cout << "There is one item in the queue, the operation cannot be performed\n";
					break;
				}
				
				if (cicle_size == 2)
				{
					st--;
					cicle_size -= 2;
					cout << "The operation was successful! The resulting queue: " << endl;
					cout << "Queue is Empty\n" << endl;
					break;
				}
				
				st--;
				cicle_size -= 2;
				cout << "The operation was successful! The resulting queue: " << endl;
				st.printCicle();
				cout << "\n";
			}
			break;
		case 8:
			if (!st)
			{
				cout << "Queue is Empty\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st.del();
				cicle_size--;
				cout << "The operation was successful! The resulting queue: " << endl;
				if (!st)
				{
					cout << "Queue is Empty\n" << endl;
					break;
				}
				st.printCicle();
				cout << "\n";
			}
			break;

		case 0: //0 - Выход
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}
	st.~Cicle();
	/////////////////////////////////////////////////////////ЗАДАНИЕ №2
	system("cls");

	int input_num1, input_num2;
	Int num1, num2, res(0.0);

	cout << "Task #2 - integer\n" << endl;
	flag = 1;

	while (flag == 1)
	{
		cout << "Choose which operations to perform with the class of real numbers:" << endl;
		cout << "1 - Addition" << endl;
		cout << "2 - Subtraction" << endl;
		cout << "3 - Comparison \"less than \"" << endl;
		cout << "4 - Comparison \"greater than \"" << endl;
		cout << "5 - Comparison \"unequal\"" << endl;
		cout << "6 - Comparison \"equals\"" << endl;
		cout << "0 - Exit" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - Сложение
			system("cls");
			cout << "Enter the first number: " << endl;
			cin >> input_num1;
			cout << "Enter the second number: " << endl;
			cin >> input_num2;
			num1.set_my_int(input_num1);
			num2.set_my_int(input_num2);
			res = num1 + num2;
			cout << "Result: ";
			res.display();
			break;
		case 2: //2 - Вычитание
			system("cls");
			cout << "Enter the first number: " << endl;
			cin >> input_num1;
			cout << "Enter the second number: " << endl;
			cin >> input_num2;
			num1.set_my_int(input_num1);
			num2.set_my_int(input_num2);
			res = num1 - num2;
			cout << "Result: ";
			res.display();
			break;
		case 3: //3 - Сравнение "меньше, чем"
			system("cls");
			cout << "Enter the first number: " << endl;
			cin >> input_num1;
			cout << "Enter the second number: " << endl;
			cin >> input_num2;
			num1.set_my_int(input_num1);
			num2.set_my_int(input_num2);
			if (num1 < num2)
				cout << "The first number is smaller than the second" << endl;
			else
				cout << "The first number is greater than the second" << endl;
			break;
		case 4: //4 - Сравнение "больше, чем"
			system("cls");
			cout << "Enter the first number: " << endl;
			cin >> input_num1;
			cout << "Enter the second number: " << endl;
			cin >> input_num2;
			num1.set_my_int(input_num1);
			num2.set_my_int(input_num2);
			if (num1 > num2)
				cout << "The first number is greater than the second" << endl;
			else
				cout << "The first number is smaller than the second" << endl;
			break;
		case 5: //5 - Сравнение "неравно"
			system("cls");
			cout << "Enter the first number: " << endl;
			cin >> input_num1;
			cout << "Enter the second number: " << endl;
			cin >> input_num2;
			num1.set_my_int(input_num1);
			num2.set_my_int(input_num2);
			if (num1 != num2)
				cout << "The first number is not equal to the second" << endl;
			else
				cout << "The first number is equal to the second" << endl;
			break;
		case 6: //6 - Сравнение "равно"
			system("cls");
			cout << "Enter the first number: " << endl;
			cin >> input_num1;
			cout << "Enter the second number: " << endl;
			cin >> input_num2;
			num1.set_my_int(input_num1);
			num2.set_my_int(input_num2);
			if (num1 == num2)
				cout << "The first number is equal to the second" << endl;
			else
				cout << "The first number is not equal to the second" << endl;
			break;
		case 0: //0 - Выход
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}
	
	return 0;
}
