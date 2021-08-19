#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector(){
        data = nullptr;
        cur_size = 0;
        capacity = 0;
    }
    explicit SimpleVector(size_t size){
        data = new T[size];
        cur_size = size;
        capacity = size;
    }
    ~SimpleVector(){
        delete[] data;
    };

    T& operator[](size_t index){
        return *(data+index);
    }


    const T& operator[](size_t index) const{
        return *(data+index);
    }

    T* begin(){
        return data;
    }

    T* end(){
        return data + cur_size;
    }

    const T* begin() const{
        return data;
    }

    const T* end() const{
        return data + cur_size;
    }

    size_t Size() const{
        return cur_size;
    }
    size_t Capacity() const{
        return capacity;
    }
    void PushBack(const T& value){
        if( capacity == 0 ){
            data = new T[1];
            data[0] = value;
            cur_size++;
            capacity++;
        }else if( cur_size < capacity ){
            data[cur_size] = value;
            cur_size++;
        }else{
            T* new_data = new T[capacity*2];
            for( int i = 0; i < capacity; i++ )
                new_data[i] = data[i];
            delete[] data;
            data = new_data;
            data[cur_size] = value;
            cur_size++;
            capacity *= 2;
        }
    }

private:
    T* data;
    size_t cur_size;
    size_t capacity;
};
