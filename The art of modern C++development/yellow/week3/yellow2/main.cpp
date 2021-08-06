#include "phone_number.h"
#include <exception>
#include <sstream>


PhoneNumber::PhoneNumber(const string& international_number){
    stringstream ss(international_number);
    if( ss.peek() != '+' )
        throw invalid_argument("");
    ss.ignore(1);
    getline(ss, country_code_, '-');
    if( ss.eof() )
        throw invalid_argument("");
    getline(ss, city_code_, '-');
    if( ss.eof() )
        throw invalid_argument("");
    getline(ss, local_number_);
    if( country_code_.empty() || city_code_.empty() || local_number_.empty() )
        throw invalid_argument("");
}

string PhoneNumber::GetCountryCode() const{
    return country_code_;
};

string PhoneNumber::GetCityCode() const{
    return city_code_;
};

string PhoneNumber::GetLocalNumber() const{
    return local_number_;
};

string PhoneNumber::GetInternationalNumber() const{
    return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
};
