/*

## Constructor :- hidden function that allocated memory and object initilize
                - used to  create object
                - constructor is called when any object is created.
                - By Defualt its present ;
                - very very similar to function;
                - its  reutrn classtype types;
                - it has no name;
                - within the class it would be
                - Same name as class

        1. Default Constructor - no parameter

        2. parameterized COnstructor - parameter Available

        3. Copy Constructor - 
*/
#include<iostream>
using namespace std;

class bike {
public:
    int tyreSize;

    // Default Constructor
    bike() {
        cout << "Constructor is called" << endl;
    }

    // Parameterized Constructor
    bike(int a, int b = 100) {
        this->tyreSize = a;  // Corrected assignment
        cout << "Parameterized Constructor is called" << endl;
    }

    // Copy Constructor (Call by Reference)
    bike(const bike &b) {  // `const` is recommended
        cout << "Copy Constructor is called" << endl;
    }
};

int main() {
    bike tvs;             // Default Constructor
    bike honda(500, 4);   // Parameterized Constructor
    bike b1;              // Default Constructor
    bike b2 = b1;         // Copy Constructor
    bike b3(b1);          // Copy Constructor (Corrected)
}
