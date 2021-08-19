#include <iostream>
#include "airline_ticket.h"

#define SORT_BY(field) [](const AirlineTicket& lhs, const AirlineTicket& rhs) { return lhs.field < rhs.field; }

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
