#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& f);

template <typename T> vector<T> Sqr(const vector<T>& v);

template <typename F, typename S> map<F, S> Sqr(const map<F, S>& m);

template <typename T> T Sqr(T x);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& f){
    return make_pair(Sqr(f.first), Sqr(f.second));
}

template <typename T>
vector<T> Sqr(const vector<T>& v){
    vector<T> sq;
    for( const auto& i : v )
        sq.push_back(Sqr(i));
    return sq;
}

template <typename F, typename S>
map<F, S> Sqr(const map<F, S>& m){
    map<F, S> sq;
    for( const auto& i : m )
        sq[i.first] = Sqr(i.second);
    return sq;
}

template <typename T>
T Sqr(T x){
    return x*x;
}
