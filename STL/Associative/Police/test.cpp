
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // char str[] = " 1 ленина, 2 фрунзе;";
    // char str[] = " 1 ленина, 2 фрунзе, 4 leninskiy, 5 vetranov;";
    char str[] = "	1 ленина, 2 фрунзе;";
    char *pc;

    pc = strtok(str, ";");

    std::string id, street;
    // char id[10], street[100];

    while (pc != NULL)
    {
        id = strtok(pc, " ");
        cout << "ID: " << id << endl;
        street = strtok(NULL, ",");
        cout << "Street: " << street << endl;
        pc = strtok(NULL, ";");
    }
    // cout << "Id: " << id << endl;
    // id = strtok(pc, " ");
    // cout << "Id: " << id << endl;
    // street = strtok(NULL, ";");
    // cout<< "Street: " << street << endl;
    // strcpy(id,strtok(pc, " "));
    // strcpy(street,strtok(NULL," "));
    // id = ;
    // street = strtok(NULL,";");

    // for(char *k = strtok(pc,"    ;");k!= NULL;k=strtok(NULL,";"))  {
    //     cout << k << endl;
    // }

    // cout << "id: " << id << endl;
    // cout << "Street : " << street << endl;

    return 0;
}
