#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool operator<(const Region& lhs, const Region& rhs){
    return tie(lhs.names, lhs.parent_std_name, lhs.population, lhs.std_name) <
            tie(rhs.names, rhs.parent_std_name, rhs.population, rhs.std_name);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
    int mx = 0;
    map<Region, int> m;
    for( auto const& i: regions )
        mx = max(mx, ++m[i]);
    return mx;
}
