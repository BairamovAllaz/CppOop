#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int arr[5] = {0,1,2,3,4};
    ofstream myfile;
    myfile.open("test.txt");

    for (size_t i = 0; i < 5; i++)
    {
        myfile << i << " - " << arr[i] << endl;
    }

    if(myfile.is_open()){ 
        cout << "Success" << endl;
    }    

    myfile.close(); 

    ///read file
    string line;
    ifstream readfile("test.txt"); 

    if(readfile.is_open()){ 
        while(getline(readfile,line)){ 
            cout << "Line: " << line << endl;
        }
        readfile.close();
    }else{
        cout << "Error when open file " << endl;
    }






    return 0;
    cout << "Hello cpp" << endl;
}