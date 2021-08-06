#include <iostream>
#include <map>

using namespace std;

template <typename First, typename Second>
Second& GetRefStrict(map<First, Second>& m, First key){
    if( m.find(key) == m.end() )
        throw runtime_error("");
    else
        return m.at(key);
}
