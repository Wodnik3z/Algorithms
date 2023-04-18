#include <time.h>
#include <iostream>
//template<typename T>
using namespace std;


class Node {
public:
	Node* next;
	Node* prev;
	int data;
	Node(int);
};


Node::Node(int v) {

	data = v;
	next = prev = NULL;

}


class DLinkedList
{
	Node* head;
	Node* tail;
	int size;
public:
	DLinkedList();
	~DLinkedList();
	void assignHead(int);
	void assignTail(int);
	void deleteHead();
	void deleteTail();
	void show();
	void clear();
	//void search();

};


DLinkedList::DLinkedList()     // ustawiamy liste na 0:0
{
	head = tail = NULL;
	size = 0;

}
DLinkedList::~DLinkedList() {}

void DLinkedList::assignHead(int v)
{
	Node* temp = new Node(v);
	if (head == NULL) {
		head = tail = temp;
	}
	else {
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	size++;
}

void DLinkedList::assignTail(int v)
{
	Node* temp = new Node(v);
	if (tail == NULL) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	size++;
}


void DLinkedList::deleteHead() {

	if (size == 0) {
		return;
	}
	if (head == tail) {
		tail = NULL;
	}


	Node* temp = head;
	head = head->next; //ustawiamy head na nastepnym
	delete temp;

	size--;

}


void DLinkedList::deleteTail() {

	if (size == 0) {
		return;
	}
	if (size == 1) {
		deleteHead();
		return;
	}


	if (head == tail) {
		head = NULL;
	}


	Node* temp = tail;
	tail = tail->prev; //ustawiamy tail na przedostatnie
	tail->next = nullptr; // kasujemy wskaznik na next
	delete temp;

	size--;
}

void DLinkedList::show()
{

	//string
	Node* temp = head;
	while (temp != NULL)
	{

		//txt += ;
		//return string
		cout << temp->data << "  ";
		temp = temp->next;
	}

}


void DLinkedList::clear()
{

	Node* temp = head;


	if (head == NULL) {
		cout << "lista jest pusta" << endl;
	}
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete(temp);

	}

}




int main()
{
	const int MAX_ORDER = 100;
	std::cout << "Hello World!\n";
	DLinkedList* dll = new DLinkedList();

	int cc, bb;
	cout << "1, dodaj Head/usun head" << endl;
	cout << "2, dodaj tail/usun tail" << endl;
	//cout << "3, usun wszystko" << endl;
	cout << "3, wyjdz" << endl;

	cin >> bb;




	switch (bb)
	{
	case 1:

		cout << "dodajemy do przodu" << endl;
		{
			clock_t t1 = clock();

			do {
				for (int i = 0; i < MAX_ORDER + 1; i++) {
					//cin >> cc;
					cc = i;
					dll->assignHead(cc);
				}
			} while (cc < MAX_ORDER);
			dll->show();
			dll->deleteHead();
			cout << "po usunieciu glowy\n\n";
			dll->show();

			clock_t t2 = clock();

			double time = (t2 - t1) / (double)CLOCKS_PER_SEC;
			cout << "czas" << time;

		}
		break;

	case 2:
	{


		cout << "dodajemy do tylu" << endl;
		clock_t t1 = clock();
		do {
			for (int i = 0; i < MAX_ORDER + 1; i++) {

				//cin >> cc;
				cc = i;

				dll->assignTail(cc);
			}
		} while (cc != MAX_ORDER);
		dll->show();
		 
		dll->deleteTail();
		cout << "po usunieciu ogona\n\n";
		dll->show();



	}
	break;
	/*case 3:
	{
		clock_t t3 = clock();
		cout << "usuwamy wszystko" << endl;

		do {

			for (int i = 0; i < MAX_ORDER + 1; i++) {



				cc = i;


				dll->assignTail(cc);
			}
		} while (cc != MAX_ORDER);
		dll->show();
		cout << "przed usunieciem\n\n";
		dll->clear();
		cout << "po usunieciu wszystkiego\n\n";


		clock_t t4 = clock();

		double time2 = (t4 - t3) / (double)CLOCKS_PER_SEC;
		cout << "czas" << time2;
		break; }*/


	case 3:
		cout << "Wylaczanie programu" << endl;
		return 0;
	}


}

