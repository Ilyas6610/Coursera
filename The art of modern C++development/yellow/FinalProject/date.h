#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Date{
public:
    Date(){};
    Date(int y, int m, int d);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int year = 0;
    int month = 0;
    int day = 0;
};

Date ParseDate(istream& istr);

ostream& operator<<(ostream& ostr, const Date& d);

bool operator==(const Date& rhs, const Date& lhs);

bool operator<(const Date rhs, const Date lhs);

bool operator>=(const Date& rhs, const Date& lhs);

bool operator<=(const Date& rhs, const Date& lhs);

bool operator>(const Date& rhs, const Date& lhs);

bool operator!=(const Date& rhs, const Date& lhs);


