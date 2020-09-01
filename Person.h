#include <iostream>
using namespace std;

class Person {
public:
    string firstName, lastname, address, city, state, zip, phone;
    
    Person(string personDetails[]) {
        this->firstName = personDetails[0];
        this->lastname = personDetails[1];
        this->address = personDetails[2];
        this->city = personDetails[3];
        this->state = personDetails[4];
        this->zip = personDetails[5];
        this->phone = personDetails[6];
    }
};