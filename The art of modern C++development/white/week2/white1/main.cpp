#include <iostream>

using namespace std;

int Factorial(int x){
    if( x < 0 )
        return 1;
    int z = 1;
    for (int i = 2; i <= x; i++)
        z *= i;
    return z;
}
