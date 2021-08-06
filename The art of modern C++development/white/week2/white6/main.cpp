#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v){
    int sz = v.size();
    for( int i = 0; i < sz/2; i++ )
        swap(v[i], v[sz - 1 - i]);
}
