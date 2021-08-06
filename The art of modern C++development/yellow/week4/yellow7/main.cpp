#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Деление на 2 части
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if( distance(range_begin, range_end) < 2 )
        return;
    vector<typename RandomIt::value_type> v(range_begin, range_end);
    MergeSort(v.begin(), v.begin() + v.size()/2);
    MergeSort(v.begin() + v.size()/2, v.end());
    merge(v.begin(), v.begin() + v.size()/2, v.begin() + v.size()/2, v.end(), range_begin);
}
*/

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if( distance(range_begin, range_end) < 2 )
        return;
    vector<typename RandomIt::value_type> v(range_begin, range_end);
    MergeSort(v.begin(), v.begin() + v.size()/3);
    MergeSort(v.begin() + v.size()/3, v.begin() + 2*v.size()/3);
    MergeSort(v.begin() + 2*v.size()/3, v.end());
    vector<typename RandomIt::value_type> v1;
    merge(v.begin(), v.begin() + v.size()/3, v.begin() + v.size()/3, v.begin() + 2*v.size()/3, back_inserter(v1));
    merge(v1.begin(), v1.end(), v.begin() + 2*v.size()/3, v.end(), range_begin);
}
