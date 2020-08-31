#include <iostream>
using namespace std;

class AddressBook
{
public:
    string firstName, lastname, address, city, state, zip, phone;
  
    Person *person;
    
    void addPerson(Person);
    void display();
};

void AddressBook :: addPerson(Person person) {
    this -> person = new Person(person);
}

void AddressBook :: display() {
    cout << endl << endl;
    cout << "firstName : " <<  person->firstName << endl;
    cout << "lastName  : " <<  person->lastname << endl;
    cout << "address   : " <<  person->address << endl;
    cout << "city      : " <<  person->city << endl;
    cout << "state     : " <<  person->state << endl;
    cout << "zip       : " <<  person->zip << endl;
    cout << "phone     : " <<  person->phone << endl;
}