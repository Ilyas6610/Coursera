#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

  private:
  int fail_count = 0;
};
/*
void TestConstruct(){
    {
        Rational r1, r2(0,1)
        AssertEqual(r1.Numerator(), r2.Numerator(), "Empty");
        AssertEqual(r1.Denominator(), r2.Denominator(), "Empty");

    }
    AssertEqual(Rational(4,12), Rational(1,3), "Test1");
    AssertEqual(Rational(0,4), Rational(0,1), "Test2");
    AssertEqual(Rational(3,5), Rational(3,5), "Test3");
    AssertEqual(Rational(-1,-1), Rational(1,1), "Test4");
    AssertEqual(Rational(4,-5), Rational(-4,5), "Test5");
}*/

void TestNum(){
    {
        Rational R(4,5);
        AssertEqual(R.Numerator(), 4, "Test1");
    }
    {
        Rational R;
        AssertEqual(R.Numerator(), 0, "Test2");
    }
    {
        Rational R(12, 15);
        AssertEqual(R.Numerator(), 4, "Test3");
    }
    {
        Rational R(0, 4);
        AssertEqual(R.Numerator(), 0, "Test3.1");
    }
    {
        Rational R(1,-5);
        AssertEqual(R.Numerator(), -1, "Test4");
    }
    {
        Rational R(-1, 5);
        AssertEqual(R.Numerator(), -1, "Test5");
    }
    {
        Rational R(-1, -5);
        AssertEqual(R.Numerator(), 1, "Test6");
    }
}

void TestDenom(){
    {
        Rational R(4,5);
        AssertEqual(R.Denominator(), 5, "Test1");
    }
    {
        Rational R;
        AssertEqual(R.Denominator(), 1, "Test2");
    }
    {
        Rational R(12, 15);
        AssertEqual(R.Denominator(), 5, "Test3");
    }
    {
        Rational R(1,-5);
        AssertEqual(R.Denominator(), 5, "Test4");
    }
    {
        Rational R(-1,5);
        AssertEqual(R.Denominator(), 5, "Test5");
    }
    {
        Rational R(-1,-5);
        AssertEqual(R.Denominator(), 5, "Test6");
    }
    {
        Rational R(0,-5);
        AssertEqual(R.Denominator(), 1, "Test6");
    }
}


int main() {
    TestRunner runner;
//    runner.RunTest(TestConstruct, "TestConstruct");
    runner.RunTest(TestNum, "TestNum");
    runner.RunTest(TestDenom, "TestDenom");
    return 0;
}
