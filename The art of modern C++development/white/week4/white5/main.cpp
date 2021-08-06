#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");
    double x;
    cout << fixed << setprecision(3);
    while(input >> x){
        cout << x << endl;
    }
    return 0;
}
