#include <iostream>
#include <string>
#include "dateType.h" 

class extPersonType {
private:
    std::string firstName;
    std::string lastName;
    std::string relationship;
    dateType birthDate;

public:
    extPersonType() {}  // Default constructor

    // Parameterized constructor
    extPersonType(std::string fName, std::string lName, std::string rel, dateType bDate)
        : firstName(fName), lastName(lName), relationship(rel), birthDate(bDate) {}

    // Accessor and mutator functions
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getRelationship() const { return relationship; }
    dateType getBirthDate() const { return birthDate; }

    // Print function for extPersonType
    void print() const {
        std::cout << firstName << " " << lastName << " - "  << relationship << " - Birthday: ";
        birthDate.print();
        std::cout << std::endl;
    }
};
