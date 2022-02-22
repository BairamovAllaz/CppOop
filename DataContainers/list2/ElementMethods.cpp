#include "List.h"
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