#include "stdrfx.h"
#include "List.h"
#include "ListMethods.cpp"
#include "ElementMethods.cpp"
#include "Iterators.cpp"

// #define BASE_CHECK
// #define RANGE_BASED_FOR
int main()
{
    srand(time(0));
#ifdef RANGE_BASED_FOR
    List<int> list = {2, 4, 5, 6};
    // for (List<int>::ConstIterator it = list.cbegin(); it != nullptr; ++it)
    // {
    //     std::cout << *it << endl;
    // }
    // for (List<int>::ConstIterator it = list.cbegin(); it != nullptr; ++it)
    // {
    //     std::cout << *it << endl;
    // }

    for (int i : list)
    {
        cout << i << endl;
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
    // List<string> list = {"Allaz", "Bairamov"};
    // for (string i : list)
    // {
    //     cout << i << endl;
    // }
    List<double> list = {0.4, 5.4, 3.4, 5.7};
    for (double i : list)
    {
        cout << i << endl;
    }

    list.push_back(100.5);
    for (double i : list)
    {
        cout << i << endl;
    }

    return 0;
}
