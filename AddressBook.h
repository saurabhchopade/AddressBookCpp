#include <iostream>
using namespace std;
#include <algorithm>
#include <list> 

class AddressBook {
public:
    string firstName, lastname, address, city, state, zip, phone;
    
    list <Person> personList; 
  
    void addPerson(Person);    
    void display();
    void updateDetails();
    void deleteRecord();
    bool checkPresent(string,string);
    void sortByName(int);
    void displayOutput(Person);
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
        for (auto personDetails: personList) {
            cout << "firstName : " <<  personDetails.firstName << endl;
            cout << "lastName  : " <<  personDetails.lastname << endl;
            cout << "address   : " <<  personDetails.address << endl;
            cout << "city      : " <<  personDetails.city << endl;
            cout << "state     : " <<  personDetails.state << endl;
            cout << "zip       : " <<  personDetails.zip << endl;
            cout << "phone     : " <<  personDetails.phone << endl;
            cout << endl << endl;
	    }
    }
}

void AddressBook :: updateDetails() {
    InputUtil input;
    string name;
 
    cout << "Enter Name To update Details";
    cin >> name;
    
    for (auto personItr = personList.begin(); personItr != personList.end(); personItr++) { 
       
        if(personItr->firstName == name) {
            personItr->firstName = name;
            personItr->lastname = input.getLastName();  
            personItr->address = input.getAddress();  
            personItr->city = input.getCity();  
            personItr->state = input.getState();  
            personItr->zip = input.getZip();  
            personItr->phone = input.getPhone();  
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

bool AddressBook :: checkPresent(string fName, string lName) {
    for (auto personInfo: personList) {
        if(personInfo.firstName == fName && personInfo.lastname == lName) {
            return true;
        }
    }
    return false;
}

void AddressBook :: sortByName(int option) {
    string *sortData = new string[personList.size()];
    int counter = 0;
    for (auto personInfo: personList) {
        switch (option) {
        case 1:
            sortData[counter] = personInfo.firstName;
            break;
        case 2:
            sortData[counter] = personInfo.city;
            break;
        case 3:
            sortData[counter] = personInfo.state;
            break;
        case 4:
            sortData[counter] = personInfo.zip;
            break;    
        default:
            break;
        }
        counter++;
    }

    sort(sortData, sortData + personList.size());

    for (int recordNo = 0; recordNo < counter; recordNo++) {
        for (auto personInfo: personList) {
            switch (option) {
                case 1:
                    if(sortData[recordNo] == personInfo.firstName)
                        displayOutput(personInfo);
                    break;
                case 2:
                    if(sortData[recordNo] == personInfo.city)
                        displayOutput(personInfo);
                    break;
                case 3:
                    if(sortData[recordNo] == personInfo.state)
                        displayOutput(personInfo);
                    break;
                case 4:
                    if(sortData[recordNo] == personInfo.zip)
                        displayOutput(personInfo);
                    break;    
                default:
                    break;
             }
        
        }
    }         
}

void AddressBook :: displayOutput(Person personInfo) {

    cout << "firstName : " <<  personInfo.firstName << endl;
    cout << "lastName  : " <<  personInfo.lastname << endl;
    cout << "address   : " <<  personInfo.address << endl;
    cout << "city      : " <<  personInfo.city << endl;
    cout << "state     : " <<  personInfo.state << endl;
    cout << "zip       : " <<  personInfo.zip << endl;
    cout << "phone     : " <<  personInfo.phone << endl;
    cout << endl << endl;
}
