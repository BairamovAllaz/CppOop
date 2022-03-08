#include <iostream>
#include <cstring>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using namespace std;
// #define STL_ARRAY
// #define VECTOR
// #define DEQUE
// #define LIST
#define FORWARD_LIST
#define delimetr "\n------------------------------\n"

int main()
{
#ifdef STL_ARRAY
    std::array<int, 5> arr = {3, 5, 6, 3, 2}; // static array
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << "Begin: " << *(arr.begin()) << endl;
#endif

#ifdef VECTOR
    std::vector<int> vec = {4, 7, 45, 2, 11, 99, 65}; // dynamic array
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    vec.push_back(100);
    cout << endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "MaxSize: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "First: " << vec.front() << endl;
    cout << "Last: " << vec.back() << endl;

    vec.resize(3);
    cout << delimetr;

    try
    {
        for (size_t i = 0; i < vec.capacity(); i++)
        {
            cout << vec.at(i) << endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << endl;
    cout << delimetr << endl;
    vec.assign({1, 4, 6, 8, 90, 100});
    for (int i : vec)
    {
        cout << i << endl;
    }

    cout << delimetr << endl;
    vec.insert(vec.begin() + 3, 999);

    for (int i : vec)
    {
        cout << i << endl;
    }

#endif

#ifdef DEQUE
    std::vector<int> vec;
    std::deque<int> deque = {3, 5, 8, 13, 21};
    vec.push_back(1);
    deque.push_back(34);
    deque.push_back(55);
    deque.push_back(89);
    for (int i = 0; i < deque.size(); i++)
    {
        cout << deque[i] << tab;
    }
    cout << endl;
    deque.push_front(2);
    deque.push_front(1);
    deque.push_front(1);
    deque.push_front(0);
    for (int i : deque)
        cout << i << tab;
    cout << endl;
#endif

#ifdef LIST
    std::list<int> doublyList = {2, 6, 84, 35, 23, 77, 54};

    if (!(doublyList.empty()))
    {

        for (int i : doublyList)
        {
            cout << i << endl;
        }
        std::cout << std::endl;

        std::cout << "Size: " << doublyList.size() << endl;
        std::cout << "Max Size: " << doublyList.max_size() << endl;
        std::cout << std::endl;
        int index, value;
        std::cout << "Enter index to insert: ";
        cin >> index;
        std::cout << "Enter value to insert: ";
        cin >> value;
        std::list<int>::iterator it = doublyList.begin();
        std::advance(it, index);
        doublyList.insert(it, value);
        std::cout << std::endl;
        for (int i : doublyList)
        {
            cout << i << endl;
        }

        doublyList.sort();

        cout << "Sorted: " << endl;

        for (int i : doublyList)
        {
            cout << i << endl;
        }

        cout << "Enter index to remove: ";
        cin >> index;

        std::list<int>::iterator it2 = doublyList.begin();
        std::advance(it2, index);

        doublyList.erase(it2);

        cout << "Removed: " << endl;

        for (int i : doublyList)
        {
            cout << i << endl;
        }
    }
    else
    {
        std::cerr << "List is empty!!" << std::endl;
    }

#endif

#ifdef FORWARD_LIST
    std::forward_list<int> mylist = {4, 3, 2, 8, 5, 3};

    for (int i : mylist)
    {
        cout << i << endl;
    }
    int index, value;
    cout << "Enter index: ";
    cin >> index;
    cout << "Enter value: ";
    cin >> value;
    std::forward_list<int>::iterator it = mylist.begin();
    std::advance(it, index);

    mylist.insert_after(it, value);

    cout << "Insterted: " << endl;
    for (int i : mylist)
    {
        cout << i << endl;
    }

#endif // DEBUG

    return 0;
}