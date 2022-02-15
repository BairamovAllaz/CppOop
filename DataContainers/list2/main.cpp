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
        while (Head)
        {
            pop_back();
        }
        cout << "Ldesctructor\t" << endl;
    }

    explicit List(const List &other)
    {
        if (&other == this)
        {
            return;
        }

        Head = nullptr;
        Tail = nullptr;

        Element *Temp = other.Tail;
        while (Temp)
        {
            push_back(Temp->Data);
            Temp = Temp->pPrev;
        }
        cout << "CopyConstructor\t" << this << endl;
    }

    List &operator=(List &other)
    {
        if (&other == this)
        {
            return *this;
        }
        Element *Temp = other.Tail;
        while (Temp)
        {
            push_back(Temp->Data);
            Temp = Temp->pPrev;
        }
        cout << "CopyAssigment\t" << this << endl;
        return *this;
    }

    List(const std::initializer_list<T> &list)
    {

        for (T Data : list)
        {
            push_back(Data);
        }
        // for (const T *it = list.begin(); it != list.end(); ++it)
        // {
        //     push_back(*it);
        // }
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

        if (Head == Tail)
        {
            delete Head;
            Head = Tail = nullptr;
            return;
        }
        Head = Head->pNext;
        delete Head->pPrev;
        Head->pPrev = nullptr;
        size--;
    }

    void pop_back()
    {
        if (Head == Tail)
            return pop_front();
        Tail = Tail->pPrev;
        delete Tail->pNext;
        Tail->pNext = nullptr;
        size--;
    }

    void insert(int index, T data)
    {
        if (index > size)
        {
            cerr << "Error size" << endl;
            return;
        }
        if (Head == nullptr && Tail == nullptr || index == 0)
        {
            return push_front(data);
        }
        if (index == size)
        {
            return push_back(data);
        }
        Element *newElement = new Element(data);
        Element *Temp;
        if (index < size / 2)
        {
            Temp = Head;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pNext;
            }
            size++;
        }
        else
        {
            Temp = Tail;
            for (int i = 0; i < size - 1 - index; ++i)
            {
                Temp = Temp->pPrev;
            }
            size++;
        }
        newElement->pNext = Temp;
        newElement->pPrev = Temp->pPrev;
        Temp->pPrev->pNext = newElement;
        Temp->pPrev = newElement;
    }

    void erase(int index)
    {
        if (index > size)
        {
            cerr << "Error size" << endl;
            return;
        }
        if (Head == nullptr && Tail == nullptr || index == 0)
        {
            return pop_front();
        }
        if (index == size)
        {
            return pop_back();
        }
        Element *Temp;
        if (index < size / 2)
        {
            Temp = Head;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pNext;
            }
            size--;
        }
        else
        {
            Temp = Tail;
            for (int i = 0; i < size - 1 - index; ++i)
            {
                Temp = Temp->pPrev;
            }
            size--;
        }
        Temp->pPrev->pNext = Temp->pNext;
        Temp->pNext->pPrev = Temp->pPrev;
        delete Temp;
    }

    void print() const
    {
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

#define BASE_CHECK

int main()
{
    srand(time(0));
#ifdef BASE_CHECK
    List<string> list;
    list.push_back("H");
    list.push_back("E");
    list.push_back("L");
    list.push_back("L");
    list.push_back("O");
    // list.insert(5, "World");
    list.erase(1);
    list.print();
    // cout << "New: "<< endl;
    // list.pop_front();
    // list.print();

    // List<string> list = {"This", "is", "a", "test"};
    // list.print();

    // int n;
    // cout << "Enter size: ";
    // cin >> n;
    // List<string> list;
    // for (int i = 0; i < n; ++i)
    // {
    //     list.push_back(rand() % 20 + 1);
    // }
    // cout << "Last: " << endl;
    // list.print_reverse();

    // List<string> list2;
    // list2 = list;
    // list2.print_reverse();

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
#endif
    return 0;
}
