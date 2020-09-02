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

void displayOptions(){
        cout << endl << endl;
        cout << "==== CHOOSE OPTION ====" << endl;
        cout << "1) AddPerson        : " << endl;
        cout << "2) DisplayDetails   : " << endl;
        cout << "3) UpdateDetails    : " << endl;
        cout << "4) DeleteRecord     : " << endl;
        cout << "5) SortByFirstName  : " << endl;
        cout << "6) SortByCity       : " << endl;
        cout << "7) SortByState      : " << endl;
        cout << "8) SortByZip        : " << endl;
        cout << "9) ViewByCity&State : " << endl;
        cout << endl << endl;
        cout << "Enter Option         : ";
}

void userChoice() {
    AddressBook addressBook;
    while (true) {
        int option;
        cin>> option;
        displayOptions();
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
            case 5: {
                int byFirstName = 1;
                addressBook.sortByChoice(byFirstName);
                break;
            }    
            case 6: {
                int byCity = 2;
                addressBook.sortByChoice(byCity);
                break;
            }    
            case 7: {
                int byState = 3;
                addressBook.sortByChoice(byState);
                break;
            }    
            case 8: {
                int byZip = 4;
                addressBook.sortByChoice(byZip);
                break;
            }    
            case 9: {
                int byZip = 4;
                addressBook.viewByCityAndState();
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