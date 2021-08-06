#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

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
    string GetFullNameWithHistory(int year) {
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
    map<int, pair<string, string> > fullnames;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}

