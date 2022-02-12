#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
#define tab "\t"
// #define OLD_PRINT
template <typename T>
class ForwardList;
template <typename T>
class Iterator;

template <typename T>
class Element
{
    T Data;
    Element<T> *pNext;
    static int count;

public:
    Element(T Data, Element<T> *pNext = nullptr) : Data(Data), pNext(pNext)
    {
        count++;
        cout << "EConstrcutor:\t" << this << endl;
    }
    ~Element()
    {
        count--;
        cout << "EDestrcutor:\t" << this << endl;
    }
    friend class ForwardList<T>;
    friend class Iterator<T>;
    // friend std::ostream &operator<<(std::ostream &in, const Element &obj);
};
template <typename T>
int Element<T>::count = 0;
/// iterator documentation:  http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html
template <typename T>
class Iterator
{
private:
    Element<T> *Temp;

public:
    Iterator(Element<T> *temp = nullptr) : Temp(temp) { cout << "Idesctructor\t" << this << endl; }
    ~Iterator() { cout << "Idesctructor\t" << this << endl; }
    Iterator<T> &operator++()
    {
        Temp = Temp->pNext;
        return *this;
    }
    Iterator<T> operator++(int)
    {
        Iterator Copy = *this;
        Temp = Temp->pNext;
        return Copy;
    }
    bool operator==(const Iterator<T> &obj) const
    {
        return this->Temp == obj.Temp;
    }

    bool operator!=(const Iterator<T> &obj) const
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

    friend class ForwardList<T>;
};

template <typename T>
class ForwardList
{
private:
    Element<T> *Head;
    unsigned int size;

public:
    ForwardList()
    {
        this->size = 0;
        Head = nullptr;
        cout << "LConstructor:\t" << this << endl;
    }
    ForwardList(const std::initializer_list<T> &list) : ForwardList()
    {
        // for (auto &Data : list)
        // {
        //     push_front(Data);
        // }
        // for(const int* it=list.begin();it!=list.end();it++) {
        //     push_back(*it);
        // }
        for (const T *it = list.end() - 1; it != list.begin() - 1; --it)
        {
            push_front(*it);
        }
    }
    explicit ForwardList(const ForwardList<T> &obj)
    {
        if (&obj == this)
            return;
        Head = nullptr;
        // for (Element<T> *Temp = obj.Head; Temp; Temp = Temp->pNext)
        // {
        //     push_back(Temp->Data);
        // }
        for (Iterator<T> it = obj.Head; it; ++it)
        {
            push_back(*it);
        }
        cout << "Copy constructor\t" << this << endl;
    }
    ForwardList<T> &operator=(const ForwardList<T> &obj)
    {
        if (&obj == this)
            return *this;
        while (Head)
            pop_front();
        // for (Element<T> *Temp = obj.Head; Temp; Temp = Temp->pNext)
        // {
        //     push_back(Temp->Data);
        // }
        for (Iterator<T> it = obj.Head; it; ++it)
        {
            push_back(*it);
        }
        cout << "CopyAssigment\t" << this << endl;
        return *this;
    }
    ForwardList(int size)
    {
        this->size = 0;
        this->Head = nullptr;
        for (int i = 0; i < size; ++i)
        {
            push_front(T());
        }
    }
    // desctructor
    ~ForwardList()
    {
        // Element *Temp = Head;
        // while (Temp->pNext)
        // {
        //     Element *New = Temp->pNext;
        //     delete Temp;
        //     Temp = New;
        // }
        // cout << "LDestructor:\t" << this << endl;

        while (Head)
            pop_front();

        cout << "Ldesctructor" << endl;
    }
    ForwardList(ForwardList<T> &&obj) : Head(nullptr), size(0)
    {
        Element<T> *Temp = Head;
        Head = obj.Head;
        obj.Head = Temp;
        cout << "Move constructor: \t" << this << endl;
    }
    ForwardList<T> &operator=(ForwardList<T> &&obj)
    {
        Element<T> *Temp = Head;
        Head = obj.Head;
        obj.Head = Temp;
        cout << "Move Assigment: \t" << this << endl;
        return *this;
    }
    // const Element &operator[](int it) const
    // {
    //     Element *Temp = Head;
    //     for (int i = 0; i < it; i++)
    //     {
    //         Temp = Temp->pNext;
    //     }
    //     return *Temp;
    // }
    // Element &operator[](int it)
    // {
    //     Element *Temp = Head;
    //     for (size_t i = 0; i < it; i++)
    //     {
    //         Temp = Temp->pNext;
    //     }
    //     return *Temp;
    // }
    T &operator[](int index)
    {
        Element<T> *Temp = Head;
        for (int i = 0; i < index; ++i)
        {
            Temp = Temp->pNext;
        }
        return Temp->Data;
    }
    const T &operator[](int index) const
    {
        Element<T> *Temp = Head;
        for (int i = 0; i < index; ++i)
        {
            Temp = Temp->pNext;
        }
        return Temp->Data;
    }

