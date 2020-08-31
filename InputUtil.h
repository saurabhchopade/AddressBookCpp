#include <iostream>
using namespace std;

class InputUtil {
public:
    string inputString;

    string getFirstName() {
        cout << "Enter FirstName : ";
        cin >> inputString;
        return inputString;
    }

    string getLastName() {
        cout << "Enter LastName : ";
        cin >> inputString;
        return inputString;
    }

    string getAddress() {
        cout << "Enter Address : ";
        cin >> inputString;
        return inputString;
    }

    string getCity() {
        cout << "Enter City : ";
        cin >> inputString;
        return inputString;
    }

    string getState() {
        cout << "Enter State : ";
        cin >> inputString;
        return inputString;
    }

    string getZip() {
        cout << "Enter Zip : ";
        cin >> inputString;
        return inputString;
    }
    
    string getPhone() {
        cout << "Enter Phone : ";
        cin >> inputString;
        return inputString;
    }
};
