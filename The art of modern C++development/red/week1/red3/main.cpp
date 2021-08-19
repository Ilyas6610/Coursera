#include <iostream>
#include "test_runner.h"

using namespace std;

#define PRINT_VALUES(out, x, y) do {out << (x) << endl; out << (y) << endl;} while(0)

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    int x = 5;
    if( x == 5 )
        PRINT_VALUES(output, x, x++);
    else{
        x=6;
    }
     ASSERT_EQUAL(output.str(), "5\n6\n");
  }, "PRINT_VALUES usage example");
  return 0;
}
