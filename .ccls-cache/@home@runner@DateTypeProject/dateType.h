#include <iostream>

class dateType {
private:
    int month; // Month (1-12)
    int day;   // Day (1-31 depending on month)
    int year;  // Year (>= 1900)

public:
    // Constructor with date validation
    dateType(int m = 1, int d = 1, int y = 1900) {
        setDate(m, d, y);
    }

    // Function to set the date with validation
    void setDate(int m, int d, int y) {
        if (y < 1900) {
            year = 1900; // Default value for year
            std::cout << "Invalid year. Setting to default: " << year << std::endl;
        } else {
            year = y;
        }

        if (m < 1 || m > 12) {
            month = 1; // Default value for month
            std::cout << "Invalid month. Setting to default: " << month << std::endl;
        } else {
            month = m;
        }

        // Validate day based on month and year
        int maxDays = getDaysInMonth(month, year);
        if (d < 1 || d > maxDays) {
            day = 1; // Default value for day
            std::cout << "Invalid day. Setting to default: " << day << std::endl;
        } else {
            day = d;
        }
    }

    // Function to check if a year is a leap year
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    // Function to get the number of days in a month
    int getDaysInMonth(int m, int y) const {
        if (m == 2) { // February
            return isLeapYear(y) ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) { // April, June, September, November
            return 30;
        } else { // January, March, May, July, August, October, December
            return 31;
        }
    }

    // Function to print the date
    void print() const {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }
};


