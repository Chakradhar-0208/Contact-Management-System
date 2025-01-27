#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
struct Contact {
    string name;
    string phone;
    string address;
    string email;
};
class ContactManager {
private:
    vector<Contact> contacts;
    const string filename = "contacts.txt";

    void loadContacts() {
        ifstream file(filename);
        if (file.is_open()) {
            Contact contact;
            while (getline(file, contact.name)) {
                file>>contact.phone;
                file>>contact.address;
                file>>contact.email;
                contacts.push_back(contact);
            }
            file.close();
        }
    }

    void saveContacts() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.name << endl;
                file << contact.phone << endl;
                file << contact.address << endl;
                file << contact.email << endl;
            }
            file.close();
        }
    }

public:
    ContactManager() {
        loadContacts();
    }

    ~ContactManager() {
        saveContacts();
    }

    void addContact() {
        Contact contact;
        cout << "Enter name: ";
        cin.ignore();
        cin>>contact.name;
        cout << "Enter phone: ";
        cin>>contact.phone;
        cout<<"Enter address: ";
        cin>>contact.address;
        cout << "Enter email: ";
        cin>>contact.email;
        contacts.push_back(contact);
        cout << "Contact added successfully!" << endl;
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "No contacts to display." << endl;
            return;
        }
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << "\nPhone: " << contact.phone<<"\nAddress: "<<contact.address << "\nEmail: " << contact.email << endl << endl;
        }
    }

    void searchContact() {
        string searchName;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, searchName);
        for (const auto& contact : contacts) {
            if (contact.name == searchName) {
                cout << "Contact found:\n";
                cout << "Name: " << contact.name << "\nPhone: " << contact.phone<<"\nAddress: "<<contact.address  << "\nEmail: " << contact.email << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    void editContact() {
        string searchName;
        cout << "Enter name of the contact to edit: ";
        cin.ignore();
        getline(cin, searchName);
        for (auto& contact : contacts) {
            if (contact.name == searchName) {
                cout << "Contact found:\n";
                cout << "Name: " << contact.name << "\nPhone: " << contact.phone <<"\nAddress: "<<contact.address << "\nEmail: " << contact.email << endl;

                cout << "Enter new name (or press Enter to keep current): ";
                string newName;
                cin>>newName;
                if (!newName.empty()) contact.name = newName;

                cout << "Enter new phone (or press Enter to keep current): ";
                string newPhone;
                cin>>newPhone;
                if (!newPhone.empty()) contact.phone = newPhone;

                cout << "Enter new email (or press Enter to keep current): ";
                string newEmail;
                cin>>newEmail;
                if (!newEmail.empty()) contact.email = newEmail;

                cout << "Contact updated successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }
};

int main() {
    ContactManager cm;
    int choice;

    do {
        cout << "\n\t\t******Welcome to contact manager Contact Management System******\n\n";
        cout<<"\n=====================\n\tMain menu\n=====================\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Exit\n=====================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cm.addContact(); break;
            case 2: cout<<"\n\tList of contacts\n======================\n";cm.displayContacts(); break;
            case 3: cm.searchContact(); break;
            case 4: cm.editContact(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
