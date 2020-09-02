#include <iostream>
using namespace std;
#include <algorithm>
#include <list> 
#include <map> 

class AddressBook {
public:
    string firstName, lastname, address, city, state, zip, phone;
    
    list <Person> personList; 
    map<string,string> choiceWiseData;

    void addPerson(Person);    
    void display();
    void updateDetails();
    void deleteRecord();
    bool checkPresent(string,string);
    void sortByChoice(int);
    void displayOutput(Person);
    void displaySortedData(string[],int);
    void viewByCityAndState();
    void insertAsPerCityOrState(int, string, Person);
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

void AddressBook :: sortByChoice(int option) {
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
    displaySortedData(sortData,option);
}

void AddressBook :: displaySortedData(string sortData[], int option){
    for (int recordNo = 0; recordNo < personList.size(); recordNo++) {
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

void AddressBook :: viewByCityAndState() {
    string name;
    int choice;
  
    cout << "1) View By State         : " << endl;
    cout << "2) View By city          : " << endl;
    cin >> choice;
    cout << "Enter Name As Per Option : ";
    cin >> name;
  
    for (auto personInfo: personList) {
       insertAsPerCityOrState(choice, name, personInfo);
    }

    (choiceWiseData.empty() == true)? cout << "No Such Data Found " << endl : cout << "" ; 
}

void AddressBook :: insertAsPerCityOrState(int choice, string name, Person personInfo) {
     switch (choice){
            case 1:
                if(name == personInfo.state)
                    choiceWiseData.insert( { personInfo.firstName, personInfo.state });
                    cout << "PersonName = " << personInfo.firstName << " city Name = " << personInfo.city << endl;     
                break;
            case 2:
                if(name == personInfo.city)
                    choiceWiseData.insert( { personInfo.firstName, personInfo.city });  
                    cout << "PersonName = " << personInfo.firstName << " city Name = " << personInfo.city << endl;     
                break;            
            default:
                cout << "Wrong Option";
                break;
        }
}
