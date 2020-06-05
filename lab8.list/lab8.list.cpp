#include <iostream>
#include <ctime>
#include <list>
#include <iterator>
#include <forward_list>
using namespace std;

template<typename T>
class List 
{
	public:

		List();
		~List();

		void push_back(T data);
		int GetSize() { return Size; }
		void pop_front();
		void clear();
		void push_front(T data);
		void inser(T value, int index);
		void removeAt(int index);
		T& operator[](const int index);


	private:

		template<typename T>
		class Node 
		{
		public:
			Node *pNext;
			T data;

			Node(T data = T(), Node* pNext = nullptr) {
				this->data = data;
				this->pNext = pNext;
			}
		};
		int Size;
		Node<T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) 
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr) 
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size) 
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::inser(T data, int index)
{
	if (index==0)
	{
		push_front(data);

	}
	else 
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data,previous->pNext);

		previous->pNext = newNode;
		Size++;
	}

	

}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index==0)
	{
		pop_front();
	}
	else 
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index) 
		{
			return current->data;
		}
		current = current -> pNext;
		counter++;
	}
}

void firstlvl() 
{
	List<int> mylist;
	int a;
	bool Is55 = false;
	do {
		mylist.clear();
		for (int i = 0; i < 10; i++) {
			a = rand() % 100;
			if (a == 55) Is55 = true;
			mylist.push_back(a);
		}
	} while (Is55 == false);


	cout << "Список до редактирования" << endl;
	for (int i = 0; i < mylist.GetSize(); i++)
	{
		cout << mylist[i]<<"  ";
	}
	cout << endl;
	for (int i = 0; i < mylist.GetSize(); i++)
	{
		if (mylist[i] == 55)
		{
			mylist.removeAt(i - 1);
			break;
		}
	}
	cout << "Список после редактирования" << endl;
	for (int i = 0; i < mylist.GetSize(); i++)
	{
		cout << mylist[i] << "  ";
	}
	cout << endl << endl;
	mylist.clear();
}




void secondlvl() 
{
	List <double> mylist;
	double a;
	bool IsPositive = false;
	do {
		mylist.clear();
		for (int i = 0; i < 10; i++) {
			a = double(rand() % 100) / 10 - 5;
			if (a > 0) IsPositive = true;
			mylist.push_back(a);
		}
	} while (IsPositive == false);

	cout << "Список до редактирования" << endl;
	for (int i = 0; i < mylist.GetSize(); i++)
	{
		cout << mylist[i] << "  ";
	}
	cout << endl;


	for (int i = 0; i < mylist.GetSize(); i++)
	{
		if (mylist[i] > 0)
		{
			mylist.inser(mylist[i], i);
			break;
		}
	}
	
	cout << "Список после редактирования" << endl;
	for (int i = 0; i < mylist.GetSize(); i++)
	{
		cout << mylist[i] << "  ";
	}
	cout << endl;
}
void thirdlvl() 
{

	list <int> mylist;
	list <int> ::iterator Place, Obj;

	int a;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			int a = rand() % 10;
			mylist.push_back(a);
		}
	}	
	cout << "Список до редактирования" << endl;
	for (Place = mylist.begin(); Place != mylist.end(); Place++)
	{
		cout << *Place << " ";
	}
	cout << endl << "Адресс первого элемента" << endl;
	cout<<&mylist.begin()<<endl;

	for (Place = mylist.begin(); Place != mylist.end(); Place++)
	{
		if (*Place % 2 != 0) {
			Obj = Place;
			a = *Place;
			mylist.insert(Obj, a);
		}
	}
	cout << endl;
	cout << "Список после редактирования" << endl;
	for (Place = mylist.begin(); Place != mylist.end(); Place++)
	{
		cout << *Place << " ";
	}
	cout << endl << "Адресс первого элемента" << endl;
	cout << &mylist.begin() << endl;
}  



int main()
{
	setlocale(0, "");
	srand(time(0));
	int a;
	while (true)
	{
		cout << "Numbers of levels are 1 2 3 (0 to exit)\n";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
			cout << "Создать линейный однонаправленный список из вещественных чисел. Удалить из списка элемент перед первым элементом со значением 55." << endl << endl;
			firstlvl();
			break;
		case 2:
			cout << "Создать линейный однонаправленный список из вещественных чисел.Продублировать в списке первый положительный элемент(если такого нет, оставить список без изменения)." << endl << endl;
			secondlvl();
			break;
		case 3:
			cout << "Дан указатель P 1 на первый элемент непустого двусвязного списка. Продублировать в списке все элементы с нечетными значениями(новые элементы добавлять   перед   существующими элементами с такими же значениями) и вывести указатель на первый элемент преобразованного списка." << endl << endl;
			thirdlvl();
			break;
		case 0:
			return(0);
			break;
		default:
			cout << "Incorrect number, try again" << endl;
			break;
		}
	}
}

