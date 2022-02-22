#include "List.h"


//!base_Iterator
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


//!const_reverse_iterator
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
