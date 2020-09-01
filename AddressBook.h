#include <iostream>
using namespace std;
#include <list> 

class AddressBook {
public:
    string firstName, lastname, address, city, state, zip, phone;
    
    list <Person> personList; 
  
    void addPerson(Person);    
    void display();
    void updateDetails();
    void deleteRecord();
};
  
void AddressBook :: addPerson(Person personn) {
    personList.insert(personList.begin(),personn);
    cout << personList.size();
}

void AddressBook :: display() {
    if (personList.empty() == true) {
        cout << "*Address Book Is Empty*";
    }
    else {
        for (auto index: personList) {
            cout << "firstName : " <<  index.firstName << endl;
            cout << "lastName  : " <<  index.lastname << endl;
            cout << "address   : " <<  index.address << endl;
            cout << "city      : " <<  index.city << endl;
            cout << "state     : " <<  index.state << endl;
            cout << "zip       : " <<  index.zip << endl;
            cout << "phone     : " <<  index.phone << endl;
            cout << endl << endl;
	    }
    }
}

void AddressBook :: updateDetails() {
    InputUtil input;
    string name;
 
    cout << "Enter Name To update Details";
    cin >> name;
    
    for (auto itr = personList.begin(); itr != personList.end(); itr++) { 
       
        if(itr->firstName == name) {
            itr->firstName = name;
            itr->lastname = input.getLastName();  
            itr->address = input.getAddress();  
            itr->city = input.getCity();  
            itr->state = input.getState();  
            itr->zip = input.getZip();  
            itr->phone = input.getPhone();  
         } 
    }
}

 void AddressBook :: deleteRecord() {
    int flag = 0;
    string fName, lName;
  
    cout << "Enter firstName   : ";
    cin >> fName;
    cout << "Enter lastName    : ";
    cin >> lName;

    list<Person>::const_iterator personItr = personList.cbegin();
	while (personItr != personList.cend())
	{
		if (personItr->firstName== fName) {
			personItr = personList.erase(personItr);
		}
		else {
			++personItr;
		}
	}
 }
