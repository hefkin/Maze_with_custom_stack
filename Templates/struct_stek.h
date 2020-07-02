#pragma once
using namespace std;

template<class T>
class struct_stek
{
private:
	struct Node
	{
		Node() :elem(0), next(0)
		{}
		Node* next;
		T elem;
	};
	Node* head;
	Node* tail;
	void pop();

public:
	struct_stek();
	~struct_stek();
	void push(T);
	int top();
	void print();
};

template<typename T>
struct_stek<T>::struct_stek() :tail(NULL), head(NULL)
{

}

template<typename T>
struct_stek<T>::~struct_stek()
{
	while (head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
}

template<typename T>
void struct_stek<T>::push(T val)
{
	Node* Temp;
	Temp = new Node;
	Temp->elem = val;
	if (tail == NULL)
	{
		tail = Temp;
	}
	else
	{
		Temp->next = tail;
		tail = Temp;
	}
}

template<typename T>
int struct_stek<T>::top()
{
	if (tail == NULL)
	{
		cout << "Stek is empty" << endl;
		return 1;
	}
	cout << tail->elem;
	pop();
	return 0;
}

template<typename T>
void struct_stek<T>::pop()
{
	if (tail == NULL)
	{
		cout << "Stek is empty" << endl;
	}
	Node* delptr = tail;
	tail = tail->next;
	delete delptr;
}

template<typename T>
void struct_stek<T>::print()
{
	if (tail == NULL)
	{
		cout << "Stek is empty" << endl;
	}
	int xy = 0, count = 1, count_8 = 8, count_quad = 1;
	for (Node* ptr = tail; ptr != 0; ptr = ptr->next)
	{
		if (count_8 == 8)
		{
			cout << endl << "Quadrate number " << count_quad << endl;
			count_8 = 0;
			count = 1;
			count_quad++;
		}
		if (xy == 0)
		{
			cout << "x" << count << " " << ptr->elem << '\t';
			xy = 1;
		}
		else
		{
			cout << "y" << count << " " << ptr->elem << endl;
			xy = 0;
			count++;
			count_8 += 2;
		}
		
	}
	cout << endl;
}

