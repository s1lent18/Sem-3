#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Copy Constructor vs Assignment Operator

// copy constructor is called when a new object is created from an existing object
// as a copy of the existing object

// assignment operator is called when an already initialized object is assigned
// a new value form another existing object

// Deep Copy vs Shallow Copy

// Deep Copy:
//      The Copy constructor is basically an overloaded constructor
//      This initializes the new object with already existing object
//      Copy Constructor is used when a new object is created with some existing object
//      Both the objects use seperate memory locations
//      if no copy constructor is defined in the class the compier provides one

// Assignment Operator:
//      Assignment operator is basically an operator
//      this assigns the value of one object to another object both of which already exists
//      This operator is used when we want to assign existing object to new object
//      one memory location is used but different reference variables are pointing to the same location 
//      if the assignment operator is not overloaded then bitwise copy will be made
//Rule of Three




class Prep
{
    private:
        int data;

    public:
        Prep()                                             // Default Constructor
        {
            cout << "Normal Constructor" << endl;

            data = 0;
        }

        Prep(int data):data(data) // <- initializer list   // Parameritized Constuctor
        {
            this->data = data;
        }

        Prep(Prep & obj)                                   // Copy Constructor
        {
            data = obj.data;

            cout << "Copy Contructor Called " << endl;
        }
 
        Prep & operator = (const Prep & obj)               // Assignment operator
        {
            data = obj.data;    

            return *this;
        }

        void display()
        {
            cout << "Data: " << data << endl;
        }
};

void helloworld()
{
    cout << "Hello World " << endl;
}

// reasons to use function pointer:
// - we can use it to define functions as a parameter to another function
// Example:

void printvalue(int value)
{
    cout << " The value is: " << value << endl;
}

void Foreach(vector<int> & values, void(*func)(int))
{
    for(int value : values)
        func(value);
}

int main()
{
    Prep T(5);

    Prep T4(10);

    T.display();

    Prep T1;

    T1 = T;

    Prep T2 = T4;

    T1.display();
    T2.display();
    
    void(*newfunction)() = &helloworld;                       // definition of a function pointer

    auto function = &helloworld;                            // definition of a function pointer

    function();

    newfunction();

    vector <int> values = {1, 2, 3 ,4, 5};

    Foreach(values, printvalue);

    Foreach(values, [](int value) {cout << " The value is " << value << endl; });

    // the above line of code can be used when you don't want to declare a function is
    // of one time use so u declare it like this

}