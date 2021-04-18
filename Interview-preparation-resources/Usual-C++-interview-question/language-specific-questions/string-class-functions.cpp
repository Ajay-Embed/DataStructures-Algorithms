//Usage of various functions available in string class in C++

#include <iostream>

using namespace std;

int main()
{
    //Initialiazing and declaring a string class object string_1
    string string_1 = "HelloWorld";
    cout << string_1 << endl;
    
    /*
    cout << "Enter the string you wish to enter" << endl;
    //The getline routine accepts whitespaces as well
    getline(cin, string_1);
    cout << string_1 << endl;
    */
    
    //Some functions which are available in the string class
    cout << "The length of the string is = " << string_1.length() << endl;
    
    cout << "The size of the string is = " << string_1.size() << endl;
    
    //to resize the string
    string_1.resize(3);
    cout << "The size of the string is = " << string_1.size() << endl;
    
    //For more information please refer - https://www.cs.fsu.edu/~myers/c++/notes/stringobj.html

    return 0;
}