    void unique()
    {
        Element<T> *Temp = Head, *In = nullptr;
        for (int i = 0; Temp; ++i)
        {
            In = Temp->pNext;
            while (In)
            {
                if (Temp->Data == In->Data)
                {
                    //erase(i);
                    Element<T> *next = Temp->pNext;
                    delete Temp;
                    Temp->pNext = next;
                }
                In = In->pNext;
            }
            Temp = Temp->pNext;
        }
    }

    void reverse()
    {
        Element<T> *Temp = Head, *next = nullptr, *prev = nullptr;

        while (Temp)
        {
            next = Temp->pNext; // next element for while loop
            Temp->pNext = prev; // current next element to pervios element
            prev = Temp;        // pervios element for next element
            Temp = next;        /// next element to while loop run again!
        }
        Head = prev;
    }

    void push_front(T Data)
    {
        // Element *New = new Element(Data);
        // New->pNext = Head;
        // Head = New;
        Head = new Element<T>(Data, Head);
        size++;
    }
    void push_back(T Data)
    {
        if (Head == nullptr)
        {
            return push_front(Data);
        }
        // Element *New = new Element(Data);
        Element<T> *Temp = Head;

        while (Temp->pNext)
        {
            Temp = Temp->pNext;
        }
        Temp->pNext = new Element<T>(Data);
        // New->pNext = NULL; Deafult Null
        size++;
    }
    ////*removing elements
    void pop_front()
    {
        if (Head == nullptr)
            return;
        Element<T> *Erases = Head;
        Head = Head->pNext;
        delete Erases;
        size++;
    }
    void pop_back()
    {
        if (Head == nullptr)
            return;
        if (Head->pNext == nullptr)
            return pop_front();
        Element<T> *Temp = Head;
        while (Temp->pNext->pNext)
        {
            Temp = Temp->pNext;
        }

        delete Temp->pNext;
        Temp->pNext = nullptr;
        size--;
    }
    void insert(int index, T Data)
    {
        if (index > size)
            return;
        if (index == 0 || Head == nullptr)
            return push_front(Data);
        // Element *New = new Element(Data);
        Element<T> *Temp = Head; //*iterator

        for (int i = 0; i < index - 1; ++i)
        {
            Temp = Temp->pNext;
        }
        // New->pNext = Temp->pNext;
        Temp->pNext = new Element<T>(Data, Temp->pNext);
        size++;
    }
    void erase(int index)
    {
        if (index > size)
            return;
        if (index == 0)
            return pop_front();
        Element<T> *Temp = Head;
        for (int i = 0; i < index - 1; ++i)
        {
            Temp = Temp->pNext;
        }
        Element<T> *Erased = Temp->pNext;
        Temp->pNext = Temp->pNext->pNext;
        delete Erased;
        size--;
        // Element *Temp = Head;
        // for (int i = 0; i < index - 1; ++i)
        // {
        //     Temp = Temp->pNext;
        // }
        // Element *next = Temp->pNext->pNext;
        // delete Temp->pNext;
        // Temp->pNext = next;
    }

    void print() const
    {
#ifdef OLD_PRINT
        // Element *Temp = Head;
        // while (Temp)
        // {
        //     // cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
        //     // Temp = Temp->pNext;
        //     cout << "Hello world " << endl;
        //     ++Temp;
        // }

        Iterator Temp = Iterator(Head);

        while (Temp.Temp)
        {
            cout << Temp.Temp->Data << tab << Temp.Temp->pNext << endl;
            Temp++;
        }

        cout << "Count in Forwardlist: " << size << endl;
        cout << "All Count of list: " << Head->count << endl;
#endif // DEBUG
        for (Iterator<T> Temp = Head; Temp.Temp; ++Temp)
        {
            // cout << Temp.Temp->Data << tab << Temp.Temp->pNext << endl;
            cout << "Data: " << *Temp << endl;
        }
    }

