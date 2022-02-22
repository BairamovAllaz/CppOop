#pragma once
#include "stdrfx.h"
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
        Element(T Data, Element *pNext = nullptr, Element *pPrev = nullptr);
        ~Element();
        friend class List;
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
        Base_Iterator(Element *Temp = nullptr);
        ~Base_Iterator();

        virtual Base_Iterator &operator++() = 0;
        virtual Base_Iterator &operator--() = 0;

        bool operator==(const Base_Iterator &obj) const;

        bool operator!=(const Base_Iterator &obj) const;

        T &operator*();

        const T &operator*() const;
        operator bool() const;
    };

    class ConstIterator : public Base_Iterator
    {
    public:
        ConstIterator(Element *temp = nullptr);
        ~ConstIterator();
        ConstIterator &operator++();
        ConstIterator operator++(int);
        ConstIterator &operator--();
        ConstIterator operator--(int);
        friend class List;
    };

    class ConstReverseIterator : public Base_Iterator
    {
    public:
        ConstReverseIterator(Element *temp = nullptr);
        ~ConstReverseIterator();
        ConstReverseIterator &operator++();
        ConstReverseIterator operator++(int);
        ConstReverseIterator &operator--();
        ConstReverseIterator operator--(int);
        friend class List;
    };

    class Iterator : public ConstIterator
    {
    public:
        Iterator(Element *temp = nullptr) : ConstIterator(temp) {}
        ~Iterator() {}

        friend class List;
    };

    class ReverseIterator : public ConstReverseIterator
    {
    public:
        ReverseIterator(Element *temp = nullptr) : ConstReverseIterator(temp) {}
        ~ReverseIterator() {}

        friend class List;
    };

    List();
    ~List();
    explicit List(const List &other);
    List &operator=(List &other);
    List(const std::initializer_list<T> &list);
    /// adding elements
    void push_front(T Data);
    void push_back(T Data);
    void pop_front();
    void pop_back();
    void insert(int index, T data);
    void erase(int index);
    T &operator[](int index);
    const T &operator[](int index) const;
    Iterator begin();
    Iterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    ConstReverseIterator crbegin() const;
    ConstReverseIterator crend() const;
    void print() const;
    void print_reverse() const;
};
