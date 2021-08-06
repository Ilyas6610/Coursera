#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s1, s2;
    map<string, set<string> > m;
    for( int i = 0; i < n; i++ ){
        cin >> s1;
        if( s1 == "ADD" ){
            cin >> s1 >> s2;
            m[s1].insert(s2);
            m[s2].insert(s1);
        }else if ( s1 == "COUNT" ){
            cin >> s1;
            cout << m[s1].size() << endl;
        }else if ( s1 == "CHECK" ){
            cin >> s1 >> s2;
            if( m[s1].count(s2) )
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
