#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    cin >> k;
    if ( k == 0 ){
        cout << 0;
        return 0;
    }
    string s = "";
    while( k > 1 ){
        s += to_string(k%2);
        k /= 2;
    }
    cout << 1;
    for( int i = s.length() - 1; i >= 0; i-- )
        cout << s[i];
    return 0;
}