    Iterator<T> begin()
    {
        return Head;
    }
    Iterator<T> end()
    {
        return nullptr;
    };

    friend Iterator<T>;
};

template <typename T>
ForwardList<T> operator+(ForwardList<T> &left, ForwardList<T> &right)
{
    ForwardList<T> newlist(left);
    for (int i : right)
    {
        newlist.push_back(i);
    }

    return newlist;
}

// std::ostream &operator<<(std::ostream &in, const Element &obj)
// {
//     in << endl;
//     in << "Data: " << obj.Data << endl;
//     return in;
// }
// #define BaseCheck
// #define CONSTRUCTOR_CHECK
// #define LIST_CHECK
// #define ASSIGMENT_CHECK

int main()
{
    srand(time(0));
#ifdef BaseCheck
    int n;
    cout << "Enter size of list: ";
    cin >> n;
    ForwardList list;
    list.pop_front();
    for (int i = 0; i < n; i++)
    {
        list.push_back(rand() % 100);
    }
    list.print();

    int index;
    int value;
    cout << "Enter index to add: ";
    cin >> index;
    cout << "Enter element to add: ";
    cin >> value;

    list.insert(index, value);
    list.print();

    cout << "Enter index to delete: ";
    cin >> index;

    list.erase(index);
    list.print();

#endif
#ifdef CONSTRUCTOR_CHECK
    int n;
    cout << "Enter size of list: ";
    cin >> n;
    ForwardList list;
    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
    }
    for (int i = 0; i < n; i++)
    {
        cout << list[i] << endl;
    }
    cout << "Done" << endl;
#endif // DEBUG
#ifdef LIST_CHECK
    // ForwardList list = {3, 5, 8, 13, 23};
    // list.print();
    // ForwardList list;
    // list.push_front(44);
    // list.push_front(48);
    // list.push_front(77);
    // list.push_front(33);
    // cout << "List 1: " << endl;
    // list.print();
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     // list.push_front(rand() % 100);
    //     list.push_back(rand() % 100);
    // }
    // list.push_back(123);
    // list.print();
    // list.pop_front();
    // list.pop_back();
    // int index,value;
    // cout << "Enter index: ";
    // cin >> index;
    // cout << "Enter value: ";
    // cin >> value;
    // list.insert(index,value);
    // list.print();
    // ForwardList list2 = std::move(list);
    // cout << "List 2: " << endl;
    // list2.print();
    // ForwardList list2;
    // list2 = list;
    // cout << "List 2: " << endl;
    // list2.print();
    // ForwardList list2;
    // list2.push_front(44);
    // list2.push_front(48);
    // list2.push_front(77);
    // list2.push_front(33);
    // list2.push_front(55);
    // cout << "List 2: " << endl;
    // list2.print();
#endif // DEBUG
#ifdef ASSIGMENT_CHECK
    int n;
    cout << "Enter size of list: ";
    cin >> n;
    ForwardList list(n);
    for (int i = 0; i < n; ++i)
    {
        list[i] = rand() % 20;
    }
    for (int i = 0; i < n; i++)
    {
        cout << list[i] << endl;
    }
#endif // DEBUG
    // ForwardList<int> list = {666, 3, 4, 888, 7, 5, 999};

    // ForwardList<string> list_string = {"Have", "a", "nice", "day"};
    // for (string c : list_string)
    // {
    //     cout << c << tab;
    // }
    // ForwardList<string> list_string2;
    // list_string2 = list_string;
    // for (string c : list_string2)
    // {
    //     cout << c << tab;
    // }

    ForwardList<int> list1 = {1, 4, 3, 2, 0, 1};
    list1.unique();
    // list1.print();
    for (int i : list1)
    {
        cout << i << endl;
    }
    // ForwardList<int> list2 = {5, 6, 7, 8, 9};

    // ForwardList<int> list3 = list1 + list2;

    // for (int i : list3)
    // {
    //     cout << i << tab;
    // }

    // ForwardList list = {666, 333, 4, 888, 7, 5, 999};
    // ForwardList list2 = std::move(list);
    // cout << "List: " << endl;
    // for (int c : list2)
    // {
    //     cout << c << endl;
    // }
    // cout << "List2: " << endl;
    // for (int d : list)
    // {
    //     cout << d << endl;
    // }

    return 0;
}
