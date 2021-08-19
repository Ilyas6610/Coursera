#include "test_runner.h"

#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

template <typename Iterator>
class  IteratorRange{
public:
    IteratorRange(Iterator f, Iterator l):
        first(f),
        last(l)
    {};

    Iterator begin(){
        return first;
    }

    Iterator end() const{
        return last;
    }

    Iterator begin() const{
        return first;
    }

    Iterator end(){
        return last;
    }


    size_t size() const{
        return distance(first, last);
    }

private:
    Iterator first, last;
};

template <typename Iterator>
class Paginator {
public:
    Paginator(Iterator beg, Iterator ed, size_t page_size){
        while( true ){
            if(beg == ed)
                break;
            if( distance(beg, ed) >= page_size ){
                pages.push_back(IteratorRange<Iterator>(beg, next(beg, page_size)));
                advance(beg, page_size);
            }else{
                pages.push_back(IteratorRange<Iterator>(beg, ed));
                break;
            }
        }
    }

    size_t size() const{
        return pages.size();
    }

    auto begin(){
        return pages.begin();
    }

    auto begin() const{
        return pages.begin();
    }

    auto end(){
        return pages.end();
    }

    auto end() const{
        return pages.end();
    }

private:
    vector<IteratorRange<Iterator>> pages;
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(c.begin(), c.end(), page_size);
}

