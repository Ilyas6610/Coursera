#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v){
    int sz = v.size();
    vector<int> vec;
    for( int i = sz - 1; i >= 0; i-- )
        vec.push_back(v[i]);
    return vec;
}
