#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    Person( const string& first_name, const string& second_name, const int year ){
        fullnames[year] = make_pair(first_name, second_name);
        y = year;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if( year < y )
            return;
        fullnames[year].first = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if( year < y )
            return;
        fullnames[year].second = last_name;
    }
    string GetFullName(int year) const{
        if( year < y )
            return "No person";
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
    string GetFullNameWithHistory(int year) const{
        if( year < y )
            return "No person";
        vector<string> first_name, second_name;
        for( auto const& i : fullnames ){
            if( i.first <= year ){
                if( !i.second.first.empty()){
                    if( (!first_name.empty() && first_name[first_name.size() - 1] != i.second.first ) || (first_name.empty()))
                        first_name.push_back(i.second.first);
                }
                if( !i.second.second.empty() )
                    if( ( !second_name.empty() && second_name[second_name.size() - 1] != i.second.second ) || (second_name.empty()))
                     second_name.push_back(i.second.second);
            }else
                break;
        }
        reverse(first_name.begin(), first_name.end());
        reverse(second_name.begin(), second_name.end());
        string res = "";
        if( !first_name.size() && ! second_name.size() )
            return "Incognito";
        else if( !first_name.size() ){
            res = (second_name.size() != 1) ? (res + second_name[0] + " (") : (res + second_name[0] + " with unknown first name" );
            for( int i = 1; i < second_name.size(); i++ )
                res = (i != second_name.size() - 1) ? (res + second_name[i] + ", ") : (res + second_name[i] + ") with unknown first name" );
        }else if( !second_name.size() ){
            res = (first_name.size() != 1) ? (res + first_name[0] + " (") : (res + first_name[0] + " with unknown last name" );
            for( int i = 1; i < first_name.size(); i++ )
                res = (i != first_name.size() - 1) ? (res + first_name[i] + ", ") : (res + first_name[i] + ") with unknown last name" );
        }else{
            res = (first_name.size() != 1) ? (res + first_name[0] + " (") : (res + first_name[0] + " ");
            for( int i = 1; i < first_name.size(); i++ )
                res = (i != first_name.size() - 1) ? (res + first_name[i] + ", ") : (res + first_name[i] + ") " );
            res = (second_name.size() != 1) ? (res + second_name[0] + " (") : (res + second_name[0]);
            for( int i = 1; i < second_name.size(); i++ )
                res = (i != second_name.size() - 1) ? (res + second_name[i] + ", ") : (res + second_name[i] + ")" );
        }
        return res;
    }
private:
    int y;
    map<int, pair<string, string> > fullnames;
};
