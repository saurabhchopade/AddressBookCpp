#include <iostream>
using namespace std;

class AddressBook {
public:
    string firstName, lastname, address, city, state, zip, phone;
  
    Person *person;

    void addPerson(Person);    
    void display();
    void updateDetails();
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

void AddressBook :: updateDetails() {
    InputUtil input;
    person->firstName = input.getLastName();  
    person->address = input.getAddress();  
    person->city = input.getCity();  
    person->state = input.getState();  
    person->zip = input.getZip();  
    person->phone = input.getPhone();  
}