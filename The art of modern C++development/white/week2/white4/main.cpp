#include <iostream>

using namespace std;

void UpdateIfGreater(int a, int& b){
    b = (a>b) ? a : b;
}
