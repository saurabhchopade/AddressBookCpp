#include <iostream>
#include "InputUtil.h"
using namespace std;

class Person {
public:
    string firstName, lastname, address, city, state, zip, phone;

    void addPerson();
    void display();
};

    void Person :: addPerson() {
        Input input;
        firstName = input.getFirstName();
        lastname = input.getLastName();
        address = input.getAddress();
        city = input.getCity();
        state = input.getState();
        zip = input.getZip();
        phone = input.getPhone();
    }

    void Person  :: display() {
        cout << endl << endl;
        cout << "firstName : " << firstName << endl;
        cout << "lastName  : " << lastname << endl;
        cout << "address   : " << address << endl;
        cout << "city      : " << city << endl;
        cout << "state     : " << state << endl;
        cout << "zip       : " << zip << endl;
        cout << "phone     : " << phone << endl;
    }