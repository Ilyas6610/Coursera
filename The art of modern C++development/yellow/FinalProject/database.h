#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <deque>
#include <functional>
#include "node.h"

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    string Last(const Date& date) const;
    int  RemoveIf(function<bool(const Date&, const string&)> predicate);

    vector<string> FindIf(function<bool(const Date&, const string&)> predicate) const;

    void Print(ostream& os) const;

private:
    map<Date, vector<string> > data_vec;
    map<Date, set<string> > data;
};
