#include <iostream>

using namespace std;

/* Template classes are useful for defining
 * classes which are expected to be commonly
 * used with different data types, let's take
 * an example of a stack class. 
 *
 * A stack may be made all kinds of data types.
 * With the help of template classes we can
 * define a single class that can work for
 * all data types, i.e. primitive (int, double etc.)
 * & user defined(classes, structs etc).
 * Let's see an example.
 *
 */

template <class T>

class stack
{
    private:
        T *arr;
        int top;
        int size;

    public:
        stack(int sz)
        {
            size = sz;
            top = -1;
            arr = new T[size];
        }

     void push(T x);
     T pop();
};

/* This is a template function */
template <class T>
void stack<T>::push(T x)
{
    if(top==size-1)
        cout<<"Stack is Full";

    else
    {
        top++;
        arr[top]=x;
    }

}

/* This is a template function */
template <class T>
T stack<T>::pop()
{
    T x = 0; 

    if(top==-1)
    {
        cout<<"Stack Empty";
    }

    else
    {
        x=arr[top];
        top--; 
    }

    return x;
}

int main(void)
{
    stack<int> s(10);
    stack<float> f(10); 
    
    s.push(10);
    s.push(3);
    cout<<s.pop();

    return 0;
}
