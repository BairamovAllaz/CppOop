#include <iostream>
#include <map>
#include <cstring>
#include <list>
using namespace std;
//this file only working in c++ version 17!
int main()
{

    std::map<int, std::list<double>> QAI;
    int operation;

    cout << "1: Insert Element , 2: Print Element, 3: Print singl element , 4 : Print diapozan, 5: print from index , 6 : Exit ";
    cin >> operation;

    while (operation > 6)
    {
        cout << "Enter operation again" << endl;
    }

    while (true)
    {
        if (operation == 6)
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
        case 3: { 
            int key;
            cout << "Enter a car number to print: "; cin >> key;
            std::map<int, std::list<double>>::iterator it = QAI.find(key);
            
            if(it != QAI.end()) {
                cout << it->first << " ----- ";
                for(double i : it->second){
                    cout << i << " ";
                }
                cout << endl;
            }else{
                cout << "There not car in this number" << endl;   
            }
            break;
        }
        
        case 4: { 
            int a,b;
            cout << "Enter start element: ";cin >> a;
            cout << "Enter end element: "; cin >> b; 
            
            for(std::map<int,std::list<double>>::iterator it = QAI.lower_bound(a);it != QAI.upper_bound(b);++it){
                cout << it->first << " ----- ";
                for(double i : it->second){ 
                    cout << i << " ";    
                }
                cout << endl;
            }
        }
        
        case 5: { 
            int index;
            cout << "Enter a index: ";cin >> index; 
            
            for(std::map<int,std::list<double>>::iterator it = QAI.lower_bound(index);it != QAI.end();++it){
                cout << it->first << " ----- ";
                for(double i : it->second){ 
                    cout << i << " ";    
                }
                cout << endl;
            }
        }
        default:
            break;
        }

        cout << "1: Insert Element , 2: Print Element, 3: Print singl element , 4 : Print diapozan, 5: print from index , 6 : Exit ";
        cin >> operation;
    }

    return 0;
}
