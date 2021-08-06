#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0;
    for( int j = 0; j < s.length(); j++ ){
        if( s[j] == 'f' )
            i++;
        if( i == 2 ){
            cout << j << endl;
            break;
        }
    }
    if( i == 1 )
        cout << -1 << endl;
    else if (i == 0)
        cout << -2 << endl;
    return 0;
}
