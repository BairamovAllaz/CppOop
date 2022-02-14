#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

template <typename T>
class List
{
    class Element
    {
    private:
        T Data;
        Element *pNext; // next element
        Element *pPrev; // pervious element
    public:
        Element(T Data, Element *pNext = nullptr, Element *pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
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
    void push_front(T Data)
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

    void push_back(T Data)
    {
        if (Head == nullptr && Tail == nullptr)
        {
            Head = Tail = new Element(Data);
            size++;
            return;
        }
        Element *new_element = new Element(Data);
        new_element->pNext = nullptr;
        new_element->pPrev = Tail;
        Tail->pNext = new_element;
        Tail = new_element;
        size++;
    }

    void pop_front()
    {
        if (Head == nullptr && Tail == nullptr)
        {
            return;
        }
        Element *Erased = Head;
        Head = Head->pNext;
        Head->pPrev = nullptr;
        delete Erased;
        size--;
    }

    void pop_back()
    {
        if (Head == nullptr && Tail == nullptr)
        {
            return;
        }
        Element *Erased = Tail;
        Tail = Tail->pPrev;
        Tail->pNext = nullptr;
        delete Erased;
        size--;
    }

    void insert(int index, int data)
    {
        double newsize = size / 2;
        Element *newElement = new Element(data);
        Element *outTemp = nullptr;
        if (index <= newsize || size < 5)
        {
            Element *Temp = Head;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pNext;
            }
            outTemp = Temp;
            size++;
            cout << "Front" << endl;
        }
        else if (index >= newsize)
        {
            Element *Temp = Tail;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pPrev;
            }
            outTemp = Temp;
            size++;
            cout << "Back" << endl;
        }
        newElement->pNext = outTemp;
        newElement->pPrev = outTemp->pPrev;
        outTemp->pPrev->pNext = newElement;
        outTemp->pPrev = newElement;
    }

    void erase(int index)
    {
        double newsize = size / 2;
        Element *outTemp = nullptr;
        if (index <= newsize || size < 5)
        {
            Element *Temp = Head;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pNext;
            }
            outTemp = Temp;
            size--;
            cout << "Front" << endl;
        }
        else if (index >= newsize)
        {
            Element *Temp = Tail;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pPrev;
            }
            outTemp = Temp;
            size--;
            cout << "Back" << endl;
        }

        Element *Erased = outTemp;
        outTemp->pPrev->pNext = outTemp->pNext;
        outTemp->pNext->pPrev = outTemp->pPrev;
        delete Erased;
    }

    void print() const
    {
        Element *Temp = Head;
        for (Element *Temp = Head; Temp; Temp = Temp->pNext)
        {
            cout << Temp->Data << endl;
        }
        cout << "Size: " << size << endl;
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
    List<string> list;
    // for (int i = 0; i < n; ++i)
    // {
    //     list.push_back(rand() % 20 + 1);
    // }

    list.push_back("Hello");
    list.push_back("World");

    cout << "Last: " << endl;
    list.print_reverse();

    // int index, number;
    // cout << "Enter index to add number: ";
    // cin >> index;
    // cout << "Enter number to add: ";
    // cin >> number;
    // list.insert(index, number);
    // cout << "Our: " << endl;
    // list.print_reverse();

    // cout << "Enter index to delete: ";
    // cin >> index;
    // list.erase(index);
    // list.print_reverse();
    return 0;
}
