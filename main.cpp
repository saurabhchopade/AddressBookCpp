#include <iostream>
#include "Person.h"
#include "InputUtil.h"
#include "AddressBook.h"
using namespace std;

void addPerson(AddressBook &addressBook) {
    string firstName, lastname, address, city, state, zip, phone; 
    InputUtil input;
    
    firstName = input.getFirstName();
    lastname = input.getLastName();
    address = input.getAddress();
    city = input.getCity();
    state = input.getState();
    zip = input.getZip();
    phone = input.getPhone();
  
    Person person(firstName, lastname, address, city, state, zip, phone);
    addressBook.addPerson(person);
}

void userChoice() {
    while (true) {
        int option;
        AddressBook addressBook;
       
        cout << endl << endl;
        cout << "==== CHOOSE OPTION ====" << endl;
        cout << "1) AddPerson : " << endl;
        cout << "2) DisplayDetails : " << endl;
        cout << endl << endl;
        cout << "Enter Option : ";
        cin>> option;

        switch (option) {
            case 1: {
                addPerson(addressBook);
                break;
            }    
            case 2: {
                addressBook.display();
                break;
            }    
            default: {
                cout << "Choose Correct Option";
                break;
            }    
        }
    }    
}
int main() {
    userChoice();
}