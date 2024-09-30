#include <iostream>
#include "addressBookType.h"

void showMenu() {
    std::cout << "On-line Address Book\n";
    std::cout << "Select an option:\n";
    std::cout << "1 - Display all entries\n";
    std::cout << "2 - Display entry by last name\n";
    std::cout << "3 - Display all entries by birth month\n";
    std::cout << "4 - Display all entries by relationship\n";
    std::cout << "5 - Quit\n";
}

int main() {
    std::cout << "Initializing address book...\n";
    addressBookType myAddressBook(100); // Initialize with size 100

    std::cout << "Loading address book data...\n";
    myAddressBook.initEntry("addressbookdata.txt"); // Load entries from the file

    std::cout << "Address book loaded successfully.\n";

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Displaying all entries:\n";
                myAddressBook.print();
                break;
            case 2: {
                std::string lastName;
                std::cout << "Enter last name: ";
                std::cin >> lastName;
                std::cout << "Searching for person with last name: " << lastName << "\n";
                myAddressBook.findPerson(lastName);
                break;
            }
            case 3: {
                int month;
                std::cout << "Enter birth month (1-12): ";
                std::cin >> month;
                std::cout << "Searching for birthdays in month: " << month << "\n";
                myAddressBook.findBirthdays(month);
                break;
            }
            case 4: {
                std::string relation;
                std::cout << "Enter relationship (Business, Friend, Family): ";
                std::cin >> relation;
                std::cout << "Searching for persons with relationship: " << relation << "\n";
                myAddressBook.findRelations(relation);
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid option, try again.\n";
        }

    } while (choice != 5);

    return 0;
}
