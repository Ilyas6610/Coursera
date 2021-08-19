#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if( distance(range_begin, range_end) < 2 )
        return;
    vector<typename RandomIt::value_type> v(make_move_iterator(range_begin), make_move_iterator(range_end));
    MergeSort(v.begin(), v.begin() + v.size()/3);
    MergeSort(v.begin() + v.size()/3, v.begin() + 2*v.size()/3);
    MergeSort(v.begin() + 2*v.size()/3, v.end());
    vector<typename RandomIt::value_type> v1;
    merge(make_move_iterator(v.begin()), make_move_iterator(v.begin()) + v.size()/3, make_move_iterator(v.begin()) + v.size()/3, make_move_iterator(v.begin()) + 2*v.size()/3, back_inserter(v1));
    merge(make_move_iterator(v1.begin()), make_move_iterator(v1.end()), make_move_iterator(v.begin()) + 2*v.size()/3, make_move_iterator(v.end()), range_begin);
}
