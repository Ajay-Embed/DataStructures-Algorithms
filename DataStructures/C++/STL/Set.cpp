/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
#include <functional>

using namespace std;

class Person
{
public:
    float age;
    string name;
    bool operator<(const Person &rhs) const { return age > rhs.age; }
};
int main()
{
    Person p1 = {22, "shivam"}, p2 = {24, "paras"}, p3 = {25, "ajay"};
    set<Person> Set1;
    Set1.insert(p1);
    Set1.insert(p2);
    Set1.insert(p3);
    set<Person>::iterator i;
    for (i = Set1.begin(); i != Set1.end(); i++)
        cout << (*i).age << " " << (*i).name << "\n";
    return 0;
}
