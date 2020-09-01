#include <iostream>
#include "Person.h"
#include "InputUtil.h"
#include "AddressBook.h"
using namespace std;

void addPerson(AddressBook &addressBook) {
    InputUtil input;
    string personDetails[7];
    
    while(true) {
        personDetails[0] = input.getFirstName();
        personDetails[1] = input.getLastName();
        if(addressBook.checkPresent(personDetails[0],personDetails[1])) {
            cout << "Record Already Present" << endl;
            continue;
        }
        break;
    }
    personDetails[2] = input.getAddress();
    personDetails[3] = input.getCity();
    personDetails[4] = input.getState();
    personDetails[5] = input.getZip();
    personDetails[6] = input.getPhone();
  
    Person person(personDetails);
    addressBook.addPerson(person);
}

void userChoice() {
    AddressBook addressBook;
    while (true) {
        int option;
       
        cout << endl << endl;
        cout << "==== CHOOSE OPTION ====" << endl;
        cout << "1) AddPerson      : " << endl;
        cout << "2) DisplayDetails : " << endl;
        cout << "3) UpdateDetails  : " << endl;
        cout << "4) DeleteRecord   : " << endl;
        cout << endl << endl;
        cout << "Enter Option     : ";
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
            case 3: {
                addressBook.updateDetails();
                break;
            } 
            case 4: {
                addressBook.deleteRecord();
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