#include <iostream>
using namespace std;

#define tab "\t"

class Element
{
    int Data;
    Element *pNext;
    static int count;
public:
    Element(int Data, Element *pNext = nullptr) : Data(Data), pNext(pNext)
    {
        count++;
        cout << "EConstrcutor:\t" << this << endl;
    }
    ~Element()
    {
        count--;
        cout << "EDestrcutor:\t" << this << endl;
    }
    friend class ForwardList;
};
int Element::count = 0;


class ForwardList
{
    Element *Head;

public:
    ForwardList()
    {
        Head = nullptr;
        cout << "LConstructor:\t" << this << endl;
    }
    ~ForwardList()
    {
        cout << "LDestructor:\t" << this << endl;
    }

    void push_front(int Data)
    {
        Element *New = new Element(Data);
        New->pNext = Head;
        Head = New;
    }

    void push_back(int Data)
    {
        if (Head == nullptr)
        {
            return push_front(Data);
        }
        Element *New = new Element(Data);
        Element *Temp = Head;

        while (Temp->pNext)
        {
            Temp = Temp->pNext;
        }

        Temp->pNext = New;
        // New->pNext = NULL; Deafult Null
    }

    ////*removing elements

    void pop_front()
    {
        if(Head == nullptr) return;
        Element *Erases = Head;
        Head = Head->pNext;
        delete Erases;
    }

    void pop_back()
    {
        if(Head == nullptr)return; 
        if(Head->pNext == nullptr) return pop_front();
        Element *Temp = Head;
        while (Temp->pNext->pNext)
        {
            Temp = Temp->pNext;
        }

        delete Temp->pNext;
        Temp->pNext = nullptr;
    }


    void insert(int index,int Data) { 
        if(index > Head->count)return; 
        if(index == 0 || Head == nullptr) return push_front(Data);
        Element *New = new Element(Data); 
        Element* Temp = Head; //*iterator  

        for(int i=0;i < index-1;++i) { 
            Temp = Temp->pNext;
        }
        New->pNext = Temp->pNext;
        Temp->pNext = New;
    }


    void print() const
    {
        Element *Temp = Head;
        while (Temp)
        {
            cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
            Temp = Temp->pNext;
        }
        cout << "Count of list: " << Head->count << endl;
    }
};

int main()
{
    int n;
    cout << "Enter size of list: ";
    cin >> n;
    ForwardList list;
    for (int i = 0; i < n; i++)
    {
        // list.push_front(rand() % 100);
        list.push_back(rand() % 100);
    }

    // list.push_back(123);
    // list.print();
    // list.pop_front();
    // list.pop_back();

    int index,value; 
    cout << "Enter index: ";
    cin >> index;
    cout << "Enter value: ";
    cin >> value;

    list.insert(index,value);
    list.print();
    return 0;
}