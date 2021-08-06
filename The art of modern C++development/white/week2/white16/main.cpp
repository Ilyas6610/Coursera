#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    for( const auto& i : m )
        s.insert(i.second);
    return s;
}
