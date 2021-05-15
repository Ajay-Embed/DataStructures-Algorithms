# C++ : OOP & other features
This section aims to explain fundamentals of OOP using C++
We might add some new C++ features like smart pointers to this section as well.

## Principles of OOP in C++

1. Abstraction: Enjoy using functions without requiring to understand the implementation.

   E.g.: To use a TV's remote control, one doesn't need to know how it works. 
   One doesn't need to know implementation of printfto use it. 

   This ensures that only the essential information is accessible to the outside world while hiding 
   all the implementation details. 
 
2. Encapsulation: Wrap the data and functions that manipulate this data together into a class.

   This avoids mishandling of data, by "hiding" it. 
   E.g. A person from sales may require some information from the payroll section in a company. 
   The payroll section would not grant access to all the data they have, instead they would provide a 
   particular record/file.
 
   Note: This doesn't mean "securing" data at all.
 
   In c++, classes allow us to perform abstraction and data encapsulation. 

3. Polymorphism: Literally translates to "Many forms". This is like Bruce Wayne being Batman, same guy, 
   different forms i.e. same person behaves different in different situations. 

   In more technical terms, an operation may exhibit different behaviors in different instances. This
   behavior depends on the type of data used in the operations. 
 
   C++ allows overloading operators and functions at compile time. For e.g. the operator "<<" is 
   used with cout to print to the console, but it can also be used as a bitwise operator. The way
   we use it defines which "form" it will take. 

4. Inheritance: Capability of a "form" (as above) to be able to derive properties from a "base form". 
   For e.g. "Car" can be a base form, Honda City can be a particular form. So honda city will have features
   of a car and some special features of it's own.
   
   C++ allows the programmer to derive a class from a base class. Additionally it also has a feature
   called "Dynamic Binding", which allows functions to be overridden at runtime. (Virtual Functions).

This section aims to explain all the above principles of OOP practically in form of exemplary programs. 

