#include "database.h"
#include "date.h"
#include <sstream>
#include <algorithm>

void Database::Add(const Date& date, const string& event){
    auto res = data[date].insert(event);
    if(res.second)
        data_vec[date].push_back(event);
}

int Database::RemoveIf(function<bool(const Date&, const string&)> predicate){
    int res = 0;
    auto it2 = data_vec.begin();
    for( auto it = data.begin(); it != data.end();){
        for( auto i = it->second.begin(); i != it->second.end();){
            if( predicate(it->first, *i) ){
                i = it->second.erase(i);
                res++;
            }else{
                i++;
            }
        }
        if( it->second.empty() ){
            it = data.erase(it);
            it2 = data_vec.erase(it2);
        }
        else{
            auto i2 = stable_partition(it2->second.begin(), it2->second.end(), [predicate, it2](const string& s){return (predicate(it2->first, s));});
            it2->second = vector<string>(i2, it2->second.end());
            it2++;
            it++;
        }
    }

    return res;
}

string Database::Last(const Date& date) const{
    auto it = data_vec.lower_bound(date);
    if( it != data_vec.begin() && it->first != date )
        it = prev(it);
    else if (it->first != date)
        it = data_vec.end();
    if( it == data_vec.end() )
        throw invalid_argument("");
    stringstream ss("");
    ss << it->first << ' ' << it->second.back();
    return  ss.str();
}

vector<string> Database::FindIf(function<bool(const Date&, const string&)> predicate) const{
    vector<string> v;
    for( auto it = data_vec.begin(); it != data_vec.end(); it++ ){
        for( auto i = it->second.begin(); i != it->second.end(); i++ ){
            if( predicate(it->first, *i) ){
                ostringstream ss("");
                ss << it->first << ' ' << *i;
                v.push_back(ss.str());
            }
        }
    }

    return v;

}

void Database::Print(ostream& os) const{
    for ( auto const& i : data_vec ){
        for( auto const& j : i.second ){
            os << i.first << ' ' << j << endl;
        }
    }
};
