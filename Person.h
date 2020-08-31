#include <iostream>
using namespace std;

class Person {
public:
    string firstName, lastname, address, city, state, zip, phone;
    
    Person(string firstName, string lastname, string address, string city, string state, string zip, string phone) {
        this->firstName = firstName;
        this->lastname = lastname;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phone = phone;
    }
};