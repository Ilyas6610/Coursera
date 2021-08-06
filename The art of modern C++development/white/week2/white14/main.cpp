#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n, x, p = 1;
    cin >> n;
    string s;
    map< int, vector<string> > m;
    for( int i = 0; i < n; i++ ){
        cin >> x;
        vector<string> vec;
        for( int j = 0; j < x; j++ ){
            cin >> s;
            vec.push_back(s);
        }
        bool fl = 0;
        int k;
        for( const auto& i : m )
            if( i.second == vec ){
                fl = 1;
                k = i.first;
            }
        if( !fl ){
            m[p] = vec;
            cout << "New bus " << p++ << endl;
        }else
            cout << "Already exists for " << k << endl;
    }
    return 0;
}
