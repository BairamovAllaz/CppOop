#include "List.h"

//!List class
template <typename T>
List<T>::List()
{
    Head = Tail = nullptr;
    size = 0;
    cout << "Lconstructor\t" << this << endl;
}
template <typename T>
List<T>::~List()
{
    while (Head)
    {
        pop_back();
    }
    cout << "Ldesctructor\t" << endl;
}

template <typename T>
List<T>::List(const List &other)
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
template <typename T>
List<T> &List<T>::operator=(List<T> &other)
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
template <typename T>
List<T>::List(const std::initializer_list<T> &list) : List()
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

template <typename T>
void List<T>::push_front(T Data)
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
template <typename T>
void List<T>::push_back(T Data)
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
template <typename T>
void List<T>::pop_front()
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
template <typename T>
void List<T>::pop_back()
{
    if (Head == Tail)
        return pop_front();
    Tail = Tail->pPrev;
    delete Tail->pNext;
    Tail->pNext = nullptr;
    size--;
}
template <typename T>
void List<T>::insert(int index, T data)
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
template <typename T>
void List<T>::erase(int index)
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
template <typename T>
T &List<T>::operator[](int index)
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
template <typename T>
const T &List<T>::operator[](int index) const
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
template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    return Head;
}
template <typename T>
typename List<T>::Iterator List<T>::end()
{
    return nullptr;
}
template <typename T>
typename List<T>::ReverseIterator List<T>::rbegin()
{
    return Tail;
}
template <typename T>
typename List<T>::ReverseIterator List<T>::rend()
{
    return nullptr;
}
template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{
    return Head;
}
template <typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    return nullptr;
}
template <typename T>
typename List<T>::ConstReverseIterator List<T>::crbegin() const
{
    return Tail;
}
template <typename T>
typename List<T>::ConstReverseIterator List<T>::crend() const
{
    return nullptr;
}
template <typename T>
void List<T>::print() const
{
    for (Iterator Temp = Head; Temp.Temp; ++Temp)
    {
        cout << *Temp << endl;
    }
    cout << "Size: " << size << endl;
}
template <typename T>
void List<T>::print_reverse() const
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


//!Element
template <typename T>
List<T>::Element::Element(T Data, Element *pNext, Element *pPrev) : Data(Data), pNext(pNext), pPrev(pPrev)
{
    cout << "Econstructor\t" << this << endl;
}
template <typename T>
List<T>::Element::~Element()
{
    cout << "Edesctructor\t" << this << endl;
}



//!Iterators
template <typename T>
List<T>::Base_Iterator::Base_Iterator(Element *Temp) : Temp(Temp) {}
template <typename T>
List<T>::Base_Iterator::~Base_Iterator() {}
template <typename T>
bool List<T>::Base_Iterator::operator==(const Base_Iterator &obj) const
{
    return this->Temp == obj.Temp;
}
template <typename T>
bool List<T>::Base_Iterator::operator!=(const Base_Iterator &obj) const
{
    return this->Temp != obj.Temp;
}
template <typename T>
T &List<T>::Base_Iterator::operator*()
{
    return Temp->Data;
}
template <typename T>
const T &List<T>::Base_Iterator::operator*() const
{
    return Temp->Data;
}
template <typename T>
List<T>::Base_Iterator::operator bool() const
{
    return Temp;
}

//! constIterator
template <typename T>
List<T>::ConstIterator::ConstIterator(Element *temp) : Base_Iterator(temp) {}
template <typename T>
List<T>::ConstIterator::~ConstIterator() {}
template <typename T>
typename List<T>::ConstIterator &List<T>::ConstIterator::operator++()
{
    Base_Iterator::Temp = Base_Iterator::Temp->pNext;
    return *this;
}
template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
    Iterator Copy = *this;
    Base_Iterator::Temp = Base_Iterator::Temp->pNext;
    return Copy;
}
template <typename T>
typename List<T>::ConstIterator &List<T>::ConstIterator::operator--()
{
    Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
    return *this;
}
template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
    Element *Copy = *this;
    Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
    return Copy;
}

//! const_reverse_iterator
template <typename T>
List<T>::ConstReverseIterator::ConstReverseIterator(Element *temp) {}
template <typename T>
List<T>::ConstReverseIterator::~ConstReverseIterator() {}
template <typename T>
typename List<T>::ConstReverseIterator &List<T>::ConstReverseIterator::operator++()
{
    Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
    return *this;
}
template <typename T>
typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
    ReverseIterator Copy = *this;
    Base_Iterator::Temp = Base_Iterator::Temp->pPrev;
    return Copy;
}
template <typename T>
typename List<T>::ConstReverseIterator &List<T>::ConstReverseIterator::operator--()
{
    Base_Iterator::Temp = Base_Iterator::Temp->pNext;
    return *this;
}
template <typename T>
typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator--(int)
{
    ReverseIterator Copy = *this;
    Base_Iterator::Temp = Base_Iterator::Temp->pNext;
    return Copy;
}