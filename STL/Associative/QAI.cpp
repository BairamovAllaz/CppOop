#include <iostream>
#include <map>
#include <cstring>
#include <list>
using namespace std;

// void printResult(const int &node)
// {
//     cout << node.first << " " << node.second << endl;
// }

int main()
{
    std::map<int, std::list<double>> QAI;
    int key, law;

    cout << "Enter a car number: ";
    cin >> key;
    cout << "Enter law: ";
    cin >> law;

    // QAI.insert_or_assign(275, 635);
    QAI.insert({3, {3, 5}});
    QAI.insert({7, {6, 8}});
    QAI.insert({9, {3, 2}});

    for (const auto &node : QAI)
    {
        cout << node.first;
        for (int i : node.second)
        {
            cout << i << endl;
        }
        cout << endl;
    }
    // std::list<double> it = {2,3,5,6};
    // QAI.insert_or_assign(7,it);

    std::map<int, std::list<double>>::iterator it = QAI.find(4);

    cout << endl;

    it->second.push_back(99);
    for (const auto &i : it->second)
    {
        cout << i << endl;
    }

    QAI.insert_or_assign(4, it->second);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << endl;
    for (const auto &node : QAI)
    {
        cout << node.first;
        for (const auto &i : node.second)
        {
            cout << i << endl;
        }
        cout << endl;
    }

    return 0;
}