#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "extPersonType.h" // Include the person class

class addressBookType {
private:
    extPersonType* addressList; // Dynamic array for storing extPersonType objects
    int length;                 // Number of entries currently in the address book
    int maxSize;                // Maximum capacity of the address book

public:
    // Constructor
    addressBookType(int size) {
        maxSize = size;
        length = 0;
        addressList = new extPersonType[maxSize];
    }

    // Destructor
    ~addressBookType() {
        delete[] addressList;
    }

    // Function to initialize entries from the file
void initEntry(const std::string& filename) {
    std::ifstream infile("addressBookData.txt");

    // Check if file opened successfully
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::cout << "File opened successfully.\n"; // Debug output

    std::string line;

    // Read each line from the file
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string fName, lName, rel;
        int month, day, year;

        // Parse the line into variables
        if (!(iss >> fName >> lName >> rel >> month >> day >> year)) {
            std::cerr << line << std::endl;
            continue; // Skip to the next line if there's an error
        }

        dateType birthDate(month, day, year);
        extPersonType newPerson(fName, lName, rel, birthDate);
        addEntry(newPerson);  // Add to addressList array
        std::cout << "Entry added: " << fName << " " << lName << std::endl;  // Debug output
    }

    infile.close();
    std::cout << "File reading complete.\n";  // Debug output
}


    // Function to add an entry to the address book
    void addEntry(const extPersonType& person) {
        if (length < maxSize) {
            addressList[length] = person;
            length++;
        } else {
            std::cout << "Address book is full!" << std::endl;
        }
    }

    // Function to find a person by last name
    void findPerson(const std::string& lName) const {
        for (int i = 0; i < length; i++) {
            if (addressList[i].getLastName() == lName) {
                addressList[i].print();
                return;
            }
        }
        std::cout << "Person not found." << std::endl;
    }

    // Function to find birthdays by month
    void findBirthdays(int month) const {
        for (int i = 0; i < length; i++) {
            if (addressList[i].getBirthDate().getMonth() == month) {
                addressList[i].print();
            }
        }
    }

    // Function to find people by relationship
    void findRelations(const std::string& rel) const {
        for (int i = 0; i < length; i++) {
            if (addressList[i].getRelationship() == rel) {
                addressList[i].print();
            }
        }
    }

    // Function to print all entries
    void print() const {
        for (int i = 0; i < length; i++) {
            addressList[i].print();
        }
    }

    // Sort the entries by last name using insertion sort
    void sortEntries() {
        for (int current = 1; current < length; current++) {
            int index = current;
            while (index > 0 && addressList[index].getLastName() < addressList[index - 1].getLastName()) {
                // Swap entries
                extPersonType temp = addressList[index];
                addressList[index] = addressList[index - 1];
                addressList[index - 1] = temp;
                index--;
            }
        }
    }
};
