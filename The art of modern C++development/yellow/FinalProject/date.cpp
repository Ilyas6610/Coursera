#include "date.h"

using namespace std;

Date::Date(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}

bool operator==(const Date& rhs, const Date& lhs){
    return (rhs.GetDay() == lhs.GetDay()) && (rhs.GetMonth() == lhs.GetMonth()) && (rhs.GetYear() == lhs.GetYear());
}

bool operator<(const Date rhs, const Date lhs){
    return rhs.GetYear()*12*31 + rhs.GetMonth()*31 + rhs.GetDay() < lhs.GetYear()*12*31 + lhs.GetMonth()*31 + lhs.GetDay();
}

bool operator>=(const Date& rhs, const Date& lhs){
    return !(rhs < lhs);
}

bool operator<=(const Date& rhs, const Date& lhs){
    return (rhs < lhs || rhs == lhs);
}

bool operator>(const Date& rhs, const Date& lhs){
    return !(rhs <= lhs);
}

bool operator!=(const Date& rhs, const Date& lhs){
    return !(rhs == lhs);
}


ostream& operator<<(ostream& ostr, const Date& d){
    ostr << setw(4) << setfill('0') << d.GetYear() << '-'
     << setw(2) << setfill('0') << d.GetMonth() << '-'
     << setw(2) << setfill('0') << d.GetDay();
    return ostr;
}

Date ParseDate(istream& istr){
    string date;
    istr >> date;
    stringstream ss(date.c_str());
    int day, month, year;
    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day;
    Date d = Date(year, month, day);
    return d;
}

