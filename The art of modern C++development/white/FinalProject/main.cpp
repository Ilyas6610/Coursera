#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Date{
public:
    Date(){};
    Date(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }
    int GetYear() const {return year;}
    int GetMonth() const {return month;}
    int GetDay() const {return day;}
private:
    int year = 0;
    int month = 0;
    int day = 0;
};

ostream& operator<<(ostream& ostr, const Date& d){
    ostr << d.GetYear() << '-' << d.GetMonth() << '-'
         << d.GetDay();
    return ostr;
}

bool operator<(const Date& rhs, const Date& lhs){
    return rhs.GetYear()*31*12 + rhs.GetMonth()*rhs.GetDay() < lhs.GetYear()*31*12 + lhs.GetMonth()*lhs.GetDay();
}


class Database {
public:
  void AddEvent(const Date& date, const string& event);
  bool DeleteEvent(const Date& date, const string& event);
  int  DeleteDate(const Date& date);

  void Find(const Date& date) const;

  void Print() const{
    for ( auto const& i : data ){
        for( auto const& j : i.second ){
            cout << setw(4) << setfill('0') << i.first.GetYear() << '-'
                 << setw(2) << setfill('0') << i.first.GetMonth() << '-'
                 << setw(2) << setfill('0') << i.first.GetDay() << ' '
                 << j << endl;
        }
    }
  };

private:
    map<Date, set<string> > data;
};

bool operator==(const Date& rhs, const Date& lhs){
    return (rhs.GetDay() == lhs.GetDay()) && (rhs.GetMonth() == lhs.GetMonth()) && (rhs.GetYear() == lhs.GetYear());
}

void Database::AddEvent(const Date& date, const string& event){
    data[date].insert(event);
}

int Database::DeleteDate(const Date& date){

    int numEvents = data[date].size();
    data.erase(date);
    cout << "Deleted " << numEvents << " events" << endl;
    return numEvents;
}

bool Database::DeleteEvent(const Date& date, const string& event){
    if( data.find(date) != data.end() ){
        if( count(data[date].begin(), data[date].end(), event) != 0 ){
            data[date].erase(event);
            cout << "Deleted successfully" << endl;
            return true;
        }else{
            cout << "Event not found" << endl;
            return false;
        }
    }else{
            cout << "Event not found" << endl;
            return false;
    }
}

void Database::Find(const Date& date) const{
    if( data.find(date) != data.end() )
        for( auto const& it : data.at(date) )
            cout << it << endl;
}

void catchException(istream& istr, const string& date){
    string s = "Wrong date format: " + date;
    if(istr.peek() != '-')
        throw runtime_error(s.c_str());
    else
        istr.ignore(1);
}

void readInt(istream& istr, int& x, const string& date){
    try{
        istr >> x;
        if(istr.fail())
            throw exception();
    }catch(exception& e){
        string s = "Wrong date format: " + date;
        throw runtime_error(s.c_str());
    }
}

istream& operator>>(istream& istr, Date& d){
        string date;
        istr >> date;
        stringstream ss(date.c_str());
        int day, month, year;
        readInt(ss, year, date);
        catchException(ss, date);
        readInt(ss, month, date);
        catchException(ss, date);
        readInt(ss, day, date);
        if( !ss.eof() ){
            string s = "Wrong date format: " + date;
            throw runtime_error(s.c_str());
        }
        d = Date(year, month, day);
        if( month < 1 || month > 12 ){
            string s = "Month value is invalid: " + to_string(month);
            throw runtime_error(s.c_str());
        }
        if( day < 1 || day > 31 ){
            string s = "Day value is invalid: " + to_string(day);
            throw runtime_error(s.c_str());
        }
    return istr;
}


int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        try{
            if(command == "")
                continue;
            stringstream str(command.c_str());
            string action;
            str >> action;
            Date d;
            if( action == "Print" ){
                db.Print();
            }else if( action == "Add" ){
                str >> d;
                string event;
                str >> event;
                db.AddEvent(d, event);
            }else if( action == "Del" ){
                str >> d;
                string event;
                if(!str.eof()){
                    str >> event;
                    db.DeleteEvent(d, event);
                }else{
                    db.DeleteDate(d);
                }
            }else if( action == "Find" ){
                str >> d;
                db.Find(d);
            }else{
                string s = "Unknown command: " + action;
                throw runtime_error(s);
            }
        }catch (exception& e){
            cout << e.what() << endl;
            return 0;
        }
    }

  return 0;
}
