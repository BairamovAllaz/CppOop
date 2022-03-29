#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

template <typename T>
class Queue;
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
        friend class Queue<T>;
    } * Head, *Tail;

    // Element *Head;
    // Element *Tail;
    size_t size;

public:
    class Base_Iterator
    {
    protected:
        Element *Temp;

    public:
        Base_Iterator(Element *Temp = nullptr) : Temp(Temp) { cout << "Baseconstructro\t" << this << endl; }
        ~Base_Iterator() { cout << "BaseDesctructor\t" << this << endl; }

        bool operator==(const Base_Iterator &obj) const
        {
            return this->Temp == obj.Temp;
        }

        bool operator!=(const Base_Iterator &obj) const
        {
            return this->Temp != obj.Temp;
        }

        T &operator*()
        {
            return Temp->Data;
        }

        const T &operator*() const
        {
            return Temp->Data;
        }

        operator bool() const
        {
            return Temp;
        }
    };

    class Iterator : public Base_Iterator
    {
    public:
        Iterator(Element *temp = nullptr) : Base_Iterator(temp) { cout << "Iterator\t" << this << endl; }
        ~Iterator() { cout << "Desctructor\t" << this << endl; }

        Iterator &operator++()
        {
            Base_Iterator::Temp = Base_Iterator::Temp->pNext;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator Copy = *this;
            Base_Iterator::Temp = Base_Iterator::Temp->pNext;
            return Copy;
        }

        Iterator operator--()
        {
            Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
            return *this;
        }

        Iterator operator--(int)
        {
            Element *Copy = *this;
            Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
            return Copy;
        }

        friend class List;
    };

    class ReverseIterator : public Base_Iterator
    {
    public:
        ReverseIterator(Element *temp = nullptr) : Base_Iterator(temp) { cout << "Ritconstructor"; }
        ~ReverseIterator() { cout << "Ridesctructor"; }

        ReverseIterator &operator++()
        {
            Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
            return *this;
        }
        ReverseIterator operator++(int)
        {
            ReverseIterator Copy = *this;
            Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
            return Copy;
        }

        ReverseIterator &operator--()
        {
            Base_Iterator::Temp = Base_Iterator::Temp->pNext;
            return *this;
        }

        ReverseIterator operator--(int)
        {
            ReverseIterator Copy = *this;
            Base_Iterator::Temp = Base_Iterator::Temp->pNext;
            return Copy;
        }
        friend class List;
    };

    class ConstIterator : public Iterator
    {
    public:
        ConstIterator(Element *temp = nullptr) : Iterator(temp) {}
        ~ConstIterator() {}
        friend class List;
    };

    class ConstReverseIterator : public ReverseIterator
    {
    public:
        ConstReverseIterator(Element *temp = nullptr) : ReverseIterator(temp) {}
        ~ConstReverseIterator() {}
        friend class List;
    };

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

    List(const std::initializer_list<T> &list) : List()
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
        // Element *new_element = new Element(Data);
        // new_element->pNext = Head;
        // Head->pPrev = new_element;
        Head = Head->pPrev = new Element(Data, Head);
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
        // Element *new_element = new Element(Data);
        // new_element->pPrev = Tail;
        // Tail->pNext = new_element;
        Tail = Tail->pNext = new Element(Data, nullptr, Tail);
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
        // Element *newElement = new Element(data);
        // newElement->pNext = Temp;
        // newElement->pPrev = Temp->pPrev;
        // Temp->pPrev->pNext = newElement;
        // Temp->pPrev = newElement;
        Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp, Temp->pPrev);
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

    T &operator[](int index)
    {
        Element *Temp;
        if (index < size / 2)
        {
            Temp = Head;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pNext;
            }
        }
        else
        {
            Temp = Tail;
            for (int i = 0; i < size - 1 - index; ++i)
            {
                Temp = Temp->pPrev;
            }
        }
        return Temp->Data;
    }
    const T &operator[](int index) const
    {
        Element *Temp;
        if (index < size / 2)
        {
            Temp = Head;
            for (int i = 0; i < index; ++i)
            {
                Temp = Temp->pNext;
            }
        }
        else
        {
            Temp = Tail;
            for (int i = 0; i < size - 1 - index; ++i)
            {
                Temp = Temp->pPrev;
            }
        }
        return Temp->Data;
    }

    Iterator begin()
    {
        return Head;
    }
    Iterator end()
    {
        return nullptr;
    }

    ReverseIterator rbegin()
    {
        return Tail;
    }
    ReverseIterator rend()
    {
        return nullptr;
    }

    ConstIterator cbegin() const
    {
        return Head;
    }

    ConstIterator cend() const
    {
        return nullptr;
    }

    ConstReverseIterator crbegin() const
    {
        return Tail;
    }
    ConstReverseIterator crend() const
    {
        return nullptr;
    }

    void print() const
    {
        for (Iterator Temp = Head; Temp.Temp; ++Temp)
        {
            cout << *Temp << endl;
        }
        cout << "Size: " << size << endl;
    }

    void print_reverse() const
    {
        // for (IteratorBack Temp = Tail; Temp.Temp; ++Temp)
        // {
        //     cout << *Temp << endl;
        // }

        for (Iterator Temp = Tail; Temp.Temp; --Temp)
        {
            cout << *Temp << endl;
        }
        cout << "Size: " << size << endl;
    }

    friend class Queue<T>;
};

template <typename T>
class Queue : private List<T>
{

public:
    Queue(const std::initializer_list<T> &list) : List<T>(list) {}

    void enqueue(T data)
    {
        List<T>::push_back(data);
    }

    void dequeue()
    {
        List<T>::pop_front();
    }

    bool isEmpty()
    {
        if (List<T>::size == 0)
        {
            return true;
        }

        return false;
    }

    int size()
    {
        return List<T>::size;
    }

    void print() const
    {
        List<T>::print();
    }

    typename List<T>::Iterator begin()
    {
        return List<T>::Head;
    }

    typename List<T>::Iterator end()
    {
        return nullptr;
    }

    typename List<T>::ConstIterator begin()const
    {
        return List<T>::Head;
    }

    typename List<T>::ConstIterator end() const
    {
        return nullptr;
    }
};

// #define BASE_CHECK
// #define RANGE_BASED_FOR
#define QUEUE
int main()
{
    srand(time(0));
#ifdef RANGE_BASED_FOR
    List<int> list = {2, 4, 5, 6};
    // for (List<int>::ConstIterator it = list.cbegin(); it != nullptr; ++it)
    // {
    //     std::cout << *it << endl;
    // }
    for (List<int>::ConstIterator it = list.cbegin(); it != nullptr; ++it)
    {
        std::cout << *it << endl;
    }

#endif

#ifdef BASE_CHECK
    // List<string> list;
    // list.push_back("H");
    // list.push_back("E");
    // list.push_back("L");
    // list.push_back("L");
    // list.push_back("O");
    // list.insert(5, "World");
    // // list.erase(1);
    // list.insert(2, "T");
    // list.print();
    List<string> list = {"H", "E", "L", "L", "O", "O"};
    // for (string i : list)
    // {
    //     cout << i << endl;
    // }
    list.print_reverse();
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

#ifdef QUEUE

    Queue<int> q = {1, 3, 4, 5, 6, 7, 8, 1, 2, 4, 5, 6};
    // q.enqueue(100);
    // for (int i = 0; i < 5; ++i)
    // {
    //     q.enqueue(i + 1);
    // }

    for (int i : q)
    {
        cout << i << endl;
    }
    // q.print();

#endif // DEBUG
    return 0;
}
