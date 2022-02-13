#include <iostream>
#include <ctime>
using namespace std;

class List
{
    class Element
    {
    private:
        int Data;
        Element *pNext; // next element
        Element *pPrev; // pervious element
    public:
        Element(int Data, Element *pNext = nullptr, Element *pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
        {
            cout << "Econstructor\t" << this << endl;
        }

        ~Element()
        {
            cout << "Edesctructor\t" << this << endl;
        }
        friend class List;
    } * Head, *Tail;
    // Element *Head;
    // Element *Tail;
    size_t size;

public:
    List()
    {
        Head = Tail = nullptr;
        size = 0;
        cout << "Lconstructor\t" << this << endl;
    }
    ~List()
    {
        cout << "Ldesctructor\t" << endl;
    }

    /// adding elements
    void push_front(int Data)
    {
        if (Head == nullptr && Tail == nullptr)
        {
            Head = Tail = new Element(Data);
            size++;
            return;
        }
        Element *new_element = new Element(Data);
        new_element->pNext = Head;
        Head->pPrev = new_element;
        Head = new_element;
        size++;
    }

    void print() const
    {
        Element *Temp = Head;
        for (Element *Temp = Head; Temp; Temp = Temp->pNext)
        {
            cout << Temp->Data << endl;
        }
    }

    void print_reverse() const
    {
        for (Element *Temp = Tail; Temp; Temp = Temp->pPrev)
        {
            cout << Temp->Data << endl;
        }
    }
};

int main()
{
    srand(time(0));
    int n;
    cout << "Enter size: ";
    cin >> n;
    List list;
    for (int i = 0; i < n; ++i)
    {
        list.push_front(rand() % 20 + 1);
    }
    cout << "Print " << endl;
    list.print();
    cout << "Reverse: " << endl;
    list.print_reverse();

    return 0;
}
