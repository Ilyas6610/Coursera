#include "test_runner.h"

#include <cstdint>
#include <iterator>
#include <numeric>
#include <list>
#include <iostream>

using namespace std;

template <typename RandomIt>
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {
    list<typename RandomIt::value_type> pool;
    for( auto it = first; it != last; it++ )
        pool.push_back(move(*it));
    size_t cur_pos = 0;
    auto it = pool.begin();
    auto cur_size = pool.size();
    bool fl = false;
    while (!pool.empty()) {
        //cout << *it << ' ' << cur_pos << endl;
        //for( auto it3 = pool.begin(); it3 != pool.end(); it3++ )
          //  cout << *(it3) << ' ';
        //cout << endl;
        *(first++) = move(*it);
        if(pool.size() == 1)
            break;
        while(true){
            advance(it, 1);
            cur_pos++;
            if(!fl){
                auto it2 = prev(it);
                pool.erase(it2);
                fl = true;
            }
            if( it == pool.end() )
                it = pool.begin();
            if( cur_pos == step_size )
                break;
        }
        cur_pos = 0;
        fl = false;
        //auto it2 = it;
        //if( cur_pos + step_size >= cur_size ){
          //  it = pool.begin();
          //  cur_pos = (cur_pos+step_size)%(pool.size());
          //  advance(it, cur_pos);
          //  cur_size = pool.size();
        //}else{
          //  cur_pos += step_size;
          //  advance(it, step_size);
        //}
        //cout << "ITERATORS VALUES: " << *it << ' ' << *it2 << endl;
        //if( it == it2 ){
            //if(next(it) == pool.end() )
              //  it = pool.begin();
            //else
              //  advance(it, 1);
        //}
        //pool.erase(it2);
    }
}

vector<int> MakeTestVector() {
  vector<int> numbers(10);
  iota(begin(numbers), end(numbers), 0);
  return numbers;
}

void TestIntVector() {
  const vector<int> numbers = MakeTestVector();
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 1);
    ASSERT_EQUAL(numbers_copy, numbers);
  }
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 3);
    ASSERT_EQUAL(numbers_copy, vector<int>({0, 3, 6, 9, 4, 8, 5, 2, 7, 1}));
  }
}

// Это специальный тип, который поможет вам убедиться, что ваша реализация
// функции MakeJosephusPermutation не выполняет копирование объектов.
// Сейчас вы, возможно, не понимаете как он устроен, однако мы расскажем,
// почему он устроен именно так, далее в блоке про move-семантику —
// в видео «Некопируемые типы»

struct NoncopyableInt {
  int value;

  NoncopyableInt(int value) : value(value) {}

  NoncopyableInt(const NoncopyableInt&) = delete;
  NoncopyableInt& operator=(const NoncopyableInt&) = delete;

  NoncopyableInt(NoncopyableInt&&) = default;
  NoncopyableInt& operator=(NoncopyableInt&&) = default;
};

bool operator == (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
  return lhs.value == rhs.value;
}

ostream& operator << (ostream& os, const NoncopyableInt& v) {
  return os << v.value;
}

void TestAvoidsCopying() {
  vector<NoncopyableInt> numbers;
  numbers.push_back({1});
  numbers.push_back({2});
  numbers.push_back({3});
  numbers.push_back({4});
  numbers.push_back({5});

  MakeJosephusPermutation(begin(numbers), end(numbers), 2);

  vector<NoncopyableInt> expected;
  expected.push_back({1});
  expected.push_back({3});
  expected.push_back({5});
  expected.push_back({4});
  expected.push_back({2});

  ASSERT_EQUAL(numbers, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  RUN_TEST(tr, TestAvoidsCopying);
  return 0;
}
