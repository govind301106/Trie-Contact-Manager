#include "ContactManager.h"
#include <iostream>

using namespace std;

int main() {

    ContactManager cm;
    int choice;

    while (true) {

        cout << "\n====== Trie Contact Manager ======\n";
        cout << "1. Add Contact\n";
        cout << "2. Delete Contact\n";
        cout << "3. Update Contact\n";
        cout << "4. Search By Name\n";
        cout << "5. Search By Phone\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice) {

        case 1: {
            string name, phone;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Phone: ";
            cin >> phone;
            cm.addContact(name, phone);
            break;
        }

        case 2: {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            cm.deleteContact(name);
            break;
        }

        case 3: {
            string name, newPhone;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter New Phone: ";
            cin >> newPhone;
            cm.updateContact(name, newPhone);
            break;
        }

        case 4: {
            string prefix;
            cout << "Enter Name Prefix: ";
            cin >> prefix;
            cm.searchByName(prefix);
            break;
        }

        case 5: {
            string prefix;
            cout << "Enter Phone Prefix: ";
            cin >> prefix;
            cm.searchByPhone(prefix);
            break;
        }

        case 6:
            cout << "Thank You!\n";
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }
}