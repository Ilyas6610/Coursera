#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n, x, cnt = 1, fl = 0;
    map<int, set<string> > m;
    string s;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> x;
        set<string> st;
        for( int j = 0; j < x; j++ ){
            cin >> s;
            st.insert(s);
        }
        for( const auto& i : m ){
            if ( i.second == st )
                fl = i.first;
        }
        if (fl)
            cout << "Already exists for " << fl << endl;
        else{
            m[cnt] = st;
            cout << "New bus " << cnt << endl;
            cnt++;
        }
        fl = 0;

    }
    return 0;
}
