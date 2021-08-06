#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s){
    auto it = s.begin();
    vector<string> v;
    while( it != s.end() ){
        auto new_it = find(it, s.end(), ' ');
        v.push_back(string(it, new_it));
        it = (new_it == s.end()) ? new_it : ++new_it;
    }
    return v;
}

