#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate(){
    T* x;
    if( dq.empty() ){
        x = new T;
        s.insert(x);
    }else{
        x = dq.front();
        dq.pop();
        s.insert(x);
    }
    return x;
  };
  T* TryAllocate(){
    if( dq.empty() )
        return nullptr;
    s.insert(dq.front());
    T* x = dq.front();
    dq.pop();
    return x;
  };

  void Deallocate(T* object){
    if( s.find(object) == s.end() )
        throw invalid_argument("");
    s.erase(object);
    dq.push(object);
  };

  ~ObjectPool(){
    while(!dq.empty()){
        delete dq.front();
        dq.pop();
    }
    for( auto& i : s )
        delete i;
  };

private:
    set<T*> s;
  queue<T*> dq;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
