#ifndef DATETYPE_H
#define DATETYPE_H

class dateType {
private:
    int month;
    int day;
    int year;

public:
    // Default constructor
    dateType() : month(1), day(1), year(1900) {}

    // Parameterized constructor
    dateType(int m, int d, int y) : month(m), day(d), year(y) {}

    // Mutator functions
    void setDate(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    // Accessor functions
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Function to print the date
    void print() const {
        std::cout << month << "/" << day << "/" << year;
    }
};

#endif



