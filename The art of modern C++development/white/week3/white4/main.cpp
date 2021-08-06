#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        fullnames[year].first = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        fullnames[year].second = last_name;
    }
    string GetFullName(int year) {
        string first_name, second_name;
        for( auto const& i : fullnames ){
            if( i.first <= year ){
                if( !i.second.first.empty() )
                    first_name = i.second.first;
                if( !i.second.second.empty() )
                    second_name = i.second.second;
            }else
                break;
        }
        if( first_name.empty() && second_name.empty() )
            return "Incognito";
        else if( first_name.empty() )
            return second_name + " with unknown first name";
        else if( second_name.empty() )
            return first_name + " with unknown last name";
        else
            return first_name + ' ' + second_name;
    }
private:
    map<int, pair<string, string> > fullnames;
};
