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

    std::map<int, std::list<double>> QAI;
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
            int key, law;
            cout << "Enter a car number: ";
            cin >> key;
            cout << "Enter law: ";
            cin >> law;
            std::map<int, std::list<double>>::iterator it = QAI.find(key);
            std::list<double> mylist;
            if (it != QAI.end())
            {
                it->second.push_back(law);
                mylist = it->second;
            }
            else
            {
                std::list<double> l;
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
                for (double i : node.second)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            break;
        }
        case 3:
        {
            int key;
            cout << "Enter a car number to print: ";
            cin >> key;
            std::map<int, std::list<double>>::iterator it = QAI.find(key);

            if (it != QAI.end())
            {
                cout << it->first << " ----- ";
                for (double i : it->second)
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
            int a, b;
            cout << "Enter start element: ";
            cin >> a;
            cout << "Enter end element: ";
            cin >> b;

            for (std::map<int, std::list<double>>::iterator it = QAI.lower_bound(a); it != QAI.upper_bound(b); ++it)
            {
                cout << it->first << " ----- ";
                for (double i : it->second)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }

        case 5:
        {
            int index;
            cout << "Enter a index: ";
            cin >> index;

            for (std::map<int, std::list<double>>::iterator it = QAI.lower_bound(index); it != QAI.end(); ++it)
            {
                cout << it->first << " ----- ";
                for (double i : it->second)
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
                    for (double inttemp : temp.second)
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
            std::ifstream myfile("file.txt");
            std::string line;
            int linesize = 0;
            if (myfile.is_open())
            {
                while (std::getline(myfile, line))
                {
                    cout << line << endl;
                    ++linesize;
                }

                myfile.clear();
                myfile.seekg(0);
                cout << endl;
                for (int i = 0; i < linesize; ++i)
                {

                    int key;
                    std::list<double> mylist;
                    std::getline(myfile, line, ':');
                    key = stoi(line);
                    std::string buffer;
                    std::getline(myfile, buffer);
                    double buf = std::stod(buffer);
                    cout << "Buf : " << buf << endl;
                    mylist.push_back(buf);
                    QAI.insert_or_assign(key, mylist);
                }
            }
            else
            {
                std::cerr << "file is not founded" << endl;
            }
            myfile.close();
        }

        default:
            break;
        }

        cout << "1: Insert Element , 2: Print Element, 3: Print singl element , 4 : Print diapozan, 5: print from index , 6 : write to file , 7  : Read from file! , 8 : exit ";
        cin >> operation;
    }

    return 0;
}
