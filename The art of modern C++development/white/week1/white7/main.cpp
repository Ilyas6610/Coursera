#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = max(a, b), d = min(a, b);
    while( c%d != 0 ){
        int k = d;
        d = c%d;
        c = k;
    }
    cout << d << endl;
    return 0;
}
