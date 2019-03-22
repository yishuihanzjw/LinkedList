#include<iostream>

using namespace std;

typedef struct Node
{
	int value;
	Node* next;
}Node;

class MyLinkedList
{
private:
	Node *head;

public:
	MyLinkedList()
	{
		head = new Node;
		head->next = nullptr;
		head->value = 0;
	}

	~MyLinkedList()
	{
		head = nullptr;
		delete head;
	}

	void addAtHead(int val)
	{
		Node *p = new Node;
		p->next = head;
		p->value = val;
		head = p;
	}

	void addAtTail(int val)
	{
		Node *p = new Node;
		p = head;
		p->value = head->value;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->value = val;
		Node *temp = new Node;
		p->next = temp;
		//temp->value = val;
		temp->next = nullptr;
	}

	void addAtIndex(int index, int val)
	{
		cout << this->getNum() << endl;
		if (index > this->getNum())
		{
			cout << "out of length" << endl;
			return;
		}
		else if (index == this->getNum())
		{
			addAtTail(val);
		}
		else
		{

		}
	}
	int getNum()
	{
		int count = 0;
		Node *p = new Node;
		p = head;
		while (p->next != nullptr)
		{
			count++;
			p = p->next;
		}
		delete p;
		return count;
	}

	void display()
	{
		Node *p = new Node;
		p = head;
		while (p->next != nullptr)
		{
			cout << p->value << "\t";
			p = p->next;
		}
		cout << endl;
		//delete p;
	}
};
void main()
{
	MyLinkedList *linkedList = new MyLinkedList();

	linkedList->addAtHead(2);//2

	linkedList->addAtHead(5);//5	2

	linkedList->addAtHead(1);//1	5	2

	linkedList->addAtTail(9);//1	5	2	9

	linkedList->addAtIndex(4,8);

	linkedList->display();

	//cout << linkedList->getNum() << endl;
}