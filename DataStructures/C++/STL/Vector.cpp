//std::std::vector is a dynamic aaray or array list
//vector can grow or shrink dynamically
// Syntax std::vector<T> vec
//ELEMENT ACCESS---
//at(),front(),back()

//Element Insertion
//push_back

//Note:Vector provides us fast acccess to the element and can also grow and shrink dynamically.
//So in a way its combination of array and linked list as we can acccess a particular element without
//traversing the full list as done in array and can also keep the size dynamic as done in linked list.
//Vector = Linked List+Array

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    //Declarations
    std::vector<int> arr1;
    std::vector<int> arr2(5, 10);
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::vector<int> arr4{1, 2, 3, 4, 5};

    // Accessing Elemnts
    std::cout << arr3[0] << " ";       //1;
    std::cout << arr3.at(0) << " ";    //1;
    std::cout << arr3.front() << " ";  //1;
    std::cout << arr3.back() << " \n"; //5;

    // Vector size and capacity
    //Size means how elements my vector has at a particular time.
    //Capacity means how many elements my vector can hold at a particular time.
    for (int i = 0; i < 32; i++)
    {
        //arr1.reserve(32);
        //by adding this line we reserve the capacity of vector which means the vector will reserve 32 elements at once
        //instead of growing dynamically.Uncomment the above line and thrun the program to test.
        arr1.push_back(i);
        cout << "Size of array is " << arr1.size() << " Capcity of array is " << arr1.capacity() << "\n";
    }

    return 0;
}
