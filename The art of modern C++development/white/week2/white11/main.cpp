#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s1, s2;
    map<char, int> w1, w2;
    for( int i = 0; i < n; i++ ){
        cin >> s1 >> s2;
        for (const auto& i: s1)
            w1[i]++;
        for (const auto& i: s2)
            w2[i]++;
        if( w1 == w2 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        w1.clear();
        w2.clear();
    }
    return 0;
}
