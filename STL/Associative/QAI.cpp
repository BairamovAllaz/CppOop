#include <iostream>
#include <map>
#include <cstring>
#include <list>
#include <fstream>
#include <string>
using namespace std;
// this file only working in c++ version 17!
int main()
{

    std::map<std::string, std::list<std::string>> QAI;
    int operation;

    cout << "1: Insert Element , 2: Print Element, 3: Print singl element , 4 : Print diapozan, 5: print from index , 6 : write to file , 7  : Read from file! , 8 : exit ";
    cin >> operation;

    while (operation > 8)
    {
        cout << "Enter operation again" << endl;
    }

    while (true)
    {
        if (operation == 8)
        {
            break;
        }

        switch (operation)
        {
        case 1:
        {
            std::string key, law;
            cout << "Enter a car number: ";
            // cin >> key;
            cin.ignore();
            std::getline(cin, key);
            cout << "Enter law: ";
            // cin >> law;
            cin.ignore();
            std::getline(cin, law);
            std::map<std::string, std::list<std::string>>::iterator it = QAI.find(key);
            std::list<std::string> mylist;
            if (it != QAI.end())
            {
                it->second.push_back(law);
                mylist = it->second;
            }
            else
            {
                std::list<std::string> l;
                l.push_back(law);
                mylist = l;
            }

            QAI.insert_or_assign(key, mylist);

            cout << endl;
            break;
        }
        case 2:
        {
            for (const auto &node : QAI)
            {
                cout << node.first << " --- ";
                for (std::string i : node.second)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            break;
        }
        case 3:
        {
            std::string key;
            cout << "Enter a car number to print: ";
            // cin >> key;
            cin.ignore();
            std::getline(cin, key);
            std::map<std::string, std::list<std::string>>::iterator it = QAI.find(key);

            if (it != QAI.end())
            {
                cout << it->first << " ----- ";
                for (std::string i : it->second)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "There not car in this number" << endl;
            }
            break;
        }

        case 4:
        {
            std::string a, b;
            cout << "Enter start element: ";
            // cin >> a;
            cin.ignore();
            std::getline(cin, a);
            cout << "Enter end element: ";
            // cin >> b;
            cin.ignore();
            std::getline(cin, b);

            for (std::map<std::string, std::list<std::string>>::iterator it = QAI.lower_bound(a); it != QAI.upper_bound(b); ++it)
            {
                cout << it->first << " ----- ";
                for (std::string i : it->second)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }

        case 5:
        {
            std::string index;
            cout << "Enter a index: ";
            // cin >> index;
            cin.ignore();
            std::getline(cin, index);

            for (std::map<std::string, std::list<std::string>>::iterator it = QAI.lower_bound(index); it != QAI.end(); ++it)
            {
                cout << it->first << " ----- ";
                for (std::string i : it->second)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            break;
        }
        case 6:
        {
            std::ofstream myfile("file.txt");
            if (myfile.is_open())
            {
                for (const auto &temp : QAI)
                {
                    myfile << temp.first << ":";
                    for (std::string inttemp : temp.second)
                    {
                        myfile << inttemp << ",";
                    }
                    myfile << endl;
                }
                myfile.close();
                system("start notepad file.txt");
            }
            else
            {
                std::cerr << "File is not found!" << endl;
            }
            break;
        }
        case 7:
        {
            // std::ifstream myfile("file.txt");
            // std::string line;
            // int linesize = 0;
            // if (myfile.is_open())
            // {
            //     while (std::getline(myfile, line))
            //     {
            //         cout << line << endl;
            //         ++linesize;
            //     }

            //     myfile.clear();
            //     myfile.seekg(0);
            //     cout << endl;
            //     for (int i = 0; i < linesize; ++i)
            //     {

            //         int key;
            //         std::list<std::string> mylist;
            //         std::getline(myfile, line, ':');
            //         key = stoi(line);
            //         std::string buffer;
            //         std::getline(myfile, buffer);
            //         double buf = std::stod(buffer);
            //         cout << "Buf : " << buf << endl;
            //         mylist.push_back(buf);
            //         QAI.insert_or_assign(key, mylist);
            //     }
            // }
            // else
            // {
            //     std::cerr << "file is not founded" << endl;
            // }
            // myfile.close();
            cout << "Helo" << endl;
            break;
        }

        default:
            break;
        }

        cout << "1: Insert Element , 2: Print Element, 3: Print singl element , 4 : Print diapozan, 5: print from index , 6 : write to file , 7  : Read from file! , 8 : exit ";
        cin >> operation;
    }

    return 0;
}
