#include "indexString.h"
#include "indexString.cpp"

// #define CONSTRUCTORS_CHECK
// #define CONSTRUCTORS_CHECK2
#define CONSTRUCTORS_CHECK3

int main()
{

#ifdef CONSTRUCTORS_CHECK
    String s;
    cout << "s: " << s << endl;
    String str1 = "Hello";
    String str2 = "World";
    cout << "Str1: " << str1 << endl;
    cout << "Str2: " << str2 << endl;
    cout << "Your string: " << str1.getStr() << endl;

    String copy = str2;
    cout << "Copy:" << copy << endl;
    // String str3 = str1 + str2;
    // cout << "Str3: " << str3 << endl;

    // String str4;
    // cout << "Enter str4: ";
    // cin >> str4;
    // cout << "Str4: " << str4 << endl;

    // String str5(25);
    // cout << "Nothing 2: " << endl;
    // cout << str5 << endl;

    String s7 = str1;
    cout << "S7: " << s7 << endl;

    String s8;
    s8 = s7;
    cout << "S8: " << s8 << endl;

#endif // DEBUG

#ifdef CONSTRUCTORS_CHECK2

    String str1("Hello");
    String str2("World");
    String str3 = str1 + str2;
    cout << str3 << endl;
    str1 += str2;
    cout << "Str1 : " << str1 << endl;
    String s4;
    cout << "Enter s4: ";
    getline(cin, s4);
    cout << "S4 : " << s4 << endl;

#endif // DEBUG

#ifdef CONSTRUCTORS_CHECK3
    String s(10);
    cout << "s : " << s << endl;
#endif // DEBUG
    return 0;
}