#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

        Prep(int data)                                     // Parameritized Constuctor
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