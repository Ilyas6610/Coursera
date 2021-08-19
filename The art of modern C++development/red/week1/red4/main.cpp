#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Deque{
public:
    Deque(){};

    bool Empty() const{
        return (vec_front.empty() && vec_back.empty());
    }

    size_t Size() const{
        return vec_front.size() + vec_back.size();
    }

    T& operator[](size_t index){
        return (index >= vec_front.size()) ? (vec_back[index - vec_front.size()]) : (vec_front[vec_front.size() - index - 1]);
    }

    const T& operator[](size_t index) const{
        return (index >= vec_front.size()) ? (vec_back[index - vec_front.size()]) : (vec_front[vec_front.size() - index - 1]);
    }

    T& At(size_t index){
        if( index >= vec_back.size() + vec_front.size() )
            throw out_of_range("");
        return (index >= vec_front.size()) ? (vec_back.at(index - vec_front.size())) : (vec_front.at(vec_front.size() - index - 1));
    }

    const T& At(size_t index) const{
        if( index >= vec_back.size() + vec_front.size() )
            throw out_of_range("");
        return (index >= vec_front.size()) ? (vec_back.at(index - vec_front.size())) : (vec_front.at(vec_front.size() - index - 1));
    }

    T& Front(){
        return (vec_front.empty()) ? vec_back[0] : vec_front.back();
    }

    const T& Front() const{
        return (vec_front.empty()) ? vec_back[0] : vec_front.back();
    }

    T& Back(){
        return (vec_back.empty()) ? vec_front[0] : vec_back.back();
    }

    const T& Back() const{
        return (vec_back.empty()) ? vec_front[0] : vec_back.back();
    }

    void PushFront(const T& val){
        vec_front.push_back(val);
    }

    void PushBack(const T& val){
        vec_back.push_back(val);
    }


private:
    vector<T> vec_front, vec_back;

};
