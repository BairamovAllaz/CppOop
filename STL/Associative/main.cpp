#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <list>
using namespace std;
// #define STL_SET
// #define STL_MAP
#define STL_MAP_CHECK
int main()
{
#ifdef STL_SET
    /// set and multiset is binarry search tree
    // std::set<int> myset = {50, 43, 23, 56, 50, 43, 21};                          //set is unique tree
    std::multiset<int> mymultiset = {50, 50, 50, 32, 43, 21, 24}; // multiset is not unique

    // for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    // {
    //     cout << *it << endl;
    // }

    for (int i : mymultiset)
    {
        cout << i << endl;
    }

    int value;
    cout << "Enter value to insert: ";
    cin >> value;
    mymultiset.insert(value);

    for (int i : mymultiset)
    {
        cout << i << endl;
    }
    cout << "Enter value to delete: ";
    cin >> value;
    mymultiset.erase(value);
    for (int i : mymultiset)
    {
        cout << i << endl;
    }

    // cout << endl;

    // for (std::multiset<int>::iterator it = mymultiset.lower_bound(43); it != mymultiset.upper_bound(24); ++it)
    // {
    //     cout << *it << endl;
    // }

#endif

#ifdef STL_MAP
    // std::map<int,std::string> week =
    // {
    //     std::pair<int,std::string>(0,"Sunday"),
    //     std::pair<int,std::string>(1,"Monday"),
    //     std::pair<int,std::string>(2,"Teusday"),
    //     std::pair<int,std::string>(3,"Wednsday"),
    //     std::pair<int,std::string>(4,"Thurday"),
    //     std::pair<int,std::string>(5,"Friday"),
    //     std::pair<int,std::string>(6,"Saturday"),
    // }
    std::map<int, std::string> week = {
        {0, "Sunday"},
        {1, "Monday"},
        {2, "Tuesday"},
        {3, "Wednsday"},
        {4, "Thuseday"},
        {5, "Friday"},
        {6, "Saturday"},
    };
    // for(std::map<int,std::string>::iterator it = week.begin();it != week.end();++it) {
    //     cout << it->first << '\t' << it->second << endl;
    // }
    for (const auto &i : week)
    {
        cout << i.first << '\t' << i.second << endl;
    }

#endif

#ifdef STL_MAP_CHECK
    std::map<std::string, std::list<std::string>>
        dic = {
            {"1", {"0"}},
            {"2", {"1"}},
            {"3", {"3"}},
        };


    // for (std::map<std::string, std::list<std::string>>::iterator it = dic.begin(); it != dic.end(); ++it)
    // {
    //     cout << it->first << "\t";
    //     for (std::list<std::string>::iterator git = it->second.begin(); git != it->second.end(); ++git)
    //     {
    //         cout << *git << endl;
    //     }
    //     cout << endl;
    // }

    // for (const auto &i : dic)
    // {
    //     cout << i.first << endl;
    //     for (std::string k : i.second)
    //     {
    //         cout << k << endl;
    //     }
    //     cout << endl;
    // }


    for(std::pair<std::string,std::list<std::string>>i : dic){
        cout << i.first << endl; 
        for(std::string k : i.second) { 
            cout << k << endl;
        }
     }

#endif

    return 0;
}