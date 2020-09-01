#include <iostream>
using namespace std;

class InputUtil {
public:
    string inputString;

    string getFirstName() {
        cout << endl << "Enter FirstName : ";
        cin >> inputString;
        return inputString;
    }

    string getLastName() {
        cout << endl << "Enter LastName : ";
        cin >> inputString;
        return inputString;
    }

    string getAddress() {
        cout << endl << "Enter Address : ";
        cin >> inputString;
        return inputString;
    }

    string getCity() {
        cout << endl << "Enter City : ";
        cin >> inputString;
        return inputString;
    }

    string getState() {
        cout << endl << "Enter State : ";
        cin >> inputString;
        return inputString;
    }

    string getZip() {
        cout << endl << "Enter Zip : ";
        cin >> inputString;
        return inputString;
    }
    
    string getPhone() {
        cout << endl << "Enter Phone : ";
        cin >> inputString;
        return inputString;
    }
};
