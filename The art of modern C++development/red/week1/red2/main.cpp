#include <iostream>
#include "airline_ticket.h"

using namespace std;

#define UPDATE_FIELD(ticket, field, values){ \
    map<string, string>::const_iterator it; \
    it = values.find(#field); \
    if (it != values.end()) { \
        istringstream is(it->second); \
        is >> ticket.field; \
    } \
}
bool operator<(const Date& rhs, const Date& lhs){
    if( rhs.year != lhs.year )
        return rhs.year < lhs.year;
    else if( lhs.month != rhs.month )
        return rhs.month < lhs.month;
    else
        return rhs.day < lhs.day;
}

bool operator==(const Date& rhs, const Date& lhs){
    return (rhs.year == lhs.year) && (rhs.month == lhs.month) && (rhs.day == lhs.day);
}

ostream& operator<<(ostream& os, const Date& date){
    os << date.year << '-' << date.month << '-' << date.day;
    return os;
}

bool operator<(const Time& rhs, const Time& lhs){
    if( rhs.hours != lhs.hours )
        return rhs.hours < lhs.hours;
    else
        return rhs.minutes < lhs.minutes;
}

bool operator==(const Time& rhs, const Time& lhs){
    return (rhs.hours == lhs.hours) && (rhs.minutes == lhs.minutes);
}

ostream& operator<<(ostream& os, const Time& time){
    os << time.hours << ':' << time.minutes;
    return os;
}

istream& operator>>(istream& is, Date& date){
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return is;
}

istream& operator>>(istream& is, Time& time){
    is >> time.hours;
    is.ignore(1);
    is >> time.minutes;
    return is;
}
