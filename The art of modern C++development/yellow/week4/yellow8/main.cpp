#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){
    pair<RandomIt, RandomIt> p;
    string s = "";
    s+=prefix;
    p.second = upper_bound(range_begin, range_end, s, [](const string& a, const string& b){return a[0] < b[0];});
    p.first = lower_bound(range_begin, range_end, s, [](const string& a, const string& b){return a[0] < b[0];});
    return p;
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end,
                                        const string& prefix){
    pair<RandomIt, RandomIt> p;
    p.second = upper_bound(range_begin, range_end, prefix,
                           [prefix](const string& a, const string& b)
                           {return string(a.begin(), a.begin() + min(min(prefix.size(), a.size()), b.size()))
                                    < string(b.begin(), b.begin() + min(min(prefix.size(), a.size()), b.size()));

                           });
    p.first = lower_bound(range_begin, range_end, prefix,
                            [prefix](const string& a, const string& b)
                           {return string(a.begin(), a.begin() + min(prefix.size(), a.size()))
                                    < string(b.begin(), b.begin() + min(prefix.size(), b.size()));

                           });


    return p;
}
