#include <iostream>
using namespace std;
#define tab "\t"

class Element {
private:
	int Data; 
	Element* pNext;
public:
	Element() {
		this->Data = int(); 
		this->pNext = nullptr;
		cout << "Default constructor" << endl;
	}

	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "Econstructor\t" << this << endl;
	}
	~Element() {
		cout << "Desctructor\t" << this << endl;
	}

	friend class ForwardList;
};
class ForwardList {
private:
	Element* Head; //start element in list
public:
	ForwardList() {
		Head = nullptr; 
		cout << "Lconstructor\t" << this << endl;
	}
	~ForwardList() {
		cout << "Ldesctructor\t" << this << endl;
	}
	void push_front(int Data) {
		Element* New = new Element(Data);
		New->pNext = Head; 
		Head = New;
	}
	void push_back(int Data) {
		Element* Temp = Head;
		while (Temp && Temp->pNext) {
			Temp = Temp->pNext;
		}
		Element* newelement = new Element(Data);
		newelement->pNext = NULL;
		Temp->pNext = newelement;
	}
	void pop_front() {
		Element* Temp = Head;
		Head = Head->pNext; 
		delete Temp;
	}
	void pop_back() {
		Element* Temp = Head; 
		///Temp = before last element 
		while(Temp->pNext->pNext != NULL) { // index - 1 = element which placed before our element
			Temp = Temp->pNext;
		}
		delete Temp->pNext; /// delete last element.Example 5  ---- delete 4->5(adress) 
		Temp->pNext = NULL;  //4->pNext = Null last element null!!
	}
	void insert(int index, int Data) {
		Element* Temp = Head;
		int i = 0;
		while (i < index - 1 && Temp != NULL) // index - 1 = element which placed before our element
		{
			Temp = Temp->pNext;
			++i;
		}
		Element* newElement = new Element(Data); 
		newElement->pNext = Temp->pNext;
		Temp->pNext = newElement;
	}


	void erase(int index) {
		Element* Temp = Head;
		int i = 0;
		while (i < index - 1 && Temp != NULL)//index - 1 = element which placed before our element
		{
			Temp = Temp->pNext;
			++i;
		}
		Element* next = Temp->pNext->pNext;
		delete Temp->pNext;
		Temp->pNext = next;
	}
	void print()const{
		Element* Temp = Head;
		while (Temp) {
			cout << Temp->Data << endl;
			Temp = Temp->pNext;
		}
	}
};


int main() {
	setlocale(LC_ALL, "");
	ForwardList list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_back(99);
	list.print();
	list.pop_front();
	cout << endl;
	list.print();
	list.pop_back(); 
	list.print();
	list.insert(1, 100); 
	list.print();
	list.erase(1); 
	list.print();
	return 0;
}
